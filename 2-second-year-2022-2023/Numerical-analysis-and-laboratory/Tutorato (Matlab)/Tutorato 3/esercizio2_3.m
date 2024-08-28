close all
clear all
clc

% Controllo l'inversa dell'esercizio 2

A=[3,4,1;6,9,2;5,2,8];
Ainv = inv(A)

% Controllo inversa esercizio 3

B=[10,0,0;0,7,0;0,0,15];
Binv = inv(B) % Molto costosa
Binv = diag([1/B(1,1), 1/B(2,2), 1/B(3,3)]) % Metodo molto meno costoso

C = [20,1,7;0,2,17;0,0,3]
Cinv = inv(C) % Molto costoso
Cinv = invupper(C) % Modo meno costoso

D=C';
Dinv = inv(D) % Molto costoso
Dinv = (invupper(D'))' % Modo meno costoso