.text
	main:
		addi $s0, $zero, 7	# a
		addi $s1, $zero, 4	# b
		addi $s2, $zero, 4	# c
		addi $s3, $zero, 2	# d
		
		addi $a0, $s0, 0
		addi $a1, $s1, 0
		addi $a2, $s2, 0
		addi $a3, $s3, 0
		
		jal dist
		
		addi $s4, $v0, 0
				
		j end	
		
	dist:	
		add $t2, $a0, $a1	# a + b
		sub $t3, $a2, $a3	# c - d
		
		sllv $t5, $a1, $a3	# b << d
		
		srlv $t4, $t2, $t3	# (a + b) >> (c - d)
		
		add $v0, $t4, $t5 
				
		jr $ra
	
	end:
		addi $v0, $zero, 1
		addi $a0, $s4, 0
		syscall