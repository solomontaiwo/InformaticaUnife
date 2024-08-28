close all
clear all
clc

rng(4)
a=-2; b=4; myrho=1.5; mybeta=4; mygamma=1.8; N=3; npunti=10*N;
x=rand(npunti,1)*(b-a)+a;
mydelta=(2*rand(npunti,1)-1)*myrho/4;
fun=@(x)(myrho*sin(mybeta*x+mygamma)+mydelta);
A=x.^([4:-1:0]);
y=fun(x);
fprintf("Soluzione con minimi quadrati");
sol=(A'*A)\(A'*y)
fprintf("Soluzione con \");
sol1=A\y
xx=linspace(a,b,1001);
ff=polyval(sol1,xx);
plot(x,y,"ro",xx,ff,"b");