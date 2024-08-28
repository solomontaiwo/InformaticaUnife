close all
clear all
clc

f=@(x) exp(3*x);
h=input("Ampiezza intervallo (0<h<1) = ");
while h<=0 || h>=1
    h=input("Ampiezza intervallo (0<h<1) = ");
end
M=exp(h);
epsilon=1e-6;
n=0;
while M/factorial(n+1)*h^(n+1)>epsilon
    n=n+1;
end

fprintf("Grado del polinomio di Maclaurin per soddisfare l'approssimazione è = %g\n",n);

%% Parte 2: do il grado, mi tiri fuori h

n=input("Grado del polinomio = ");
while n<=0 || fix(n)~=n
    n=input("Grado del polinomio = ");
end
h=(epsilon*factorial(n+1)/M)^(1/(n+1));
fprintf("h = %g\n",h);