.data
	name: .asciiz "Solomon"
	
.text
	li $v0, 4
	la, $a0, name
	syscall