% Cognome Nome
% Matricola
% ------
% Test esercizio 2 - Esame Calcolo Numerico del 2023.09.08
% ------

close all; clear variables; clc;
disp("Test esercizio 2 - Esame Calcolo Numerico del 2023.09.08");

parametri = [4.1; 2.7; 3; -1.75]; N = 3.0e7; xA = 0.1; xB = 2.8;
x = linspace(xA, xB, N)';
x( find( abs( log( x/parametri(3) ) -5.^( parametri(4)*x ) ) ...
    < 100 * eps ) ) = [];
N = numel(x);

tic; fwhlx = esercizio2( x, parametri );
tempoVect = toc;

fcptx = zeros(N, 1);
tic; 
for i = 1 : N
    fcptx(i) = esercizio2( x(i), parametri ); 
end
tempoLoop = toc;

if ( any( abs( fwhlx - fcptx ) > 10 * eps ) )
    warning("Differenze maggiori di 10*eps nella valutazione della " + ...
        "funzione");
end

fprintf("\nTempo dell'invocazione vettoriale: %g secondi", tempoVect);
fprintf("\nTempo del ciclo: %g secondi", tempoLoop);
fprintf("\nDifferenza relativa: %g\n", abs( tempoVect - ...
    tempoLoop ) / abs(tempoVect) );
fprintf("\nIncidenza percentuale: %g%%", abs(tempoVect)*100 / ...
    abs(tempoLoop) );
fprintf("\n\n");
ph = plot(x, fwhlx);