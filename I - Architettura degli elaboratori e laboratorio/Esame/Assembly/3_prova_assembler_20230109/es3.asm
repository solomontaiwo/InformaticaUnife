.data
	array: .word 0, 1, 2, 4, 4, 6, 7, 9

.text
	addi $s0, $zero, 0	# cresc = 0
	addi $s1, $zero, 0	# decresc = 0
	addi $s2, $zero, 0	# non_strett = 0
	addi $s3, $zero, 32	# n = 8, dimensione vettore
	addi $s4, $zero, 0	# i
	sub $s5, $s3, 4		# n - 1
	
	loop:
		beq $s4, $s5, end
		lw $t0, array($s4)	# array[i]
		addi $t1, $s4, 4	# i + 1
		lw $t2, array($t1)	# array[i + 1]
		
		beq $t0, $t2, addNonStrett
		
		slt $t3, $t2, $t0	# array[i+1] < array[i]
		bne $t3, $zero, addDecresc
		addi $s0, $s0, 1	# cresc = cresc + 1
		addi $s4, $s4, 4	# i = i + 4
		j loop
								
		addDecresc:
			addi $s1, $s1, 1	# decresc = decresc + 1
			addi $s4, $s4, 4	# i = i + 4
			j loop
			
		addNonStrett:
			addi $s2, $s2, 1	# non_strett = non_strett + 1
			addi $s4, $s4, 4	# i = i + 4
			j loop
				
	end:
		addi $v0, $zero, 1
		addi $a0, $s0, 0
		syscall
		
		addi $v0, $zero, 1
		addi $a0, $s1, 0
		syscall
		
		addi $v0, $zero, 1
		addi $a0, $s2, 0
		syscall
		
		addi $v0, $zero, 10
		syscall
	
	