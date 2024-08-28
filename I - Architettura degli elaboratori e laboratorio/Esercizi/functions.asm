.data
     message: .asciiz "Hi, everybody.\nMy name is Solomon.\n"
     
 .text
    main:
        jal displayMessage
        
        addi $s0, $zero, 5
        
        # Print number 5
        li $v0, 1
        move $a0, $s0
        syscall
    
    # Tell the program that the process is done.
    li $v0, 10
    syscall
  
    displayMessage:
        li $v0, 4
        la $a0, message
        syscall
        
        jr $ra