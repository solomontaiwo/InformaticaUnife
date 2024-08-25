% Cognome Nome
% Matricola
% -----
% Esercizio 1 - Esame del 2023.01.19
% -----

close all; clear variables; clc;
disp("Esercizio 1 - Esame calcolo numerico del 2023.01.19");

p7 = zeros(8, 1);
p7(1) = abs( tan((4.2*pi) - 2.8 ) );
p7(2) = log2( acos( 1.64 - exp(0.7) ) );
p7(4) = (1/4) * max( [ exp(pi); pi^exp(1) ] );
p7(6) = min( [ sin(5.7); 71.6 * exp(-4); 2.3 / pi^2 ] );
p7(7) = 9.0534;
p7(8) = -sqrt( -log( 3 / 10^5 ) );

x0 = input("\nInserisci il punto in cui valutare il polinomio: " + ...
    "x0 = ");

[r, q] = ruffiniHorner(p7, x0);
[derp, q1] = ruffiniHorner(q, x0);
[ders, q2] = ruffiniHorner(q1, x0);

fprintf("Valore del polinomio p7 nel punto x0: %g\n", r);
fprintf("Derivata prima: %g\n", derp);
fprintf("Derivata seconda: %g\n", ders * 2);

ph = fplot( @(x)(polyval(p7, x)), [-2.5, 1.1] );