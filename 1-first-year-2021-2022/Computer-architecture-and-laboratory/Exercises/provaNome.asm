.data
    nome: .asciiz "Solomon"
    
.text
    li $v0, 4
    la $a0, nome
    syscall