.text
	main:
		addi $s1, $zero, 5	# g
		addi $s2, $zero, 2	# h
		
		lw $t0, 32($s3)
		
		add $s1, $s2, $t0