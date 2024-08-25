% Cognome Nome
% Numero matricola
% Esercizio 2 - 19/07/2023

close all; clear all; clc;
disp("Test esercizio 2");

coeffs = [0.13, -4.26, -2.91, 3.55, 9.14]';

a = input("Valore scalare positivo per la base dell'esponenziale: a = ");
x = input("Valore scalare per la variabile: x = ");

format long e % attiva il formato di visualizzazione di massima accuratezza
y = esercizio2(x, a, coeffs);
format("default")

fprintf("Differenze relative percentuali: \n");
fprintf("\n | y(2) - y(1) | / | y(1) | = %g %%", abs(diff(y(1:2)) / y(1)) * 100);
fprintf("\n | y(3) - y(1) | / | y(1) | = %g %%", abs(diff(y([1,3])) / y(1)) * 100);
fprintf("\n | y(2) - y(1) | / | y(2) | = %g %%\n", abs(diff(y(2:3)) / y(1)) * 100);

