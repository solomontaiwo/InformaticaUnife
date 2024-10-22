-- Q0
SELECT DATA_N, INDIRIZZO
FROM IMPIEGATO
WHERE NOME_BATT='John' AND INIZ_INT='B' AND COGNOME='Smith';

-- Q1
SELECT NOME_BATT, COGNOME, INDIRIZZO
FROM IMPIEGATO, DIPARTIMENTO
WHERE NOME_D='Research' AND NUMERO_D=N_D;

-- Q1.2
SELECT NOME_BATT, COGNOME, NOME_D
FROM IMPIEGATO, DIPARTIMENTO
WHERE NUMERO_D=N_D;

-- Q2
SELECT NUMERO_P, NUMERO_D, NOME_BATT, DATA_N, INDIRIZZO 
FROM PROGETTO, DIPARTIMENTO, IMPIEGATO
WHERE NUMERO_D=NUM_D 
	AND SSN_DIR=SSN 
	AND SEDE_P='Stafford';

-- Q8
SELECT I.NOME_BATT, I.COGNOME, S.NOME_BATT, S.COGNOME
FROM IMPIEGATO AS I, IMPIEGATO AS S
WHERE I.SUPER_SSN=S.SSN

-- Q15
SELECT MAX(STIPENDIO), MIN(STIPENDIO) AS Minimo, AVG(STIPENDIO) AS Medio
FROM IMPIEGATO

-- Q18
SELECT COUNT(*)
FROM IMPIEGATO, DIPARTIMENTO
WHERE N_D=NUMERO_D AND NOME_D='Research'

-- Q20
SELECT N_D AS NUMERO, COUNT(*) AS IMPIEGATI, AVG(STIPENDIO) AS MEDIA
FROM IMPIEGATO
GROUP BY N_D

-- Q21
SELECT NUMERO_P, NOME_P, COUNT(*) AS IMPIEGATI
FROM PROGETTO, LAVORA_SU
WHERE NUMERO_P=N_P
GROUP BY NUMERO_P, NOME_P

-- Q22
SELECT NUMERO_P, NOME_P, COUNT(*) AS NUMERO_I
FROM PROGETTO, LAVORA_SU
WHERE NUMERO_P=N_P
GROUP BY NUMERO_P, NOME_P
HAVING NUMERO_I > 2
