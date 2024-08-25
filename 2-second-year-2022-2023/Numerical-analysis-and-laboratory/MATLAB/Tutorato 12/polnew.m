function [zeta,d]=polnew(x,y,xx);
% Valuta il polinomio di Newton di grado n-1 relativo a (x,y)
% (vettore di dimensione n) in xx;
%xx è a chi voglio fare Pn
n=length(x);
d=tab_diff(x,y); % nelle dispense a pg 12 sono quelli sottolinenati nella tabella
zeta=d(n)*ones(size(xx));
for i=n-1:-1:1
zeta=zeta.*(xx-x(i))+d(i); %nelle dispense a pg 12 è scritto come p4
end;