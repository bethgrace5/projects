
# Bethany Armitage
# 
# This program will eventually display a portion of pascal's triangle
#
#
#  progress:
#      compute n! and k!                                 (80  percent)
#
# >>>> compute_nchoosek:(Iterative algorithm)            (85  percent)
#
#      display row n of pascal's triangle for k=0 to n:  (90  percent)
# 
#      display the entirety of Pascal's triangle         (95  percent)
#
#      change compute_nchoosek to Recursive algorithm:   (100 percent)
#
# Register Usage:
#    main:
#       $a registers used for arguments
#       $v registers used for return values
#       $s0 arg count
#       $s1 pointer to arg vector
#       $s2 stores n
#       $s3 stores k
#       $s4 stores n!
#       $s5 stores k!

.text
main:
    # construct stack frame to save return address
    addi $sp, $sp, -44
    sw   $ra, 32($sp)
    sw   $fp, 36($sp)
    addi $fp, $sp, 40
    
    move $s0, $a0               # save argc
    move $s1, $a1               # save argv

    li   $t0, 3                 # value to compare  cmd args

# if no command arguments supplied, use default values

    beq  $s0, $t0, argv_values
    li   $s2, 6               
    li   $s3, 4 
    b    continue

# else, use commandline agruments given
argv_values:

    lw   $s2, 4($s1)            # set $s2 = argv[1]
    lw   $s3, 8($s1)            # set $s3 = argv[2]

    move $a0, $s2
    jal  atoi                   # parse first  argument and save
    move $s2, $v0

    move $a0, $s3               # parse second argument and save
    jal  atoi
    move $s3, $v0


    blt  $s2, $s3, swap         # if n < k swap values
    b    continue               # else continue 

swap:
    move $t0, $s2
    move $s2, $s3
    move $s3, $t0

continue:

    move $a0, $s2               # display two numbers
    move $a1, $s3               # (n and k)
    li   $a2, 2
    jal  print_result

    move $a0, $s2               # compute c(n,k) with n and k
    move $a1, $s3
    jal compute_nchoosek
    move $s6, $v0


#TODO print fac results in fac function by calling print result
#TODO print nchoosek result in function by calling print result

    lw   $ra, 32($sp)

    li   $v0, 10                # exit program
    syscall 
   
##########################################################################
#functions put in this section

fac:
#   this c factorial function will be implemented in MIPS for each
#   commandline agrument.
#
# $t0 counter
# $t1 product
# $t2 argument/stopping condition

    # construct stack frame to save return address
    addi $sp, $sp, -32
    sw   $ra, 20($sp)
    sw   $fp, 16($sp)
    addi $fp, $sp, 28

    li      $t0, 1
    li      $t1, 1
    move    $t2, $a0

fac_loop:
    beqz    $t2, exit_loop
    mul     $t0, $t0, $t1
    addi    $t2, $t2, -1
    addi    $t1, $t1, 1
    b fac_loop

exit_loop:
    move    $v0, $t0                    # put return value in $v0

    move    $a0, $t0                    # print result (one argument)
    li      $a2, 1
    jal     print_result

    lw   $ra, 20($sp)           # restore return adddress
    lw   $fp, 16($sp)
    addi $sp, $sp, 28           # pop stack frame

    jr      $ra                         # return

.end fac

.ent compute_nchoosek
compute_nchoosek:
    # iterative version
    # c(n, k) =   n!/((n-k)!*k!)
    # $a0 = n
    # $a1 = k
    #
    # $t0 = n!
    # $t1 = k!
    # $t3 = (n-k)!
    # $t5 = (n-k)!*k! (denominator) 
    # $t6 = c(n,k)

# TODO: construct stack frame to save reutrn address and values

    # construct stack frame to save return address
    addi $sp, $sp, -44
    sw   $ra, 44($sp)
    sw   $fp, 40($sp)
    addi $fp, $sp, 40

    sub  $t3, $a0, $a1          # $t3 = n-k

    sw   $a0, 0($sp)            # save n
    sw   $a1, 4($sp)            # save k
    sw   $t3, 8($sp)            # save n - k

    # n is already in $a0
    jal  fac                    # compute n!
    sw   $v0, 12($sp)           # save n!

    lw   $a0, 4($sp)            # load k
    jal  fac                    
    sw   $v0, 16($sp)           # save k!
        
    lw   $a0, 8($sp)            # load n - k
    jal  fac

    move $t3, $v0               # put (n - k)! into $t3 
    lw   $t1, 16($sp)           # load k! into $t1
    mul  $t5, $t3, $t1          # compute denominator (n-k)!*k!

    lw   $t0, 12($sp)           # load n!
    div  $t0, $t5               # n!/((n-k)! * k!)
    mfhi $t6                    # $s6 = c(n,k)


    move $a0, $t6               # print result with single argument
    li   $a2, 1
    jal print_result


    lw   $ra, 44($sp)           # restore return adddress
    lw   $fp, 40($sp)
    addi $sp, $sp, 44           # pop stack frame

    jr  $ra

.end compute_nchoosek


.ent print_result
print_result: 
# $a0, first argument to print
# $a1, second argument to print
# $a2, number of arguments to print
# (can be expanded to print more arguments)
# (currently prints 1 or 2, each followed by a linefeed)
    sw   $ra, ($sp)
   
    li   $v0, 1                       # display first argument
    syscall

    la   $a0, space                 # display space
    li   $v0, 4
    syscall

    beq  $a2, 1, no_more_to_print

    move $a0, $a1                   # display second argument
    li   $v0, 1
    syscall

    la   $a0, space                 # display space
    li   $v0, 4
    syscall

    no_more_to_print:
    
    la   $a0, lf                    # print newline
    li   $v0, 4
    syscall

    lw $ra, ($sp)

    jr  $ra                     # return
    
.end print_result

    

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
    space:   .asciiz " "
    lf:      .asciiz "\n"

