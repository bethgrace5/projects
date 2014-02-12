
# Bethany Armitage
# 
# This program displays a portion of pascal's triangle
# currently at  75%
#
# Register Usage:
#    main:
#       $a registers used for arguments
#       $v registers used for return values
#       $s0 arg count
#       $s1 pointer to arg vector
#       $s2 stores n
#       $s3 stores k
#

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

    
    li   $v0, 10                # exit program
    syscall 
   
    jr $ra
    
.end main



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

