.text
	addi $s0, $zero, 5	# x = 5
	addi $s1, $zero, 4	# y = 4
	addi $s2, $zero, 0	# p = 0
	
	addi $t0, $zero, 0	# i
	addi $t1, $zero, 32
	
	loop:
		beq $t0, $t1, end
		andi $t2, $s1, 1	# y & 1
		beq $t2, $zero, skippedAdd
		
		add $s2, $s2, $s0
		
		skippedAdd:
			sll $s0, $s0, 1
			srl $s1, $s1, 1
			addi $t0, $t0, 1
			j loop
	end:
		addi $v0, $zero, 1
		addi $a0, $s2, 0
		syscall
		
		addi $v0, $zero, 10
		syscall