.data
	array: .word 0, 1, 4, 2, 7, 8, 4, 6
.text
	main:
		addi $s0, $zero, 0	# indice
		lw $s1, array($zero)	# massimo
		addi $t0, $zero, 32	# indice massimo
	
		loop:
			beq $s0, $t0, end
			lw $t2, array($s0)
			slt $t1, $s1, $t2
			beq $t1, $zero, label
			addi $s1, $t2, 0
			
		label:
			addi $s0, $s0, 4
			j loop
				
		end:		
	
		li $v0, 1
		add $a0, $s1, $zero
		syscall	