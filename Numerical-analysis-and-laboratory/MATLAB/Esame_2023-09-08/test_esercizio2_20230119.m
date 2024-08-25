% Cognome Nome
% Matricola
% -----------
% Test esercizio 2 - Esame del 20230119
% -----------

close all; clear variables; clc;

disp("Test esercizio 2 - Esame del 20230119");

N = 200001; a = -1.8; b = 10;
parametri = [0.23; 9.45; 3; 2];
x = linspace(a, b, N);
fx = zeros(N, 1);

tic;
for i = 1 : N
    fx(i) = esercizio2_20230119( x(i), params );
end
tempoCiclo = toc;

tic;
z = esercizio2_20230119( x, parametri );
tempoVett = toc;

fprintf("Tempo del ciclo: %g secondi\n", tempoCiclo);
fprintf("Tempo invocazione vettoriale: %g secondi\n", tempoVett);
fprintf("Differenza relativa: %g\n", abs( (tempoCiclo - tempoVett) ...
    / tempoCiclo) );
fprintf("Incidenza percentuale: %g%%\n", tempoVett*100/tempoCiclo);

ph = plot(x, z);
