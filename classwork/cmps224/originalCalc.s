# filename: calc.s
# description: cs 224 lab 06 

# prompt the user to enter two integers, sum integers and display the result

.text
.globl read 
.globl main 
.ent  main

main:

  jal read
  li  $v0,10       # 10 is exit system call
  syscall    

.end  main


read:

  # prompt for first integer
  li $v0 4         # load immediate with 4 to setup syscall 4 (print_str)
  la $a0, iprompt  # load address of prompt into $a0 for print_str
  syscall          # display the prompt 

  # read the first integer 
  li $v0 5         # setup syscall 5 (read_int)
  syscall          # integer returned in $v0
  move $t0, $v0    # move first integer to $t0

  # prompt for second integer
  li $v0, 4        # load immediate with 4 to setup syscall 4 (print_str)
  la $a0, iprompt  # load address of prompt into $a0 for print_str
  syscall          # display the prompt 

  # read the second integer 
  li $v0 5         # setup syscall 5 (read_int)
  syscall          # integer returned in $v0
  move $t1, $v0    # move first integer to $t1

  # sum the two integers
  add $t2, $t0, $t1 

  move $a0,$t2     # move the result into register $a0
  li $v0, 1        # setup syscall 1 (print_int)
  syscall          # make the call to display the integer 
   
  li $v0, 4        # print newline
  la $a0, newline  
  syscall          
 
  jr $ra

.data

iprompt: .asciiz "Enter an integer [return]:\n"
newline: .asciiz "\n"
