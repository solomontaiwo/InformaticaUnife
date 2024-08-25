close all
clear all
clc

B=[1,0,1;0,1,1;2,-1,1];
[L,R,deter] = gauss1(B);
b=[1,0,1]';
% B = LRb R triang sup L triang inf
y = solupper(L,b);
x = sollower(R,y)