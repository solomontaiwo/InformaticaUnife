function [x] = sollower(L, b)
% SOLLOWER - Soluzione di sistemi triang. inf. (per righe)
n = length(b);
x = b;
x(1) = x(1)/L(1,1);
for i = 2:n
% SDOT
x(i) = x(i) - L(i, 1:i-1)*x(1:i-1);
x(i) = x(i)/L(i,i);
end
end