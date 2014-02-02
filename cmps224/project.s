
# Bethany Armitage
# 
# This program displays a portion of pascal's triangle
# currently at < 70%
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

    li $t0, 3
    blt $s0, $t0, arg_error     # check for two cmd line args
    
    lw $a0, 4($s1)              # parse first arg(n) and save
    jal atoi
    move $s2, $v0

    lw $a0, 8($s1)              # parse second arg(k) and save
    jal atoi
    move $s3, $v0

# utilize stl (set if less than)
    move $a0, $s2               # prepare to swap
    move $a1, $s3

    move $v0, $s2               # set return registers if no swap
    move $v1, $s3
    blt $s2, $s3, swap          # swap if n<k
    
    move $s2, $v0               # n and k are now in order
    move $s3, $v1

    move $a0, $s2               # display first argument
    li $v0, 1
    syscall
    
    li $a0, 32                  # print a space (32=ascii space)
    li $v0, 11
    syscall

    move $a0, $s3               # display second argument
    li $v0, 1
    syscall

    jal print_linefeed
    
   
    


    


.end main

.ent arg_error
    la $a0, err_ms             # print error messageg
    li $v0, 4     
    syscall

    jal print_linefeed
    `
    la $a0, use_msg            # print usage instructions
    li $v0, 4
    syscall

    jal print_linefeed

    li $v0, 10                 # exit program
    syscall

.end arg_error

.ent print_linefeed

    print_linefeed:
    lb $a0, lf
    li $v0, 11
    syscall

.end print_linefeed

.ent swap
    swap:
        move $v0, $a1
        move $v1, $a0
.end swap
    
.ent atoi
    atoi:
        move $v0, $zero

        # detect sign
        li $t0, 1
        lbu $t1, 0($a0)
        bne $t1, 45, digit
        li $t0, -1
        addu $a0, $a0, 1

    digit:
        # read character
        lbu $t1, 0($a0)

        finish when non-digit encountered
        bltu $t1, 48, finish
        bgtu $t1, 57, finish

        #translate character into digit
        subu $t1, $t1, 48

        #multiply the accumulator by ten
        li $t2, 10
        mult $v0, $t2
        mflo $v0

        # add digit to the accumulator
        add $v0, $v0, $t1

        # next character
        addu $a0, $a0, 1
        b digit

    finish:
        mult $v0, $t0
        mflo $v0
        jr $ra
.end atoi


.data
    lf:      .byte 10
    err_msg: .asciiz "Insufficient arguments given..."
    use_msg: .asciiz "Usage: spim -f project.s <int>n <int>k where n is row and k is column"
