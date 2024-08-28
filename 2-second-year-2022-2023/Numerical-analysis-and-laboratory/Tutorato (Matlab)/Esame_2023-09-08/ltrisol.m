function [x] = ltrisol (L, b)
% LTRISOL - Soluzione di sistemi triang . inf. (per colonne )
    n = length (b);
    x = b;
    x(1) = x(1)/L(1 ,1);
    for j = 2:n
        % SAXPY
        x(j:n) = x(j:n) - L(j:n, j -1)*x(j -1);
        x(j) = x(j) / L(j,j);
    end
end