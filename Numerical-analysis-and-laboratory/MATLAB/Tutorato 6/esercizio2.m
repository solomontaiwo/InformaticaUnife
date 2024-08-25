close all
clear all
clc

A = [1,1,1;0,1,-1;1,1,2];
b = [3,0,4]';
[Q,R] = qrfact(A);
fprintf("La soluzione vale\n");
% Ax = b
% QRx = b
% Rx = Q^-1b
% Rx = Q'b
xQR = solupper(R,Q'*b)
fprintf("Il determinante di A vale %d\n", det(Q) * det(R));
fprintf("Il residuo normalizzato vale %g\n", (b-A*xQR)/norm(b,inf));

% Calcolo dell'inversa con fattorizzazione ottenuta
% AX = I => QRX = I => RX = Q' => X = R^-1Q'
[Rinv] = invupper(R);
Ainv = Rinv * Q';
fprintf("L'inversa con la fattorizzazione vale \n");
disp(Ainv)
fprintf("L'inversa con il comando di Matlab vale \n");
disp(inv(A))

% Controllo risultati con qr Matlab
[Qm,Rm] = qr(A);
fprintf("La soluzione con Matlab vale \n");
xm = solupper(Rm,Qm'*b)
fprintf("Il residuo normalizzato con Matlab vale %g\n", (b-A*xm)/norm(b,inf));