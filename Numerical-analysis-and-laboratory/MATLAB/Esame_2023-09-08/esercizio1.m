% Cognome Nome
% Numero matricola
% Esercizio 1 del 2023.09.08

clear all; close all; clc;

disp("Esercizo 1 - esame del 2023.09.08");

p6 = zeros(7, 1);
p6(1) = -log(sqrt(factorial(5)));
p6(2) = -tan(pi/4) + log2(abs(sin(-7.3)));
p6(3) = min([3.7E2; -tan(exp(1)*pi); fix(0.25^3)]);
% p6(4) = 0;
p6(5) = -log10(0.314/pi^3);
p6(6) = cos(3*sqrt(2*exp(-3)));
p6(7) = abs(sin((7*pi)/9.076) * exp(2/3));

x0 = input("Inserisci il punto in cui valutare p6: x0 = ");

[r, q] = ruffiniHorner(p6, x0);
[derp, q1] = ruffiniHorner(q, x0);
[ders, q2] = ruffiniHorner(q1, x0);

fprintf("Il polinomio p6 al punto x0 = %g vale %g\n", x0, r);
fprintf("La derivata prima p' è %g\n", derp);
fprintf("La derivata seconda p'' è %g\n", ders * 2);

ph = fplot(@(x)(polyval(p6, x)), [-1.00, 0.85]);

