#
# Bethany Armitage
# 
#           Register usage 
#            $t0  outer counter
#            $t1  inner counter
#            $t6  constant 6
# 
#
.data
star:    .asciiz "* "
newline: .asciiz "\n"

.text

.ent main
main:
    li $t0, 0                   # outer counter
    li $t1, 0                   # inner counter
    li $t6, 6                   # initialize stopping condition
    

outer_loop:
    beq $t0, $t6, exit          # exit if counter hits 6
    addi $t0,$t0, 1             # increment outer counter

    li $t1, 0                   # reset inner counter


inner_loop:

    la $a0, star                # print star
    li $v0, 4
    syscall
    
    addi $t1, $t1, 1

    blt $t1, $t0, inner_loop

    la $a0, newline             # print newline
    li $v0, 4
    syscall
    b outer_loop


exit:

    la $a0, newline             # print newline
    li $v0, 4
    syscall

    li $v0, 10                  # exit
 
    syscall
    
    
        
    
