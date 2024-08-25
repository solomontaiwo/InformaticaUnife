.text
	addi $s0, $zero, 9	# x = 9
	addi $s1, $zero, 6	# y = 6
	addi $s2, $zero, 0	# w = 0
	
	and $t0, $s0, $s1
	
	beq $t0, $zero, label1
	
	addi $s2, $zero, 1
	
	j join
		
	label1:
		beq $s0, $zero, join
		
	beq $s1, $zero, join
	addi $s2, $zero, 2
	
	join:
		addi $v0, $zero, 1
		addi $a0, $s2, 0
		syscall
		
		addi $v0, $zero, 10
		syscall