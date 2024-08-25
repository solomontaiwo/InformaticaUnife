.text
	main:
		addi $s0, $zero, 7	# x
		addi $s1, $zero, 4	# y

		addi $a0, $s0, 0	# argument 1, x
		addi $a1, $s1, 0	# argument 2, y
		
		jal dist
		
		addi $s2, $v0, 0	# valore di ritorno
		
		j end
	
	dist:				
		slt $t0, $a1, $a0	# y < x
		beq $t0, $zero, label
		
		sub $t1, $a0, $a1
		
		j join
		
		label:
			sub $t1, $a1, $a0
		
		join:
			addi $v0, $t1, 0
			jr $ra
	
	end:
		addi $v0, $zero, 1
		addi $a0, $s2, 0
		syscall
		
		addi $v0, $zero, 10
		syscall