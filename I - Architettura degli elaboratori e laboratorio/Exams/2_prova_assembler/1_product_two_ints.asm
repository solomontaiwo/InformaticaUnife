.text
	addi $s0, $zero, 16	# x, moltiplicando
	addi $s1, $zero, 18	# y, moltiplicatore
	addi $s2, $zero, 0	# p, prodotto
	
	addi $s3, $zero, 0	# variabile 1, i
	addi $s4, $zero, 0	# variabile 2, tmp
	
	addi $t0, $zero, 32	# indice max loop
	
	loop:
		beq $s3, $t0, end	# i < 32
		andi $s4, $s1, 1	# tmp = y & 1
		bne $s4, $zero, label	# tmp != 0
		srl $s1, $s1, 1		# y = y >> 1
		sll $s0, $s0, 1		# x = x << 1
		addi $s3, $s3, 4	# i = i + 1
		j loop 
		
	label:
		add $s2, $s2, $s0	# p = p + x
		srl $s1, $s1, 1		# y = y >> 1
		sll $s0, $s0, 1		# x = x << 1
		addi $s3, $s3, 4 	# i = i + 1
		j loop
		
	end:
		addi $v0, $zero, 1
		addi $a0, $s2, 0
		syscall
		
		addi $v0, $zero, 10
		syscall