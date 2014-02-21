
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
.ent main
main:

     addi $sp, $sp, -32
     sw   $ra, 20($sp)
     sw   $fp, 16($sp)
     addi $fp, $sp, 28

    move $s0, $a0               # save argc
    move $s1, $a1               # save argv
    li   $s3, 3                 # value to compare  cmd args

# if no command arguments supplied, use default values

    beq  $s0, $s3, argv_values
    li   $s2, 6               
    li   $s3, 4 

# else, use commandline agruments given
    argv_values:                # note; argv[0] = project.s
    lw   $s2, 4($s1)            # set $a0 = argv[1]
    lw   $s3, 8($s1)            # set $a1 = argv[2]

    move $a0, $s2
    jal  atoi                   # parse first  argument and save
    move $s2, $v0

    move $a0, $s3               # parse second argument and save
    jal  atoi
    move $s3, $v0


    blt  $s2, $s3, swap         # swap values if n < k
    b    continue               # continue if no need to swap

swap:
    move $t0, $s2
    move $s2, $s3
    move $s3, $t0

continue:

    move $a0, $s2               # display two numbers
    li   $v0, 1
    syscall

    

    move $a0, $s3               # (n and k)
    li   $v0, 1
    syscall

   

#TODO load arguments in correct place for nchoose k funciton
    move $a0, $s2               # compute c(n,k) with n and k
    move $a1, $s3


#TODO print fac results in fac function by calling print result
#TODO print nchoosek result in function by calling print result

    jal compute_nchoosek
    move $s6, $v0


    move $a0, $v0
    li   $v0, 1
    syscall

     lw   $ra, 20($sp)
     lw   $fp, 16($sp)
     addi $sp, $sp, 32


    li   $v0, 10                # exit program
    syscall 
   
.end main
##########################################################################
#functions put in this section

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

    li    $t0, 1
    li    $t1, 1
    move  $t2, $a0
loop:
    beqz  $t2, exit_loop
    mul   $t0, $t0, $t1
    addi  $t2, $t2, -1
    addi  $t1, $t1, 1
    b loop

exit_loop:

   move   $a0, $t0
   li     $v0, 1
   syscall

    move  $v0, $t0
    jr    $ra                         # return

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

     addi $sp, $sp, -32
     sw   $ra, 20($sp)
     sw   $fp, 16($sp)
     addi $fp, $sp, 28

     sw   $a0, 0($sp)
     sw   $a1, 4($sp)
    
    sub  $a0, $a0, $a1          #  n-k
    jal  fac                    #  (n-k)!
    sw   $v0, 8($sp)            # store  (n-k)!

    lw   $a0, 0($sp)
    jal  fac                    # compute n!
    sw   $v0, 12($sp)

    lw   $a0, 4($sp)
    jal  fac                    # compute k!
    move $t1, $v0
        
    lw   $t3, 8($sp)            # $t3 = (n-k)
    mul $t5, $t3, $t1           # (n-k)!*k!

    lw   $t0, 12($sp)
    div  $t0, $t5               # n!/((n-k)! * k!)
    mfhi $t6                    # $s6 = c(n,k)
    sw   $t6, 0($sp)

    li $t6, 5

    move $a0, $t6
    li   $a3, 1

     lw   $v0, 0($sp)

     lw   $ra, 20($sp)
     lw   $fp, 16($sp)
     addi $sp, $sp, 32
    
    jr  $ra

.end compute_nchoosek

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
    space:   .asciiz " "

