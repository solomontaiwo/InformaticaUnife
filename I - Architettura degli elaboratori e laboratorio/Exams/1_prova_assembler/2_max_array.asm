.data
	array0: .word 0, 9, 4, 2, 7, 8, 4, 6

.text
	addi $s0, $zero, 0	# indice array, i
	addi $s1, $zero, 0	# max del vettore, x
	addi $t0, $zero, 32	# max dimensione array in byte
		
	
	loop:
		lw $s2, array0($s0)	# x = array[0]
		beq $s0, $t0, end	# while i != 32 (dimensione max array)
		slt $t1, $s1, $s2	# if x < array[i]
		beq $t1, $zero, avanti
		addi $s1, $s2, 0
		addi $s0, $s0, 4
		
		j loop	
		
	avanti:
		addi $s0, $s0, 4
		j loop
		
	end:
		addi $v0, $zero, 1
		addi $a0, $s1, 0
		syscall
		
		addi $v0, $zero, 10
		syscall