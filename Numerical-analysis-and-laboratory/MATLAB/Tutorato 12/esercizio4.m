close all
clear all
clc

x=[-5 -4 0 4 5]';
y=[-6 -5 7 0 3]';

n=3;%grado del polinomio
l=length(x);
A=zeros(l,n+1);
A(:,n+1)=ones(1,1);
for i=n:-1:1
    A(:,i)=A(:,i+1).*x;
end
[alpha,ris,r]=regress(A,y);
z=linspace(-5,5);
p=polyval(alpha,z);
plot(x,y,'o',z,p,'b');
legend('punti','minimi quadrati')
title('Funzione f(x)=a_0+a_1x+a_2x^2+a_3x^3');
fprintf('La somma dei quadrati dei residui=%g\n',ris);

%%% secondo pezzo polinomio f(x)=a_1+a_2exp(x)

n=1; %grado del polinomio
l=length(x);
A=zeros(l,n+1);
A(:,1)=exp(x);
A(:,2)=ones(1,1);
[alpha,ris,r]=regress(A,y);
z=linspace(-5,5);
f=alpha(1)+alpha(2)*exp(z);
figure
plot(x,y,'o',z,f,'r')
legend('punti','minimi quadrati');
title('Grafico funzione f(x)=a_1+a_2e^x');
fprintf('La somma dei quadrati dei residui=%g\n',ris);