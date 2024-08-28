.data
	domandaNome: .asciiz "Inserisci il tuo nome: "
	risposta: .space 20
	messaggioFinale: .asciiz "Ciao, "
	
.text
	main:
	li $v0, 4
	la $a0, domandaNome
	syscall
	
	li $v0, 8
	la $a0, risposta
	la $a1, 20
	syscall
	
	li $v0, 4
	la $a0, messaggioFinale
	syscall
	
	li $v0, 4
	la $a0, risposta
	syscall
		
	li $v0, 10
	syscall