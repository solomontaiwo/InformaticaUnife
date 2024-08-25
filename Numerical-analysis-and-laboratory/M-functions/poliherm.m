%calcolo del polinomio di Hermite relativo ad n+1 punti
function [y, d]=poliherm(nodi,fnodi,fdnodi,x);
%costruzione della tabella delle diff.
n=length(nodi)-1;
z=zeros(2*n+2,1);
d=z;
z(1:2:2*n+1)=nodi;
z(2:2:2*n+2)=nodi;
d(1:2:2*n+1)=fnodi;
%d(2:2:2*n+2)=fnodi;
d(2:2:2*n+2)=fdnodi;
d(3:2:2*n+1)=(fnodi(2:n+1)-fnodi(1:n))./(nodi(2:n+1)-nodi(1:n));
for i=3:2*n+2
    d(i:2*n+2)=(d(i:2*n+2)-d(i-1:2*n+1))./(z(i:2*n+2)-z(1:2*n+2-(i-1)));
end
%costruzione del polinomio
y=d(2*n+2)*ones(size(x));
for i=2*n+1:-1:1
    y=y.*(x-z(i))+d(i);
end
