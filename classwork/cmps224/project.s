
# Bethany Armitage
# 
# This program will eventually display a portion of pascal's triangle
#
#
#  progress:
# >>>>>compute n! and k!                                 (80  percent)
#
#      compute_nchoosek:(Iterative algorithm)            (85  percent)
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
.ent main
main:
    
    move $s0, $a0               # save argc
    move $s1, $a1               # save argv

    li   $t0, 3                 # value to compare  cmd args

    # defaut values supplied if insufficient cmd args supplied
    blt  $s0, $t0, default
    b argv_values

default:
    li   $v0, 6                # default values if no args supplied
    li   $v1, 4 
    b print_result

argv_values:
    lw   $a0, 4($s1)            # set $a0 = argv[1]
    lw   $a1, 8($s1)            # set $a1 = argv[2]

    jal  atoi                   # parse first arg(n) and save
    move $s2, $v0

    move $a0, $a1               # move second arg into parameter reg
    jal  atoi
    move $s3, $v0

    move $a0, $s2               # prepare to swap
    move $a1, $s3
    blt  $s2, $s3, swap         # set $t0 to 1 if n < k

    move $v0, $s2               # retain values if not swapped
    move $v1, $s3

    move $t1, $zero             # zero out $t1 to use for printing
                                # to avoid infinite loop and reuse
                                # print branch as needed
    b print_result

swap:
    move $v0, $a1
    move $v1, $a0

print_result: 
    move $a0, $v0               # display first argument
    li   $v0, 1
    syscall
    
    li   $a0, 32                # print a space (32=ascii space)
    li   $v0, 11
    syscall

    move $a0, $v1               # display second argument
    li   $v0, 1
    syscall

    lb   $a0, lf                # print linefeed
    li   $v0, 11
    syscall

    bnez $t1, compute_nchoosek

call_fac: 

    move $a0, $s2               # set parameters for factorial call
    jal fac                     # call fac function
    move $s4, $v0               # save result 

    move $a0, $s3 
    jal fac                     # call fac function
    move $s5, $v0

    li $t1, 1                   # change $t1 to avoid infinite loop
    b print_result

compute_nchoosek:

    li   $v0, 10                # exit program
    syscall 
   
.end main

.ent fac
fac:
#   this c factorial function will be implemented in MIPS for each
#   commandline agrument.
#
#   int fac(n){
#       int product =1;
#       for (int i=1, i<=n, i++)
#           product = product * i
#       return product;
#   }

# $t0 counter
# $t1 product
# $t2 argument/stopping condition

    li      $t0, 1
    li      $t1, 1
    move    $t2, $a0
loop:
    beqz    $t1, exit_loop
    mul     $t1, $t1, $t0
    addi    $t0, $t0, 1
    b loop

exit_loop:
    move    $v0, $t1
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
    lf:      .byte 10
    err_msg: .asciiz "Insufficient arguments given..."
    use_msg: .asciiz "Usage: spim -f project.s <int>n <int>k where n is row and k is column"
