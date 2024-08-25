.data
    numero1: .word 18
    numero2: .word 55
    
.text
    lw $t0, numero1
    lw $t1, numero2
    
    add $t2, $t0, $t1
    
    li $v0, 1
    add $a0, $zero, $t2
    syscall