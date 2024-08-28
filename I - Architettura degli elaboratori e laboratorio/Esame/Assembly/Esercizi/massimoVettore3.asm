.data
	array: .word 11, 56, 1, 4, 3, 14, 54, 9, 21, 2
.text
	main:
		addi $t0, $zero, 0	# indice
		lw $s0, array($t0)	# massimo
		addi $s1, $zero, 36	# indice massimo
		
		loop:
			beq $t0, $s1, end
			lw $s2, array($t0)
			slt $t1, $s0, $s2	# comparo valore massimo già trovato con array[i]
			bne $t1, $zero, setMax
			addi $t0, $t0, 4
			j loop			
			
		setMax:
			add $s0, $s2, $zero
			addi $t0, $t0, 4
			j loop
		end:
			li $v0, 1
			add $a0, $s0, $zero
			syscall
	