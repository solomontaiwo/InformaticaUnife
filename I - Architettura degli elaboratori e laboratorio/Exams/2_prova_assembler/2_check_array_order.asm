.data
	array: .word 0, 1, 4, 2, 7, 8, 4, 6 
	ord_c: .asciiz "Ordinamento crescente"
	ord_sc: .asciiz "Non crescente"

.text
	addi $s0, $zero, 0	# i = 0
	addi $s1, $zero, 1	# ord_c
	addi $s2, $zero, 1	# ord_sc
	
	addi $s3, $zero, 32	# valore max loop
		
	loop:
		beq $s0, $s3, end1
		
		lw $t0, array($s0)	# array[i]
		addi $t1, $s0, 4
		lw $t2, array($t1)	# array[i+1]
		
		beq $t0, $t2, label1	# array[i+1] == array[i]
		
		slt $t3, $t2, $t0	# array[i+1] < array[i]
		bne $t3, $zero, label2	
		
		addi $s0, $s0, 4
		j loop
		
	label1:
		addi $s2, $zero, 0	# ord_sc = 0
		
		slt $t3, $t2, $t0	# array[i+1] < array[i]
		bne $t3, $zero, label2
		
		addi $s0, $s0, 4	# i = i + 1
		j loop
				
	label2:
		addi $s1, $zero, 0	# ord_c = 0
		
		addi $s0, $s0, 4
		j loop
		
	
		
	end1:
		beq $s1, $zero, end2
		addi $v0, $zero, 4
		la $a0, ord_c
		syscall
		
		addi $v0, $zero, 10
		syscall
		
	end2:
		addi $v0, $zero, 4
		la $a0, ord_sc
		syscall
		
		addi $v0, $zero, 10
		syscall