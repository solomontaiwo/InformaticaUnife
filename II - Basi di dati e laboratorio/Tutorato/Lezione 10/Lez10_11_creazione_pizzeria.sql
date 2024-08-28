-- DROP SCHEMA Pizzeria_Schema;
CREATE SCHEMA Pizzeria_Schema;
use Pizzeria_Schema;

CREATE TABLE Person (
  name VARCHAR(50) PRIMARY KEY,
  age INTEGER,
  gender VARCHAR(10)
);

CREATE TABLE Eats (
  name VARCHAR(50),
  pizza VARCHAR(50),
  PRIMARY KEY (name, pizza),
  FOREIGN KEY (name) REFERENCES Person(name)
);

CREATE TABLE Serves (
  pizzeria VARCHAR(50),
  pizza VARCHAR(50),
  price DECIMAL(6,2),
  primary key(pizzeria, pizza)
);

CREATE TABLE Frequents (
  name VARCHAR(50),
  pizzeria VARCHAR(50),
  PRIMARY KEY (name, pizzeria),
  FOREIGN KEY (name) REFERENCES Person(name),
  FOREIGN KEY (pizzeria) REFERENCES Serves(pizzeria)
);

INSERT INTO Person (name, age, gender) VALUES
  ('John', 25, 'Male'),
  ('Alice', 30, 'Female'),
  ('Mike', 35, 'Male'),
  ('Emma', 28, 'Female'),
  ('Tom', 40, 'Male'),
  ('Sophia', 22, 'Female'),
  ('Robert', 45, 'Male'),
  ('Olivia', 27, 'Female'),
  ('David', 33, 'Male'),
  ('Emily', 29, 'Female');

INSERT INTO Eats (name, pizza) VALUES
  ('John', 'Quattro Formaggi'),
  ('John', 'Pepperoni'),
  ('Alice', 'Funghi'),
  ('Mike', 'Vegetarian'),
  ('Emma', 'Funghi'),
  ('Emma', 'Margherita'),
  ('Sophia', 'Margherita'),
  ('Robert', 'Diavola'),
  ('Olivia', 'Tonno e Cipolla'),
  ('David', 'Napoletana');

INSERT INTO Serves (pizzeria, pizza, price) VALUES
  ('Pizza Paradiso', 'Margherita', 8.99),
  ('Pizza Paradiso', 'Pepperoni', 9.99),
  ('Cheesy Heaven', 'Funghi', 10.99),
  ('Cheesy Heaven', 'Vegetarian', 11.99),
  ('Pizzaland', 'Funghi', 9.99),
  ('Pizzaland', 'Quattro Formaggi', 10.99),
  ('Slice City', 'Margherita', 10.99),
  ('Slice City', 'Diavola', 11.99),
  ('Pizza Express', 'Margherita', 9.99),
  ('Open', 'Hawaian', 8.50),
  ('Pizza Express', 'Napoletana', 10.99);

INSERT INTO Frequents (name, pizzeria) VALUES
  ('John', 'Pizza Paradiso'),
  ('John', 'Cheesy Heaven'),
  ('Alice', 'Pizza Paradiso'),
  ('Mike', 'Cheesy Heaven'),
  ('Emma', 'Pizzaland'),
  ('Tom', 'Slice City'),
  ('Sophia', 'Pizzaland'),
  ('Robert', 'Slice City'),
  ('Olivia', 'Pizza Express'),
  ('David', 'Pizza Express');




