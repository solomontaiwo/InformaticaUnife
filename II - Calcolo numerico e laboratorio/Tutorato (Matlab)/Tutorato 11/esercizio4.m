close all
clear all
clc

rng(4) % fisso il seme dei numeri pseudo-casuali
a=0.5;
b=3;
n=5; % grado del polinomio
npunti=n+1; % numero di nodi
N=201;
C=0.25*pi*exp(-4/3); % fine della funzione f teorica sempre costante
fun=@(x) (log(x+1)+2*sin(3*x+1)+C);
tCheb=cos((2*[n:-1:0]'+1)*pi/(2*n+2)); % ho nodi di Chebyshev tra [-1,1]
xCheb=0.5*((b-a)*tCheb+a+b); % nodi di Chebyshev in [a,b]
fCheb=fun(xCheb);

d=tabDiff(xCheb,fCheb);
s=1;
p5=d(1);
for k=1:n
    s=conv(s,[1,-xCheb(k)]);
    p5=[0,p5]+d(k+1)*s;
end
check=norm(p5-polyfit(xCheb,fCheb,n),inf) % polyfit i calcola il polinomio
xx=linspace(a,b,N);
ff=fun(xx);
yy=polyval(p5,xx); % valuto il polinomio ottenuto prima nei punti xx
errRel=abs(yy-ff)./abs(yy);
figure(1)
plot(xx,ff,"-b",xx,yy,"-r",xx([1,N]),[0,0],"-k",xCheb,zeros(npunti,1),".b",xCheb,fCheb,"*r");
legend("Funzione f(x)","Polinomio interpolante p_5(x)","Nodi di Chebyshev","Valore nei nodi");
title("Funzione f(x) e polinomio interpolante p_5(x)");
xlabel("Nodi di interpolazione");
ylabel("Valori della funzione");

figure(2)
plot(xx,errRel,"-r")