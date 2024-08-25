close all
clear all
clc

g=@(x) (x.^4+exp(2*x));
a=0;
b=3;
tol=1e-2;
% derivata n-esima=gn=(-1/2)^n*esp(-x*2)
%|gn(x)|<=1 in [0,3]
% normainfw=(2*((b-a)/4)^(n+1)) = (1/2)^n
% quindi ho bisogno che (1/2)^n/(n+1)!<=tol
n=0;
num=1;
fact=1;
while (num/fact>tol)
    n=n+1;
    num=num*0.5;
    fact=fact*(n+1);
end
np1=n+1;

% Nodi di Chebyshev
x=0.5*((b-a)*cos((2*[n:-1;0]'+1)*pi./(2*np1))+(a+b));
y=g(x);
xx=linspace(a,b,201)';
yy=g(xx);
[z, d] = polyNewton(x, y, xx);

figure(1)
plot([xx(1);xx(end)],[0;0],"m",... % ascissa
    x,zeros(size(x)),"bx",... % nodi di Chebyshev
    x,y,"ko"); % valore della funzione di partenza nei nodi di cheb
hold on
plot(xx,yy,"k-", ... % funzione di partenza
    xx,zz,"r"); %polinomio
legend("Ascisse", "nodi di cheb", "valori funzione nei nodi di cheb", "funzione g(x)", "polinomio interpolante");

figure(2)
plot(xx,abs(yy-z));
title("grafico errore");