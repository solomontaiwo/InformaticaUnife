close all
clear all
clc

A = [3,5,1;8,10,3;1,6,11];
b = [2,19,23]';
[L,U,P] = lu(A); %%% PA = LUb
y = sollower(L,P*b);
x = sollupper(U,y);