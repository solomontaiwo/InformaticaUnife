.data
	messaggioMassimo: .asciiz "Il numero massimo e': "
.text
	main:
		addi $t0, $zero, 4	# $t0 = a = 4
		addi $t1, $zero, 10	# $t1 = b = 10
		addi $t2, $zero, 8	# $t2 = c = 8
		
		addi $t3, $zero, 0	# $t3 = x = maxValue
		
		blt $t0, $t1, compareBC
		
		blt $t0, $t2, setMaxC
		
		addi $t3, $t0, 0
		
	finalMessage:
		li $v0, 4
		la $a0, messaggioMassimo
		syscall
		
		li $v0, 1
		add $a0, $t3, $zero
		syscall
		
		li $v0, 10
		syscall
		
	compareBC:
		slt $t4, $t1, $t2
		beq $t4, $zero, setMaxB
		add $t3, $zero, $t2
		j finalMessage
		
	setMaxB:
		add $t3, $t1, $zero
		j finalMessage
		
	setMaxC:
		add $t3, $t2, $zero
		j finalMessage