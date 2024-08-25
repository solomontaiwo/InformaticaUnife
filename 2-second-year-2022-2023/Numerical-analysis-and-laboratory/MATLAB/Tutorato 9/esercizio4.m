close all
clear all
clc

x=linspace(-1,1,11);
t=ones(11);

t(1,:)=1;
t(2,:)=x;

% Formula di ricorrenza è definita come T(i+1)=2xT(i)-T(i-1)
for i=2:10
    t(i+1,:)=2*x.*t(i,:)-t(i-1,:);
end

for i=1:11
    plot(x,t(i,:));
    hold on
    pause
end

legend("Grado 0,","Grado 1", "Grado 2", "Grado 3", "Grado 4", "Grado 5", "Grado 6", "Grado 7", "Grado 8", "Grado 9", "Grado 10");
