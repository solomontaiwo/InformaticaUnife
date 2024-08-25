.data
	messaggio: .asciiz "Inserisci un numero, ne calcolero' la potenza: "
	messaggioFinale: .asciiz "\nPotenza: "
	numeroInserito: .word 0
	messaggioNumeroInserito: .asciiz "Numero inserito: "
	potenza: .word 0
	
.text
	main:
		li $v0, 4
		la $a0, messaggio
		syscall
		
		li $v0, 5
		syscall
		
		move $t0, $v0
					
		sw $t0, numeroInserito
		
		li $v0, 4
		la $a0, messaggioNumeroInserito
		syscall
		
		li $v0, 1
		lw $a0, numeroInserito
		syscall
		
		mul $t1, $t0, $t0
		
		sw $t1, potenza
		
		li $v0, 4
		la $a0, messaggioFinale
		syscall
		
		li $v0, 1
		move $a0, $t1
		syscall
			
	li $v0, 10
	syscall