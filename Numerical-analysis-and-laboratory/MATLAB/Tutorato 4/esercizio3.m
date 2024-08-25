close all
clear all
clc

C=[5,-1,-2;-1,3,1;2,1,4];
[L,R,deter]=gauss1(C)

b=[2,3,7]'
y=solupper(L,b);
x=sollower(R,y)