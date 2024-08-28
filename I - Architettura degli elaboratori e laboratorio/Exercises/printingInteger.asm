.data
    age: .word 26    # this is a word or integer

.text
    # Print an integer to the screen
    li $v0, 1
    lw $a0, age
    syscall