# filename: calc.s

# description: cs 224 lab 06 

# prompt the user to enter two integers, sum integers and display the result

.text
.globl read 
.globl main 
.ent  main

main:

    la $s0, $a0         # save commandline arg count
    la $s1, $a1         # save commandline vector

    sw $s2, 4($s1)      # store first commandline arg
    move $a0, $s2       #convert string to integer
    jal atoi
    move $s2, $v0
  
    sw $s3, 8($s1)      # store operand supplied (2nd cmd arg)

    sw $s4, 12($s1)     # store third commandline arg
    move $a0, $s4       #convert string to integer
    jal atoi
    move $s4, $v0

    # compare operand with ascii equivalent
    li $s5, 42          # 42 = '*'
    li $s6, 43          # 43 = '+'
    li $s7, 45          # 45 = '-'
 

    move $a0, $s2
    move $a1, $s4

    beq $s3, $s5, mult
    beq $s3, $s6, add
    beq $s3, $s7, sub

    la $a0, arg_error
    

mult:
    # multiply the arguments and branch to exit

    
    b exit
add:
    # add the arguments and branch to exit
    b exit
sub:
    # subtract the arguments and branch to exit

# print result and exit program 
exit: 
    move $a0,$t2        # move the result into register $a0
    li $v0, 1           # setup syscall 1 (print_int)
    syscall             # make the call to display the integer 
     
    li $v0, 4           # print newline
    la $a0, newline  
    syscall          
 
    jr $ra

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

    iprompt: .asciiz "Enter an integer [return]:\n"
    newline: .asciiz "\n"
