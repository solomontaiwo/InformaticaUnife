% Cognome Nome
% Matricola
% --------
% Test Esercizio 2 - Esame Calcolo Numerico del 2023.01.19
% -------

close all; clear variables; clc;

disp("Test esercizio 2 - Esame Calcolo Numerico del 2023.01.19");

a = -1.8; b = 10; parametri = [0.23 9.45 3 2]; N = 200001;

x = linspace(a, b, N);

fx = zeros(N, 1);

tic;
for i = 1 : N
    fx(i) = esercizio2bis( x(i), parametri );
end
tempoCiclo = toc;

tic;
z = esercizio2bis( x, parametri );
tempoVett = toc;

fprintf("\ntempo del ciclo: tempoCiclo = %g secondi", tempoCiclo);
fprintf("\ntempo dell’invocazione vettoriale: tempoVett = %g secondi", tempoVett); 
fprintf("\ndifferenza relativa: |tempoCiclo - tempoVett| / tempoCiclo = %g", ...
        abs(tempoCiclo - tempoVett) / tempoCiclo ); 
fprintf("\nincidenza percentuale: tempoVett / tempoCiclo = %g%%", ...
        tempoVett *100/ tempoCiclo );
fprintf("\n\n");

ph = plot(x, z);


