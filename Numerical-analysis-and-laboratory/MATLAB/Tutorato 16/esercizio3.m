close all
clear all
clc

% Prima parte esercizio
A=[1 3 -1; 1 2 0.5; 5 10 -1];
b=[-2 0.5 -1]';
[L,R,p]=gauss2(A);
x1=solupper(R,sollower(L,b(p)))
fprintf("\n Norma residuo normalizzato = %g\n", norm(b-A*x1)/norm(b,inf));
[L1,R1,P1]=lu(A);
fprintf("\n max(|L-L1|) = %g\n", max(abs(L(:)-L1(:))));
fprintf("\n max(|R-R1|) = %g\n", max(abs(R(:)-R1(:))));
P=eye(3);
P=P(p,:);
fprintf("\n max(|P-P1|) = %g\n", max(abs(P(:)-P1(:))));

% Seconda parte esercizio
n=30;
normInfSol=zeros(n,1);
normInfSol=norm(x1,inf);
c=b(p);
p2=p(2);
for k=2:n
    c(p2)=0.5*c(p2);
    normInfSol(k)=norm(R\(L\c),inf);
end
plot(normInfSol,"bo");
