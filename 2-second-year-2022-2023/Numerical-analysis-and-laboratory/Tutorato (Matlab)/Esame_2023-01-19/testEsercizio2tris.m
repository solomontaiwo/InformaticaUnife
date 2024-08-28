% Cognome Nome
% Matricola
% ------
% Test Esercizio 2 - Esame Calcolo Numerico del 2023.01.19
% ------

close all; clear all; clc;
disp("Test Esercizio 2 - Esame Calcolo Numerico del 2023.01.19");

a = -1.8; b = 10; parametri = [0.23 9.45 3 2]; N = 200001;

x = linspace(a, b, N);
fx = zeros(N, 1);

tic;
for i = 1 : N
    fx(i) = esercizio2tris( x(i), parametri );
end
tempoCiclo = toc;

tic; z = esercizio2tris( x, parametri ); tempoVett = toc;

fprintf("\nTempo di calcolo ciclo: %g\n", tempoCiclo);
fprintf("Tempo di calcolo vettore: %g\n", tempoVett);
fprintf("Differenza relativa: %g\n", abs(tempoCiclo - tempoVett) / ...
    tempoCiclo );
fprintf("Percentuale di tempoVett rispetto a tempoCiclo: %g%%\n", ...
   tempoVett * 100 / tempoCiclo );

ph = plot(x, z);