.data
	Ryan: .asciiz "Ryan\n"
	Malcolm: .asciiz "Malcolm\n"
	Pino: .asciiz "Pino\n"
	Vinny: .asciiz "Vinny\n"
	
	names: .word Ryan, Malcolm, Pino, Vinny
	
	iterator: .word 0
	size: .word 3
.text
	main:
	
	la $t0, names
	
	lw $t1, iterator
	lw $t2, size
	
	beginLoop:	
	bgt $t1, $t2, exitLoop
	
	sll $t3, $t1, 2
	
	addu $t3, $t3, $t0
	
	li $v0, 4
	lw $a0, 0($t3)
	syscall
	
	addi $t1, $t1, 1
	
	j beginLoop
	
	exitLoop: