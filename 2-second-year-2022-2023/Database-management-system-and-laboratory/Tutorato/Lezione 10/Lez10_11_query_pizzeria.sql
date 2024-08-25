-- 1.	Aggiorna l’età di John con il numero 27
UPDATE Person
SET age = 27
WHERE name = 'John';

-- 2.	Modifica il prezzo delle pizze della pizzeria Pizza Paradiso aumentandolo del 10%
UPDATE Serves
SET price = price * 1.1
WHERE pizzeria = 'Pizza Paradiso';

-- 3.	Alice non frequenta più la pizzeria Pizza Paradiso, ora frequenta Cheesy Heaven (modificatelo)
UPDATE Frequents
SET pizzeria = 'Cheesy Heaven'
WHERE name = 'Alice' AND pizzeria = 'Pizza Paradiso';

-- 4.	Recuperare le tutte le informazioni delle persone ordinandole per età crescente
SELECT * FROM Person
ORDER BY age;

-- 5.	Determinare i nomi di donne che mangiano la pizza con i funghi o la margherita o entrambe  (nome pizza: ‘Funghi’ o ‘Margherita’).
SELECT DISTINCT Person.name FROM Person, Eats 
WHERE Person.name = Eats.name AND Person.gender = 'Female' AND Eats.pizza IN ('Funghi', 'Margherita');

-- 6.	Determinare i nomi di donne che mangiano sia la pizza con i funghi sia la pizza margherita
SELECT DISTINCT Person.name FROM Person, Eats 
WHERE Person.name = Eats.name AND Person.gender = 'Female' AND Eats.pizza = 'Funghi' AND Person.name IN 
		(SELECT Person.name FROM Person, Eats WHERE Person.name = Eats.name AND Person.gender = 'Female' AND Eats.pizza = 'Margherita');

-- 7. Tutte le pizzerie che servono almeno una pizza che Emma mangia e che costa meno di 10.00 euro
SELECT pizzeria FROM Serves, Eats
WHERE Serves.pizza = Eats.pizza and name = 'Emma' and price < 10.00;

-- 8. Nomi (senza duplicati) delle pizzerie ordinate in modo crescente frequentate da chi ha meno di 30 anni
SELECT DISTINCT pizzeria FROM  Person, Frequents
WHERE age < 30 AND Person.name = Frequents.name
ORDER BY pizzeria;

-- 9. Nomi delle pizzerie frequentate SOLO da uomini (o non frequentate da nessuno)
SELECT DISTINCT pizzeria from Serves
EXCEPT
SELECT pizzeria from Person, Frequents
WHERE gender <> 'Male' and Person.name = Frequents.name;

-- alternativa:
SELECT DISTINCT pizzeria from Serves
WHERE pizzeria not in ( SELECT pizzeria from Person, Frequents
					WHERE gender <> 'Male' and Person.name = Frequents.name);
                    
-- 10 individuare per ogni persona le pizze che mangia e che non sono servite dalle pizzerie che frequenta (risultati nella forma: nome persona, nome pizza)
SELECT name, pizza FROM Eats
WHERE (name,pizza) not in (SELECT name, pizza FROM Frequents, Serves WHERE Frequents.pizzeria = Serves.pizzeria);

-- 11. Calcola il numero totale di persone e rinominalo con 'total_people'
SELECT COUNT(*) AS total_people
FROM Person;

-- 12. Calcola l'età media delle persone e rinominalo in 'average_age'
SELECT AVG(age) AS average_age
FROM Person;

-- 13. Determina il prezzo medio per ogni pizza, ordina il risultato dalla pizza che costa meno a quella che costa di più
SELECT pizza, AVG(price) AS avg_price
FROM Serves
GROUP BY pizza
ORDER BY avg_price;

-- 14 Determina il prezzo medio per ogni pizzeria
SELECT pizzeria, AVG(price) AS avg_price
FROM Serves
GROUP BY pizzeria;

-- 15 Determina per ogni persona il numero di pizzerie che frequentano, se non ne frequentano nessuna allora il nome deve apparire comunque (es: nome, 0)
-- ordina il risultato il ordine decrescente per numero di pizzerie
SELECT Person.name, COUNT(pizzeria) as num FROM 
Person LEFT OUTER JOIN Frequents ON Person.name = Frequents.name
group by name
ORDER BY num DESC;

-- 16 determina per ogni pizzeria il numero di persone che la frequenta (se non è frequentata da nessuno deve comunque apparire), ordina il risultato decrescente per numero di persone
SELECT Serves.pizzeria, COUNT(DISTINCT Frequents.name) as num FROM 
Serves LEFT OUTER JOIN Frequents ON Serves.pizzeria = Frequents.pizzeria
GROUP BY Serves.pizzeria
ORDER BY num DESC;

-- 17 determina il nome della pizza (e il suo prezzo) con prezzo massimo
SELECT pizza, price FROM Serves
WHERE price = (SELECT MAX(price) FROM Serves);

-- 18 Trova il nome delle pizze, il numero delle persone che le mangia e tieni solo quelle mangiate da almeno 2 persone
SELECT e.pizza, COUNT(name) as tot FROM Eats e
GROUP BY e.pizza
HAVING tot >= 2;

-- 19 Trova il nome delle pizzerie che iniziano per 'Pizza'
SELECT pizzeria FROM Serves
WHERE pizzeria LIKE 'Pizza%';

-- 20 Trova tutte le informazioni delle pizzerie che non sono frequentate da nessuno
SELECT * FROM Serves 
WHERE pizzeria NOT IN (
  SELECT f.pizzeria
  FROM Frequents f
);








