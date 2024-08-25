% Cognome Nome
% Matricola
% ------
% Esercizio 1 - Esame Calcolo Numerico del 2023.09.08
% ------

close all; clear variables; clc;
disp("Esercizio 1 - Esame Calcolo Numerico del 2023.09.08");

p6 = zeros(7, 1);
p6(1) = -log( (sqrt( factorial(5) ) ) );
p6(2) = -tan( pi / 4 ) + log2( abs( sin(-7.3) ) );
p6(3) = min( [ 3.7E2; -tan( exp(1) * pi ); 0.25^3 ] );
p6(4) = 0;
p6(5) = -log10( 0.314 / pi^3 );
p6(6) = cos( 3 * sqrt( 2 * exp(-3) ) );
p6(7) = abs( sin( (7*pi) / 9.076 ) * exp(2/3) );

x0 = input("Punto in cui valutare il polinomio p6: x0 = ");

[r, q] = ruffiniHorner(p6, x0);
[derp, q1] = ruffiniHorner(q, x0);
[ders, q2] = ruffiniHorner(q1, x0);

fprintf("Valore del polinomio al punto x0 = %g\n", r);
fprintf("Derivata prima = %g\n", derp);
fprintf("Derivata seconda = %g\n", ders * 2);

ph = fplot(@(x)(polyval(p6, x)), [-1.00, 0.85] );