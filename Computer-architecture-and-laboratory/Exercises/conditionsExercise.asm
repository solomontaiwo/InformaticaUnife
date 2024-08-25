.data
	messaggio: .asciiz "Inserisci un numero: "
	numeroSalvato: .asciiz "Numero salvato: "
	maggiore: .asciiz "\nIl numero da te inserito e' maggiore di 5."
	minore: .asciiz "\nIl numero da te inserito e' minore di 5."
	numero: .word 0
	
.text
	main:
	# Stampo il messaggio di richiesta del numero
	li $v0, 4
	la $a0, messaggio
	syscall	
	
	# Aspetto input numero dell'utente
	li $v0, 5
	syscall
	
	# Salvo l'input da $v0 a numero e lo sposto in $t0
	sw $v0, numero
	move $t0, $v0
	
	# Stampo il messaggio Numero salvato"
	li $v0, 4
	la $a0, numeroSalvato
	syscall
	
	# Stampo il numero salvato
	li $v0, 1
	lw $a0, numero
	syscall	
	
	# Se il numero e' minore di 5, esegui la procedura "stampaMinore"		
	ble $t0, 5, stampaMinore
	
	# Se il numero e' minore di 5, esegui la procedura "stampaMinore"		
	bge $t0, 5, stampaMaggiore	
	
	# Termine programma
	li $v0, 10
	syscall

# Procedura che stampa il messaggio "minore"	
stampaMinore:
	li $v0, 4
	la $a0, minore
	syscall
	
	li $v0, 10
	syscall
	
# Procedura che stampa il messaggio "maggiore"	
stampaMaggiore:
	li $v0, 4
	la $a0, maggiore
	syscall
	
	li $v0, 10
	syscall