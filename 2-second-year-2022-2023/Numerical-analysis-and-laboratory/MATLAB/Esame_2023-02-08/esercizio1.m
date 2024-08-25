% Cognome Nome
% Matricola
% Esercizio 1 del 2023-02-08

close all; clear all; clc;
disp("Esercizio 1 - esame del 2023.02.08");

p6 = zeros(7,1);
p6(1) = cos(3*asin(-sqrt(exp(1)/pi)));
p6(2) = max([3.7*10^-2; tan(2*pi); -log10(0.314); 0.7/pi^3]);
p6(3) = (55/100)*abs(sin((5*pi)/8)*exp(1/3));
p6(5) = tan(pi/3 - log2(4.17));
p6(6) = sqrt(log(factorial(7)));
p6(7) = min(exp(-2), max(sin(7.2*pi), 3.1) + 1/2);

x0 = input("Inserisci il punto in cui valutare il polinomio p6: x0 = ");

[r, q] = ruffiniHorner(p6, x0);
[derp, q1] = ruffiniHorner(q, x0);
[ders, q2] = ruffiniHorner(q1, x0);

fprintf("Il valore del polinomio al punto x0 = %g è %g\n", x0, r);
fprintf("La derivata prima è %g\n", derp);
fprintf("La derivata seconda è %g\n", ders * 2);

ph = fplot(@(x)(polyval(p6, x)),[-0.5, 1.4]);




