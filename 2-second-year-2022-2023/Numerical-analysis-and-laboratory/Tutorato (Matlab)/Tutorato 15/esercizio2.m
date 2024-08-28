close all
clear all
clc

alpha=0.15;
n=5000;
[f,t]=fes2(n,alpha);
fprintf("\n n = %d, alpha = %g:",n, alpha);
fprintf("\n%d f(alpha) = %9.3e,\t tempo = %g secondi",[1 2;f';t']);
fprintf("\n\n");