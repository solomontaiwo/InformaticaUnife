close all
clear all
clc

A = [2,1,0;1,2,1;0,1,2];
Agj = gj(A)

%%% Metodo A=LR: AX=I => LRX=I => RX=L^-1 => X=R^-1L^-1
[L,R] = lu(A);
Linv = invupper(L');
Rinv = invupper(R);
Alr = Rinv * Linv'

%%% Medoto PA=LR: AX=I => PAX=PI => LRX=P => RX=L^-1P => X=R^-1P =>
%%% X=R^-1L^-1P

[L,R,P] = lu(A);
Linv = invupper(L');
Rinv = invupper(R);
Ap = Rinv * Linv' * P

%%% Metodo A=LL': AX=I => LL'X=I => L'X=L^-1 => X=L'^-1L^-1

L = cholesky(A);
Linv = invupper(L');
Ach = Linv * Linv'