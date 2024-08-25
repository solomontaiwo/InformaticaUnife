.text
	# Assegno a, b, c ed x rispettivamente ad $s0, $s1, $s2. $s3
	addi $s0, $zero, 4
	addi $s1, $zero, 10
	addi $s2, $zero 8
	
	addi $s3, $zero, 0
	
	slt $t0, $s1, $s0	# Se b < a, $t0 = 1
	slt $t1, $s2, $s0	# Se c < a, $t1 = 1
	
	and $t2, $t0, $t1
	
	bne $t2, $zero, label0
	
	slt $t3, $s2, $s1	# Se c < b, $t3 = 1
	beq $t3, $zero, end
	addi $s3, $s1, 0

	j end
		
	label0: 
		addi $s3, $s0, 0
		
	end:
		addi $v0, $zero, 1
		addi $a0, $s3, 0
		syscall