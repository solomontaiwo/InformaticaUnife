.data
    myCharacter: .byte 'm'
.text
    li $v0, 4
    la $a0, myCharacter
    syscall