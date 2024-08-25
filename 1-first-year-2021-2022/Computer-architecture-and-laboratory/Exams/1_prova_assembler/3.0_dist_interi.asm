.text
	main:
		addi $s0, $zero, 7	# x
		addi $s1, $zero, 4	# y
		
		addi $a0, $s0, 0	# argument 1
		addi $a1, $s1, 0	# argument 2
		
		jal dist		# call function
		
		addi $s2, $v0, 0	# returned value
		
		j end
		
	dist:
		addi $sp, $sp, -8	# make space on stack for two registers
		
		sw $t0, 0($sp)		# save $t0 on stack
		sw $t1, 4($sp)		# save $t1 on stack	
		
		slt $t0, $a1, $a0	# x > y
		beq $t0, $zero, label
		sub $t1, $a0, $a1
		
		j join
		
		label:
			sub $t1, $a1, $a0
		
		join:
			addi $v0, $t1, 0
			lw $t0, 0($sp)		# restore $t0 from stack
			lw $t1, 4($sp)		# restore $t1 from stack
			addi $sp, $sp, 8	#deallocate stack space
			jr $ra			# return to caller
	
	end:
		addi $v0, $zero, 1
		addi $a0, $s2, 0
		syscall