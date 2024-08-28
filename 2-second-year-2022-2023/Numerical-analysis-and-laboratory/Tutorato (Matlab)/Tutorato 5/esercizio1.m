close all
clear all
clc

A=[1 0 2; 1 3 1; 5 2 -1];
b=[3 5 6]';
[L,R,P,deter] = gauss2(A)
fprintf("La soluzione con pivoting parziale è");
%%% Ax=b
%%% PAx=Pb
%%% LRx=Pb
%%% Risolvo L=Pb mi fornisce y
%%% sollupper Ry

y = sollower(L,b(P));
x = solupper(R,y)

fprintf("\n Residuo normalizzato: %g", (b-A*x)/norm(b,inf));


%%% Mal condizionamento
fprintf("\nLo studio del mal condizionamento mi dà: %g\n", (b-A*x)/norm(b,inf));
%%% se numero piccolo allora buono
