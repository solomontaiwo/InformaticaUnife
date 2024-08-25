function [X]=gj(A)
% GJ - Algoritmo di Gauss-Jordan
n = size(A,1);
temp = zeros(1, 2*n);
A = [A eye(n)];
for k = 1 : n
    [amax,ind] = max(abs(A(k:n,k)));
    ind = ind + k - 1;
    if (k ~= ind)
        temp = A(ind, :);
        A(ind, :) = A(k, :);
        A(k, :) = temp;
    end
    A( [1:k-1, k+1:n], k ) = A( [1:k-1, k+1:n], k ) / A(k,k);
    % operazione di base: aggiornamento mediante diadi
    A( [1:k-1, k+1:n], k+1:2*n ) = A( [1:k-1, k+1:n], k+1:2*n )-A( [1:k-1, k+1:n], k ) * A(k, k+1:2*n);

end
X = diag( 1./diag(A(:,1:n)) ) * A(:, n+1:2*n);
end