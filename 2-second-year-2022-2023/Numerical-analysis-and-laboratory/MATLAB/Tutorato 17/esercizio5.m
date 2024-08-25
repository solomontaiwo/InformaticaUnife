close all
clear all
clc

g=@(x) (exp(-x/2));
a=0;
b=2;
tol=1e-5;
%% ((b-a)/2)^(n+1)1/(2^n)T_(n+1)(t)(f^(n+1)(xi))/(n+1)!
n=0; % grado del polinomio
num=1;
fact=1;
while (num/fact>tol)
    n=n+1;
    num=num*0.5;
    fact=fact*(n+1);
end
% l'n che esce da qui è il grado del polinomio
np1=n+1;
x=0.5*((b-a)*cos((2*[n:-1:0]'+1)*pi./(2+np1))+(a+b));
y=g(x);
% per fare il plot decente
xx=linspace(a,b,201)';
yy=g(xx);
d=tabDiff(x,y);
zz=d(np1)*ones(size(xx));
for k=n:-1:1
    zz=zz.*(xx-x(k))+d(k);
end

figure(1)
plot(xx,yy,"k-",xx,zz,"r-");
legend("grafico di partenza","polinomio");
figure(2)
plot(xx,abs(yy-zz));
title("errore")