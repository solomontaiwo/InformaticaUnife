% Cognome Nome
% Matricola
% ----
% Test Esercizio 2 - Esame Calcolo Numerico del 2023.07.19
% ----

close all; clear all; clc;
disp("Test Esercizio 2 - Esame Calcolo Numerico del 2023.07.19");

coeffs = [0.13, -4.26, -2.91, 3.55, 9.14]';

a = input("Valore scalare positivo per la base dell'esponenziale:" + ...
    " a = ");
x = input("Valore scalare per la variabile: x = ");

format long e

y = esercizio2bis( x, a, coeffs )

format default

fprintf("Differenze relative percentuali: \n");
fprintf("\n | y(2) - y(1) | / | y(1) | = %g %%", ...
    abs( diff(y(1:2)) / y(1) )*100 );
fprintf("\n | y(3) - y(1) | / | y(1) | = %g %%", ...
    abs( diff(y([1,3])) / y(1) )*100 );
fprintf("\n | y(3) - y(2) | / y(2) | = %g %%\n\n", ...
    abs( diff(y(2:3)) / y(2) )*100 );