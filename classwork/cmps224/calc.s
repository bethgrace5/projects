# filename: calc.s

# description: cs 224 lab 06 
# sime calculator to accept two operands. 
# usage:  addition:         spim -f calc.s 2 + 5
#         subtraction:      spim -f calc.s 2 - 5
#         multiplication:   spim -f calc.s 2 \* 5

.text
.globl main 
.ent  main

main:

    move $s0, $a0       # save commandline arg count
    move $s1, $a1       # save commandline vector

    lw $s2, 4($s1)      # load first commandline arg
    move $a0, $s2       # convert string to integer
    jal atoi
    move $s2, $v0
  
    lw $s3, 8($s1)      # store operand supplied (2nd cmd arg)
    lb $s3, ($s3)       # save only single char byte, not '\0' 

#   move $a0, $s3       # print int value of second arg
#   li $v0, 1           # (error testing purposes)
#   syscall

    lw $s4, 12($s1)     # load third commandline arg
    move $a0, $s4       # convert string to integer
    jal atoi
    move $s4, $v0

    move $a0, $s2       # set first cmd arg as parameter one
    move $a1, $s4       # set second cmd arg as parameter two

    # compare operand with ascii equivalent
    li $s5, 42          # 42 = '*'
    li $s6, 43          # 43 = '+'
    li $s7, 45          # 45 = '-'

    beq $s3, $s5, multiplyit      # test ascii equivalent of operand
    beq $s3, $s6, addit           # branch to appropriate operation
    beq $s3, $s7, subtractit

    # if the operand is not '+', '-', or '*' exit
    # TODO: print error or usage message upon incorrect operand
    
    li $a0, 10          # 10=ascii linefeed
    li $v0, 11          # print character linefeed

    li $v0, 10          # system call to exit
    syscall

multiplyit:
    # multiply the arguments and branch to exit
    # move result to $v0 
    mul $v0, $a0, $a1
    b exit
addit:
    # add the arguments and branch to exit
    # move result to $v0
    add $v0, $a0, $a1
    b exit
subtractit:
    # subtract the arguments and branch to exit
    # move result to $v0
    sub $v0, $a0, $a1

# print result and exit program 
exit: 
    move $a0,$v0        # move the result into first parameter
    li $v0, 1           # setup syscall 1 (print_int)
    syscall             # make the call to display the integer 
     
    li $v0, 4           # print newline
    la $a0, newline  
    syscall          

    li $v0, 10          # system call to exit
    syscall

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
    
    # finish when non-digit encountered
    bltu $t1, 48, finish
    bgtu $t1, 57, finish
     
    # translate character into digit
    subu $t1, $t1, 48
     
    # multiply the accumulator by ten
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

    newline: .asciiz "\n"
