% Cognome Nome
% Matricola
% ---------
% Esercizio 3 - Esame Calcolo Numerico del 2023.02.08
% ---------

function [rango, deter, normaInf] = miaDiade( r, s )
% MIADIADE - Function esercizio 3 prova di Calcolo Num. del 2023.02.08
%   Calcolo la diade r*s' e ne ricava rango, determinante e norma infinito.
% SYNOPSIS
%   [rango, deter, normaInf] = miaDiade( r, s )
% INPUT
%   r, s    (double vectors) - Vettori di numeri reali
% OUTPUT
%   rango       (integer) - Rango numerico della diade
%   deter       (double) -  Determinante della diade
%   normaInf    (double) -  Norma infinito della diade

    if ( isempty(r) || isempty(s) )
        error("I due vettori di input devono essere non vuoti");
    elseif ( ~isvector(r) || ~isvector(s) )
        warning("Array in input non vettori colonna: trasformati " + ...
            "in vettori colonna");
    end    
    r = r(:); s = s(:);
    A = r*s'; [m, n] = size(A);
    [Q, R] = qr(A);
    diagonaleR = diag(R);
    normaInf = norm(A, inf);
    % rango = numel( find(abs(diagonaleR) > eps*normaInf) );
    rango = rank(A);
    deter = prod( diagonaleR );
end