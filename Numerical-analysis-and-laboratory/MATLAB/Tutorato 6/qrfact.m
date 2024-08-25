function [Q, R] = qrfact(A)
% QRFACT - Fattorizzazione QR con rotazioni di Givens
[m, n] = size(A);
r = min(m-1, n);
Q = eye(m);
for i = 1 : r
for j = i+1 : m
if (A(j,i) ~= 0) % ATTENZIONE: meglio usare una soglia...
[c, s] = givensrot(A(i,i), A(j,i));
A([i,j], i:n) = [c s; -s c] * A([i,j], i:n);
Q(:, [i,j]) = Q(:, [i,j]) * [c -s; s c];
end
end
end
R = triu(A);
% elementi diagonali di R non negativi
for i = 1 : min(m,n)
if (R(i,i) < 0)
R(i, i:n) = -R(i, i:n);
Q(:,i) = -Q(:,i);
end
end
end