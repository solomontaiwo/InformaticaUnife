function [c, s] = givensrot(x1,x2)
% GIVENSROT - Rotazione elementare di Givens
% si determinano c ed s tali da annullare l’elemento y2
if (x2 == 0)
c = 1; s = 0;
else
if (abs(x2) >= abs(x1))
t = x1/x2; s = 1/sqrt(1+t^2); c = s*t;
else
t = x2/x1; c = 1/sqrt(1+t^2); s = t*c;
end
end
end