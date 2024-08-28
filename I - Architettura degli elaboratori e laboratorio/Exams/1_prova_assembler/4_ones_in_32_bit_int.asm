.text
	addi $s0, $zero, 0	# i
	addi $s1, $zero, 0	# n
	addi $s2, $zero, 0	# y
	addi $s3, $zero, -68	# x = 18
	addi $t0, $zero, 32
	
	loop:
		beq $s0, $t0, end
		andi $t1, $s3, 1	# y = x & 1
		add $s1, $s1, $t1	# n = n + y
		srl $s3, $s3, 1		# x = x >> 1
		addi $s0, $s0, 1	# i = i + 1
		j loop
		
	end:
		addi $v0, $zero, 1
		addi $a0, $s1, 0
		syscall
		
		addi $v0, $zero, 10
		syscall