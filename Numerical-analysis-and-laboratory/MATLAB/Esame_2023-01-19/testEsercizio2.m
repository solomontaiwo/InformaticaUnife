% Cognome Nome
% Matricola
% Esercizio 2 - 19/01/2023

close all; clear all; clc;
disp("Test esercizio 2");

N = 200001; a = -1.8; b = 10;
parametri = [0.23; 9.45; 3; 2];
x = linspace(a, b, N)';
fx = zeros(N,1);
tic;
for i = 1:N
    fx(i) = esercizio2(x(i), parametri);
end

tempoCiclo = toc;

tic; z = esercizio2(x,parametri);

tempoVett = toc;

fprintf("\nTempo del ciclo: tempoCiclo = %g secondi", tempoCiclo);
fprintf("\nTempo dell'invocazione vettoriale: tempoVett = %g secondi", tempoVett);
fprintf("\nDifferenza relativa: |tempoCiclo - tempoVett| / tempoCiclo =  %g", ...
    abs(tempoCiclo - tempoVett) / tempoCiclo);
fprintf("\nIncidenza percentuale: tempoVett / tempoCiclo = %g%%", ...
    tempoVett*100/tempoCiclo);
fprintf("\n\n");
ph = plot(x,z);