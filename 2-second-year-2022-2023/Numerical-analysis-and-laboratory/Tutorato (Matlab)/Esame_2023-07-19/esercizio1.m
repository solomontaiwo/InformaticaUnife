% Cognome Nome
% Numero matricola
% Esercizio 1 - esame del 2023.07.19

close all; clear all; clc;

disp("Esercizio 1 - esame del 2023.07.19");

p6 = log(2.^([4 5 6 8 9 11 12]'));

% Alternativa
% p6 = zeros(7,1);
% p6(1) = log(2^12);
% p6(2) = log(2^11);
% p6(3) = log(2^9);
% p6(4) = log(2^8);
% p6(5) = log(2^6);
% p6(6) = log(2^5);
% p6(7) = log(2^4);

x0 = input("Inserire il punto nel quale valutare il polinomio (double): x0 = ");

[r, q] = ruffiniHorner(p6, x0);
[derp, q1] = ruffiniHorner(q, x0);
[ders, q2] = ruffiniHorner(q1, x0);

fprintf("\nValore del polinomio in xo = %g\n", r);
fprintf("Derivata prima del polinomio = %g\n", derp);
fprintf("Derivata seconda del polinomio in x0 = %g\n", ders * 2);
ph = fplot(@(x)(polyval(p6, x)), [-1.4, 0.5]);




