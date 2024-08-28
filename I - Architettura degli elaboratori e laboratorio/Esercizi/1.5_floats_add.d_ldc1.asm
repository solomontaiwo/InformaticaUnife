.data
	float_number1: .double 10.5
	float_number2: .double 5.2
	
.text
	ldc1 $f0, float_number1
	ldc1 $f2, float_number2
	
	add.d $f12, $f0, $f2
	
	li $v0, 3
	syscall