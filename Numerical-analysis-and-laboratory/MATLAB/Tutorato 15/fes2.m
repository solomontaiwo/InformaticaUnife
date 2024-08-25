function [z,t]=fes2(n,alpha)
if (n<1 || (fix(n)~=n))
    error("n deve essere un intero positivo");
end
z=zeros(2,1);
t=z;
tic
last=~rem(n,2);
for k=0:2:n-last
    z(1)=z(1)+sin(k*alpha)+cos((k+1)*alpha);
end
if (last) 
    z(1)=z(1)+sin(n*alpha);
end
t(1)=toc;
tic
z(2)=sum(sin([2:2:n]'*alpha))+sum(cos([1:2:n]'*alpha));
t(2)=toc;