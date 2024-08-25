.data
	frase: .asciiz "Parolone complicato.\n"
	
.text
	li $v0, 4
	la $a0, frase
	syscall