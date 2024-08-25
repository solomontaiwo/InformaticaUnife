close all
clear all
clc

x=linspace(1,2,100);
f=@(x)exp(-2*x);
f1=@(x)-2*exp(-2*x);
z=linspace(1,2,10); %nodi chiesti a testo
y=f(z);
zeta=polnew(z,y,x);

S=spline(z,y);
[x1,C,l,k]=unmkpp(S);
yf=ppval(S,x); %per valutare la spline in x
subplot(2,1,1)
plot(x,f(x),'r',x,yf,'b');
legend('Originale','Spline')

%calcoliamo la derivata della spline
C1=zeros(l,3);
C1(:,1)=3*C(:,1);
C1(:,2)=2*C(:,2);
C1(:,3)=C(:,3);
S1=mkpp(x1,C1);
zf=ppval(S1,x);
subplot(2,1,2)
plot(x,f1(x),'g',x,zf,'m');
legend('Derivata esatta','Derivata della spline');

fprintf('Errore in norma infinito sulla funzione=%g\n',norm(f(x)-yf,'inf'));
fprintf('Errore in norma infinito sulla derivata=%g\n',norm(f1(x)-zf,'inf'));
