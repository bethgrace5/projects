
#!!!!!!!!!!!! working version
# Bethany Armitage
# 
# This program will eventually display a portion of pascal's triangle
#
#
#  progress:
#      compute n! and k!                                 (80  percent)
#
#      compute_nchoosek:(Iterative algorithm)            (85  percent)
#
#      display row n of pascal's triangle for k=0 to n:  (90  percent)
# 
#      display the entirety of Pascal's triangle         (95  percent)
#
#      change compute_nchoosek to Recursive algorithm:   (100 percent)
#  >>> complete!
# Register Usage:
#    main:
#       $a registers used for arguments
#       $v registers used for return values
#       $s0 arg count
#       $s1 pointer to arg vector
#       $s2 stores n
#       $s3 stores k

.text
.ent main
.globl main
main:
    
    move $s0, $a0               # save argc
    move $s1, $a1               # save argv

    li   $t0, 3                 # value to compare number of cmd args

    # defaut values supplied if insufficient cmd args supplied
default:
    beq  $s0, $t0, argv_values
    li   $s2, 6                # default values if no args supplied
    li   $s3, 4 
    b print_result

argv_values:
    lw   $s2, 4($s1)            # set $a0 = argv[1]
    lw   $s3, 8($s1)            # set $a1 = argv[2]

    move $a0, $s2
    jal  atoi                   # parse first arg(n) and save
    move $s2, $v0

    move $a0, $s3               # move second arg into parameter reg
    jal  atoi
    move $s3, $v0

    blt  $s2, $s3, swap         # set $t0 to 1 if n < k

    b    print_result

swap:
    move $t0, $s2
    move $s2, $s3
    move $s3, $t0

print_result: 

    sw   $s2, ($sp)             # store n for safe keeping

    move $a0, $s2               # print first argument
    li   $v0, 1
    syscall
    
    li   $a0, 32                # print a space (32=ascii space)
    li   $v0, 11
    syscall

    move $a0, $s3               # print second argument
    li   $v0, 1
    syscall

    lb   $a0, lf                # print newline
    li   $v0, 11
    syscall

    move $a0, $s2               
    jal fac                     # call fac function for n
    move $a0, $v0               # print result fac(n)
    li   $v0, 1
    syscall

    li   $a0, 32                # print a space (32 = ascii space)
    li   $v0, 11
    syscall
    
    move $a0, $s3
    jal fac                     # call fac function for k
    move $a0, $v0               # print result fac(k)
    li   $v0, 1
    syscall

    lb   $a0, lf                # print a newline
    li   $v0, 11
    syscall

    move $a0, $s2               # send n to function
    move $a1, $s3               # send k to function
    jal compute_nchoosek

    move $a0, $v0               # print result nchoosek
    li $v0, 1
    syscall

    lb   $a0, lf                # print a newline
    li   $v0, 11
    syscall

    move $a0, $s2               # print row n of pascal's triangle
    jal print_row

    lw $a0 ($sp)                # pull n from stack
    jal display_triangle        # print entire triangle up to rown n

    li $v0, 10                  # exit program
    syscall
.end main

.ent display_triangle
display_triangle:
    addi $sp, $sp, -32
    sw   $ra, 20($sp)
    sw   $fp, 16($sp)
    addi $fp, $sp, 28

    sw   $a0, ($sp)             # save n
    li   $t1, 0
    sw   $t1, 4($sp)            # save counter

loop_display_triangle:

    lw   $t0, ($sp)             # $t0 n
    lw   $t1, 4($sp)            # $t1 counter
    
    blt $t0, $t1,  exit_display_triangle

    move $a0, $t1
    jal print_row


    lw   $t1, 4($sp)
    addi $t1, $t1, 1
    sw   $t1, 4($sp)


    b loop_display_triangle

exit_display_triangle:


    lw   $ra, 20($sp)
    lw   $fp, 16($sp)
    addi $sp, $sp, 32

    jr   $ra

.end display_triangle
.ent print_row

print_row:

    addi $sp, $sp, -32
    sw   $ra, 20($sp)
    sw   $fp, 16($sp)
    addi $fp, $sp, 28

    move $t0, $a0               # $t0 = n
    move $t1, $zero             # $t1 = k

    sw   $t0, ($sp)
    sw   $t1, 4($sp)
count:

    lw   $t0, ($sp)
    lw   $t1, 4($sp)

    bgt  $t1, $t0, exit_print_row

    move $a0, $t0 
    move $a1, $t1
    jal compute_nchoosek

    move $a0, $v0               # print number
    li   $v0, 1
    syscall

    li   $a0, 32                # print a space
    li   $v0, 11
    syscall

    lw   $t1, 4($sp)
    addi $t1, $t1, 1
    sw   $t1, 4($sp)
    b count

exit_print_row:

    la   $a0, lf                # print line feed
    li   $v0, 4
    syscall

    lw   $ra, 20($sp)
    lw   $fp, 16($sp)
    addi $sp, $sp, 32

    jr   $ra

.end print_row
    
.ent compute_nchoosek
.globl compute_nchoosek
compute_nchoosek:
# int C(n, k){
#    if (k==0) return 1;
#    if (k==1) return n;
#    if (k==n) return 1;
#    return C(n-1, k) + C(n-1, k-1);
#}
# $a0 = n
# $a1 = k
# $v0 = c(n,k)


    addi $sp, $sp, -32          # set up stack frame
    sw   $ra, 20($sp)
    sw   $fp, 16($sp)           # set up frame pointer
    addi $fp, $sp, 28

    sw   $a0, ($sp)             # save n
    sw   $a1, 4($sp)            # save k

    li   $t0, 1
    li   $v0, 1
    beq  $a1, $zero, exit_nchoosek  # if k==0, return 1
    beq  $a1, $a0,   exit_nchoosek  # if k==n, return 1
    move $v0, $a0
    beq  $a1, $t0,   exit_nchoosek    # if k==1, return n

    lw   $a0, ($sp)             # save (n-1)
    lw   $a1, 4($sp)            # save k

    sw   $a0, ($sp)             # save (n-1)
    sw   $a1, 4($sp)            # save k
    addi $a0, $a0, -1


    jal compute_nchoosek        # compute C(n-1, k)

    sw   $v0,  8($sp) 

    lw   $a0, ($sp)
    lw   $a1, 4($sp)
    sub  $a0, $a0, 1
    sub  $a1, $a1, 1

    sw   $a0, ($sp)             # save (n-1)
    sw   $a1, 4($sp)            # save (k-1)
    jal compute_nchoosek        # compute C(n-1, k-1)

    # return c(n-1, k) + c(n-1, k-1);
    lw   $t0,  8($sp) 
    add  $v0, $v0, $t0


    exit_nchoosek:
    lw   $ra, 20($sp)
    addi $sp, $sp, 32
    jr   $ra

.ent fac
fac:
# computes factorial of argument sent
# $t0 counter
# $t1 accumulated product
# $t2 argument/stopping condition

    li      $t0, 1
    li      $t1, 1
    move    $t2, $a0
loop:
    beqz    $t2, exit_loop
    mul     $t0, $t0, $t1
    addi    $t2, $t2, -1
    addi    $t1, $t1, 1
    b loop

exit_loop:
    move    $v0, $t0
    jr      $ra                         # return

.end fac


# atoi function provided by instructor
.ent atoi
atoi:
    move $v0, $zero

    # detect sign
    li   $t0, 1
    lbu  $t1, 0($a0)
    bne  $t1, 45, digit
    li   $t0, -1
    addu $a0, $a0, 1

digit:
    # read character
    lbu $t1, 0($a0)

    #finish when non-digit encountered
    bltu $t1, 48, finish
    bgtu $t1, 57, finish

    #translate character into digit
    subu $t1, $t1, 48

    #multiply the accumulator by ten
    li   $t2, 10
    mult $v0, $t2
    mflo $v0

    # add digit to the accumulator
    add  $v0, $v0, $t1

    # next character
    addu $a0, $a0, 1
    b    digit

finish:
    mult $v0, $t0
    mflo $v0
    jr   $ra
.end atoi


.data
    lf:      .asciiz "\n" 

