.data

.text
	main:
		lw $t0, 32($s3)		# A[8]
		add $t1, $s2, $t0	# A[12] = h + A[8]
		sw $t1, 48($s3)