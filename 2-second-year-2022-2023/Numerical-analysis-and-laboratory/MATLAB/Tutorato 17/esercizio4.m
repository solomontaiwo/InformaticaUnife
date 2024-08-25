close all
clear all
clc

n=4;
An=spdiags([-ones(n,1),4*ones(n,1),-ones(n,1)],[-1,0,1],n,n);
bn=[3;2*ones(n-2,1);3];

Jn=-diag(1./diag(An))*(tril(An,-1)+triu(An,1));
cJn=bn./diag(An); %% D^-1*b
rhoJn=eigs(Jn,1)
RJn=-log(rhoJn)

xk=zeros(n,1);
for k=1:5
    xk=Jn*xk+cJn;
end

tol=0.1e-5;
maxit=5;
x0=zeros(n,1);
[x5,it5]=jacobi(An,bn,x0,maxit,tol);
diffRel=norm(xk-x5)/norm(x5)