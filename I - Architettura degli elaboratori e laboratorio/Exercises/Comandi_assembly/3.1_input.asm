.data
	nome_programma: .asciiz "--------------- CALCOLATORE POTENZA ---------------"
	descrizione_programma: .asciiz "\nInserisci un numero, ne calcolero' la potenza: "
	messaggio_risultato: .asciiz ", la cui potenza e' pari a "
	numero_inserito: .asciiz "\nIl numero da te inserito e' "
	punto_e_riga_vuota: .asciiz ".\n"
	numero: .word 0
	risultato: .word 0
	
.text
	main:
		# Stampa nome del programma
		li $v0, 4
		la $a0, nome_programma
		syscall
		
		# Stampa descrizione del messaggio
		li $v0, 4
		la $a0, descrizione_programma
		syscall
		
		# Richiede numero a utente
		li $v0, 5
		syscall
		
		# Sposta input in label numero
		sw $v0, numero
		
		# Stampa messaggio e numero inserito
		li $v0, 4
		la $a0, numero_inserito
		syscall
		li $v0, 1
		lw $a0, numero
		syscall
		
		# Calcola potenza del numero inserito
		lw $t0, numero
		mul $s1, $t0, $t0
		sw $s1, risultato
		
		# Stampa messaggio finale
		li $v0, 4
		la $a0, messaggio_risultato
		syscall
		
		li $v0, 1
		lw $a0, risultato
		syscall
		
		li $v0, 4
		la $a0, punto_e_riga_vuota
		syscall
		
	li $v0, 10
	syscall