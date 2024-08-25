close all
clear all
clc

A=[9 -3 -1;-2 9 0;-2 0 9];
b=[5 -2 3]';

invD=diag(1./diag(A));
J=-invD*(tril(A,-1)+triu(A,1));
GS=-tril(A)\triu(A,1); % -inv(tril(A))*triu(A,1)
eigsJ=eig(J);
eigsGS=eig(GS);
rhoJ=max(abs(eigsJ));
rhoGS=max(abs(eigsGS));
RinfJ=-log(rhoJ);
RinfGS=-log(rhoGS);
fprintf("\nrho(J) = %g, rho(GS)= %g\n", rhoJ, rhoGS);
fprintf("\nRinf(J) = %g, Rinf(GS) = %g\n", RinfJ, RinfGS);

tol=1e-5;
maxit=100;
x0=zeros(3,1);
[xJ,iterJ]=jacobi(A,b,x0,maxit,tol);
fprintf("\nNumero di iterazioni con Jacobi = %d\n", iterJ);
fprintf("\nSoluzione con Jacobi\n")
xJ

% Soluzione con Gauss Seidel
iterGS=0; xGS=x0; cGS=tril(A)\b; stop=0;
while(~stop)
    iterGS=iterGS+1;
    xold=xGS;
    xGS=GS*xold+cGS;
    stop=(norm(xold-xGS,inf)<tol*norm(xGS,inf)) || (iterGS==maxit);
end
fprintf("\nNumero iterazioni Gauss-Seidel = %d\n", iterGS);
fprintf("\nSoluzioni con Gauss-Seidel\n");
xGS