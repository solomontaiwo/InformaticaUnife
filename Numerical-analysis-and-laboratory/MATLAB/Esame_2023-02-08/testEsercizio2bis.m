% Cognome Nome
% Matricola 
% test esercizio 2 - 08/02/2023 

close all; clear all; clc;
disp("Test esercizio 2");

xx = linspace(-0.2, 0.3, 3001);
coeff = [-2; 5.2; 0.41; 3.7]; N = 6; 
Y1 = esercizio2( xx, coeff, N ); 

figure(1); 
ph1 = plot(xx,Y1');

coeff = [exp(-2); 0.7; pi/3; 1.4]; 
N = 20; 
[Y2, tempo] = esercizio2( xx, coeff, N );

figure(2); 
ph2 = plot(xx,Y2');
fprintf("\nTempi di esecuzione con c = [%g; %g; %g; %g] ed N = %d:", ...
    coeff,N); 

fprintf("\n- sintassi vettoriale: %.3g secondi", tempo(1));
fprintf("\n- sintassi non vettoriale: %.3g secondi", tempo(2)); 
fprintf("\nRapporto percentuale vettoriale/scalare: %5.1f%%\n\n", ...
    100*tempo(1)/tempo(2));