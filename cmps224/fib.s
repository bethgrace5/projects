# MIPS assembly: recursion
# cmps 224
# modified by Bethany Armitage
#
# This implements the following program:
# (displaying the nth Fibonacci value)
#
# int main(int argc, char *argv[]) {
#   if(argc > 2){
#       puts("Not enough arguments supplied");
#       return 0;
#   }
#   printf("The Fibonacci of %d is %d\n", argv[1], fib(argv[1]));
#    return 0;
# }
#
# int fib(int n) {
#   if(n == 0) return 0;
#   if(n == 1) return 1;
#   return fib(n-1) + fib(n-2);
# }
#
  .text
  .globl main           # Start execution at main

.ent main             # Begin the definition of main
main:
  # The book makes use of frame pointers in this example.
  # As described on page A-27, by convention a frame is 24 bytes
  # to store a0 - a3 and ra. This includes 4 bytes of padding.
  # To save fp, another 8 bytes are added (4 for fp and 4 for 
  # padding), making the frame 32 bytes long. Even though a0-a3
  # are not saved to the stack, space is still reserved on the
  # stack for them.

  addi  $sp, $sp, -32   # Stack frame is 32 bytes long
  sw    $ra, 20($sp)    # Save return address
  sw    $fp, 16($sp)    # Save old frame pointer
  addi  $fp, $sp, 28    # point to first word in bottom of frame 

  # With the return address and frame pointer saved, main()
  # can now make all its needed function calls

  move  $s0, $a0        # save argc
  move  $s1, $a1        # save first arg

  move  $s2, $zero      # zero out following registers
  move  $s3, $zero      # zero out following registers
  move  $s4, $zero      # zero out following registers

  blt   $s0, 2, needsArg # check if commandline argument is given

  lw    $a0, 4($s1)     # load commandline arg into $a0
  jal   atoi            # change from ascii to integer
  sw    $v0, 4($sp)     # save commandline arg on stack 
  move  $a0, $v0        # load integer into argument 

  jal  fib              # Call fib function
  move  $t0, $v0        # move result to t0

  # display stuff now
  la    $a0, the        # address of msg
  li    $v0, 4          # syscall 4=print string 
  syscall  

  lw    $a0, 4($sp)     # print argument supplied
  li    $v0, 1
  syscall

  la    $a0, fibb       # address of msg
  li    $v0, 4          # syscall 4=print string 
  syscall  

  move  $a0, $t0        # Move fib result to $a0 to display it
  li    $v0, 1          # syscall 1=print int
  syscall  

  li    $a0, 10         # ascii LF char
  li    $v0, 11         # syscall 1=print char 
  syscall  

  # Since the function calls are done, restore the return address
  # and frame pointer.

  lw    $ra, 20($sp)    # Restore return address
  lw    $fp, 16($sp)    # Restore frame pointer
  addi  $sp, $sp, 32    # Pop stack frame

  li    $v0, 10         # 10 is the code for exiting
  syscall               # Execute the exit

.end main
####################################################
.ent fib                # Begin the definition of the fib function

fib:
  # As above, create a 32 byte frame to store a0-a3, ra and fp.
  # For the fib procedure, a0 will be saved in offset 28 from the
  # sp (offset 0 from the fp).

  addi  $sp, $sp, -32   # Stack frame is 32 bytes long
  sw    $ra, 20($sp)    # Save return address
  sw    $fp, 16($sp)    # Save frame pointer
  addi  $fp, $sp, 28    # Set up frame pointer
  sw    $a0, 0($fp)     # Save argument (n)

  lw    $v0, 0($fp)     # Load n
  move  $v0, $zero      # set the return value to zero
  beq   $a0, $zero, L1  # return with 0 if n = 0

  li    $v0, 1          # set the return value to 1
  beq   $a0, 1, L1      # return with 1 if n = 1

  j     L2              # computes n-1 and stores value in $a0

L2:
  lw    $v1, 0($fp)     # Load n
  addi  $a0, $v1, -1    # Compute n - 1
  #sw  $a0, 4($sp)      # store the result of fib on stack 
 
  jal   fib             # recursive call to factorial function

  lw    $v1, 0($fp)     # load n
  addi  $a0, $v1, -2    # add -2 to n
  sw    $v0, 8($sp)     # store the result of fib on stack

  jal fib

  lw    $t1, 8($sp)
  addu  $v0, $v0, $t1   # Compute fib(n-1) + fib(n-2), put result in $v0

L1:                 
  lw    $ra, 20($sp)    # Restore $ra
  lw    $fp, 16($sp)    # Restore frame pointer
  addi  $sp, $sp, 32    # Pop stack frame
  jr    $ra             # Return to caller

.end fib
####################################################
.ent needsArg

needsArg:

  li    $v0, 4
  la    $a0, argError   # print error message
  syscall
  
  li    $a0, 10         # print ascii line feed
  li    $v0, 11 
  syscall

  li    $v0, 10         # Exit program
  syscall 
.end needsArg
####################################################
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
####################################################

.rdata

argError: 
 .asciiz "Error: needs commandline argument..."

the:
 .asciiz "The "
fibb:
 .asciiz "th Fibonacci number is: "
