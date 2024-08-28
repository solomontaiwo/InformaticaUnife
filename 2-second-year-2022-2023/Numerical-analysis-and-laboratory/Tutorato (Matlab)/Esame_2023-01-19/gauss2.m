function [L, R, p, deter] = gauss2(A)
% GAUSS2 - Fattorizzazione di Gauss con pivoting parziale (versione 2) 
% Esegue la fattorizzazione PA = LR con l’algoritmo di eliminazione di 
% Gauss con pivoting parziale (con aggiornamento mediante diadi)
%
% SYNOPSIS
%  [L, R, p, deter] = gauss2(A)
% INPUT
%   A (double array) - Matrice m x n
% OUTPUT
%   L (double array) - Matrice triangolare inferiore a diagonale unitaria
%   R (double array) - Matrice triangolare/trapezoidale superiore
%   p (double array) - Vettore delle permutazioni di righe
%   deter (double) - determinante (della parte quadrata) di A

[m, n] = size(A); deter = 1; 
temp = zeros(1, n); p = 1 : n;
tol = eps * norm(A, inf); % tolleranza verso lo zero (trascurabilita’) 
for j = 1 : min(m-1,n)
    [amax, ind] = max( abs(A(j:n, j)) );
    ind = ind + j - 1;
    if (ind ~= j) % pivot non in posizione diagonale: occorre scambiare righe
        % scambio di indici
        aux = p(j); p(j) = p(ind); p(ind) = aux; 
        deter = -deter;
        % scambio di righe
        temp = A(ind,:); A(ind,:) = A(j,:); A(j,:) = temp;
    end
    deter = deter * A(j,j); 
    if ( abs(A(j,j)) > tol )
        A(j+1:end, j) = A(j+1:end, j) / A(j,j);
        % operazione di base: aggiornamento mediante diadi
        A(j+1:end, j+1:end) = A(j+1:end, j+1:end) - A(j+1:end, j)*A(j, j+1:end); 
    end
end
deter = deter * A(n,n); 
R = triu(A);
L = eye(n) + tril(A(1:n,1:n), -1); 
end % fine della function gauss2