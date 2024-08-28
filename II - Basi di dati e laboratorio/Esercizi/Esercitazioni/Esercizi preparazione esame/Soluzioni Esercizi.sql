-- 0. Aggiungere un nuovo Dipartimetno con:
-- Nome: "Quality Assurance"
-- Numero: 3  
-- Direttore: 'MRRMRY65F34G876Q'
-- Data inizio: 22 Maggio 1988
-- Budget: 65000 
--
-- E un nuovo impiegato "Mary Moore" in quel dipartimento con: 
-- SSN 'MRRMRY65F34G876Q'
-- DATA_N: 10 Agosto 1965
-- Indirizzo: 4562 Maccheroni, Houston, TX
-- Stipendio: 23000
-- Super_SSN: 'VNTGPA82R71E612D'

-- Per poter usare il nome 'Quality Assurance' devo allungare lo spazio per il nome
ALTER TABLE DIPARTIMENTO 
	MODIFY COLUMN NOME_D VARCHAR(50) NOT NULL;

-- Per inserire un nuvo dip, devo inserire il direttore, momentaneamente uso un direttore qualsiasi e poi lo cambio sotto
INSERT INTO DIPARTIMENTO 
VALUES ('Quality Assurance', 3, 'RTANRN89R47G895K', DATE '1988-05-22', 65000);

-- Inserisco il nuovo impiegato
INSERT INTO IMPIEGATO 
VALUES ('Mary', '', 'Moore', 'MRRMRY65F34G876Q', DATE '1965-08-10', '4562 Maccheroni, Houston, TX', 'F', 23000, 'MRRMRY65F34G876Q', 3);

-- Cambio il direttore
UPDATE DIPARTIMENTO 
SET SSN_DIR = 'MRRMRY65F34G876Q'; 
WHERE NUMERO_D = 3

-- 1. Aggiungere alla tabella Dipartimento una nuova colonna "BUDGET", ai dipartimenti già creati deve essere assegnato un budget di 30000
ALTER TABLE DIPARTIMENTO
	ADD COLUMN BUDGET INT DEFAULT 30000;

-- 2. Recuperare il cognome di tutti gli impiegati senza duplicati.
SELECT DISTINCT COGNOME 
FROM IMPIEGATO;

-- 3. Recuperare tutte le informazioni degli impiegati con cognome Smith.
SELECT * 
FROM IMPIEGATO 
WHERE COGNOME = 'Smith';

-- 4. Recuperare tutte le informazioni degli impiegati il cui cognome è "Smith" o "Doe".
-- OR
SELECT * 
FROM IMPIEGATO
WHERE COGNOME = 'Smith' 
	OR COGNOME = 'Borg';

-- IN 
SELECT * 
FROM IMPIEGATO
WHERE COGNOME IN ('Smith', 'Borg');

-- 5. Selezionare tutte le informazioni sugli impiegati che lavorano al dipartimento 5.
SELECT * FROM IMPIEGATO 
WHERE DIPARTIMENTO = 5;

-- 6. Recuperare tutte le informazioni degli impiegati che lavorano nei dipartimenti 1 e 5
SELECT * 
FROM IMPIEGATO
WHERE N_D = 1 OR N_D = 5;

-- 7. Recuperare tutte le informazioni degli impiegati il cui cognome inizia con "S"
SELECT * 
FROM IMPIEGATO
WHERE COGNOME LIKE 'S%';

-- 8. Recuperare la somma di tutti i budget dei dipartimenti
SELECT SUM(BUDGET) 
FROM DIPARTIMENTO;

-- 9. Recuperare il numero di impiegati in ogni dipartimento (Solo il numero dipartimento e il numero di impiegati)
SELECT N_D AS DIPARTIMENTO, COUNT(*) AS NUMERO_IMPIEGATI
FROM IMPIEGATO
GROUP BY N_D;

-- 10. Recuperare tutte le informazioni degli impiegati includeno le informazioni del dipartimento in cui lavorano
SELECT SSN, I.NOME_BATT AS Nome_I, COGNOME, D.NOME_D AS Name_D, NOME_D, NUMERO_D, BUDGET
FROM IMPIEGATO I 
	INNER JOIN DIPARTIMENTO D
		ON I.N_D = D.NUMERO_D;

-- 11. Recuperare il nome e il cognome di ogni impiegato, insieme al nome e al budget del dipartimento in cui lavora
SELECT I.NOME_BATT, COGNOME, D.NOME_D AS NOME_D, BUDGET
FROM IMPIEGATO I 
	INNER JOIN DIPARTIMENTO D
		ON I.N_D = D.NUMERO_D;

-- 12. Recuperare il nome e il cognome di ogni impiegato che lavora in un dipartimento con budget > 60000
SELECT IMPIEGATO.NOME_BATT, COGNOME
FROM IMPIEGATO 
	INNER JOIN DIPARTIMENTO
		ON IMPIEGATO.N_D = DIPARTIMENTO.NUMERO_D
		AND DIPARTIMENTO.BUDGET > 60000;

-- 13. Recuperare il nome del dipartimento con un Budget superiore alla media del budget di tutti i dipartimenti
SELECT *
FROM DIPARTIMENTO
WHERE BUDGET > (
	SELECT AVG(BUDGET)
	FROM DIPARTIMENTO);


-- 14. Recuperare il nome dei dipartimenti che hanno più di 2 impiegati.
SELECT NOME_D FROM DIPARTIMENTO
WHERE NUMERO_D IN (
	SELECT N_D
	FROM IMPIEGATO
	GROUP BY N_D
		HAVING COUNT(*) > 2);


-- 15. Recuperare nome e cognome degli impiegati che lavorano nel dipartimento con il budget minore .
-- SELECT I.NOME_BATT, I.COGNOME
-- FROM IMPIEGATO I
-- 	WHERE I.N_D = (
-- 		SELECT NUMERO_D 
-- 		FROM ( 
--			SELECT * 
--			FROM DIPARTIMENTO d 
--			ORDER BY d.BUDGET DESC LIMIT 1);


-- 15. Ridurre il Budget di ogni dipartimento del 10% per i dipartimenti che hanno un budget maggiore di 60000
UPDATE DIPARTIMENTO 
SET BUDGET = (BUDGET*0.9) 
WHERE BUDGET IN (
	SELECT * 
	FROM (
		SELECT BUDGET 
        FROM DIPARTIMENTO 
        WHERE BUDGET > 60000) as t);
-- Spiegazione: non posso fare:
-- UPDATE DIPARTIMENTO 
-- SET BUDGET = (BUDGET * 0.9);
-- Perchè non esiste la clausula WHERE (che deve comunque avere una Key per essere "sicura".
-- Uso allora una selezione con doppio annidamente per selezionare tutte le righe che hanno budget > 60000.
-- Alternativa: usiamo la variabile SQL_SAFE_UPDATES
SET SQL_SAFE_UPDATES = 0;
UPDATE DIPARTIMENTO 
SET BUDGET = (BUDGET * 0.9)
WHERE BUDGET > 60000
SET SQL_SAFE_UPDATES = 1;


-- 16. Riassegnare tutti gli impiegati del dipartimento 5 al dipartimento 3.
UPDATE IMPIEGATO 
SET N_D = 3 
WHERE N_D = 5;


-- 17 Ricavare il nome completo di tutti gli impiegati (NOME_BATT, INIZ_INT, COGNOME) e il nome del dipartimento in cui lavorano
-- 18 Ricavare l'eneco dei nomi completi degli impiegati e il salario in ordine crescente di salario
-- 18 Ricavare l'eneco dei nomi completi degli impiegati e il salario in ordine decrescente di salario
-- 20 Ricavare l'eneco dei nomi completi degli impiegati del dipartimento nr 5 che lavorano almeno 10 ore sul progetto "ProductX"
-- 21 Ricavare l'eneco dei nomi completi degli impiegati del dipartimento nr 5 che lavorano meno di 20 ore sul progetto "ProductX"
-- 21 Ricavare l'eneco dei nomi completi degli impiegati che sono direttamente supervisionati da Franklin Wong (Senza utlizzare l'SSN di Franklin Wong direttamente nella query)
-- 22 Per ogni progetto, elencare il nome del progetto e le ore che vengono impiegate da tutti gli impioegati sul progetto stesso
-- 23 Elencare i nomi completi degli impiegati che non lavorano su alcun progetto
-- 24 Elencare per ogni dipartimento, il nome e il salario medio degli impiegati che lavorano su quel dipartimento
-- 25 Ricavare il nome e gli indirizzi di tutti gli impiegati che lavorano almeno ad un progetto di un dipartimento che ha come sede Huston
-- 26 Elencare i dipartimenti che non hanno impiegati
