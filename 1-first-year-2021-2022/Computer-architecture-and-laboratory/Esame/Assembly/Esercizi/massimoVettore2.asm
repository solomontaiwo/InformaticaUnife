.data
	array: .word 4, 3, 1, 2, 0, 3
.text
	main:
		addi $t0, $zero, 0		# indice
		lw $s0, array($t0)		# massimo
		addi $s1, $zero, 20		# indice massimo
				
		loop:			
			beq $t0, $s1, end
			lw $t1, array($t0)
			slt $t2, $t1, $s0
			beq $t2, $zero, max
			addi $t0, $t0, 4
			j loop
		
		max:
			addi $s0, $t1, 0
			addi $t0, $t0, 4
			j loop
			
		end:
			li $v0, 1
			addi $a0, $s0, 0
			syscall