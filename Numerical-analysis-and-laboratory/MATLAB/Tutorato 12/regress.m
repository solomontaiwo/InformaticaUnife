function [alpha,res,r]=regress(A,y);
%soluzione dei minimi quadrati lineari nel caso di A mat di regressione di
%rango pieno
%alpha=p.to di minimo, sol del problema.
%res=valore del minimo.
%r=vettore residuo.
[m,n]=size(A);
if m<n
    error('Numero dei dati deve essere maggiore dei gradi di libertà');
end
[Q,Rbar]=qr(A);
R=Rbar(1:n,:);
ytilde=Q'*y;
alpha=R\ytilde(1:n);
res=norm(ytilde(n+1:m))^2;%oppure res=norm(r)^2;
r=Q*[zeros(n,1);ytilde(n+1:m)]; %oppure r=y-A*alpha;

