function [x] = solupper(R,b)
% SOLUPPER - Soluzione di sistema triang. sup. (per righe)
n = length(b);
x = b; % si puo’ evitare con:
x(n) = x(n)/R(n,n); % x(n) = b(n)/R(n,n);
for i = n-1 : -1 : 1 % e poi mettendo
% SDOT - BLAS1 % dentro il ciclo:
x(i) = x(i) - R(i, i+1:n)*x(i+1:n); % x(i) = b(i) - R(i,...
x(i) = x(i)/R(i,i);
end
end