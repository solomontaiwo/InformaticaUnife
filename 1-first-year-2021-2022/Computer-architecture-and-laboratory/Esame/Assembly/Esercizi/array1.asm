.data
	names: .space 16
	
	Ryan: .asciiz "Ryan\n"
	Malcolm: .asciiz "Malcolm\n"
	Pino: .asciiz "Pino\n"
	Vinny: .asciiz "Vinny\n"
.text
	main:
	
	la $t0, names
	
	la $t1, Ryan
	sw $t1, 0($t0)
	
	la $t1, Malcolm
	sw $t1, 4($t0)
	
	la $t1, Pino
	sw $t1, 8($t0)
	
	la $t1, Vinny
	sw $t1, 12($t0)
	
	li $v0, 4
	lw $a0, 4($t0)
	syscall
	
	
	 
	 
	 