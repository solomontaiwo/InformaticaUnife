% Cognome Nome
% Matricola
% Esercizio 2 - Esame Calcolo Numerico del 2023.02.08

function [Y, varargout] = esercizio2bis( x, c, N )
% ESERCIZIO2BIS
%   Valuta la funzione f_k(t) = ( c(1)*exp(k*t/2) - c(2) ) / ( c(3) + c(4)
%   *exp(-k*x) ) nel punto t = x per tutti i k da 1 a N
% SYNOPSIS
%   [Y[, tempo]] = esercizio2bis( x, c, N )
% INPUT
%   x (array) - vettore in cui valutare la funzione
%   c (double array) - vettore dei coefficienti della funzione
%   N (integer) - numero di funzioni da valutare
% OUTPUT
%   Y (double array) - vettore contenente i valori
%   tempo (opzionale) - vettore di due elementi contenente il tempo di
%                       valutazione

% Controllo dei parametri
if ( (N <= 0) || (N ~= fix(N)) )
    error("Il parametro N deve essere intero positivo"); 
end 
c = c(:);
if ( (numel(c) ~= 4) || (~isnumeric(c)) )
    error("Il parametro c deve essere un vettore di quattro valori reali"); 
end 
if ( any(c(3:4) <= 1.0E-4) )
    error("I parametri c(3) e c(4) devono essere entrambi > 1.0E-4"); 
end

% Calcolo della funzione
x = x(:); n = numel(x); 
tic;
Y = x * [1:N]; % diade
Y = ( c(1)*exp(0.5*Y) - c(2) ) ./ ( c(3) + c(4)*exp(-Y) ); 

if (nargout == 1), return; 
end 

tempo(1) = toc; 

tic;
Y = zeros(n,N);
for k = 1 : N
    for i = 1 : n
        Y(i,k) = ( c(1)*exp(0.5*k*x(i)) - c(2) ) / ( c(3) + ...
            c(4)*exp(-k*x(i)) ); 
    end
end

tempo(2) = toc; 

varargout{1} = tempo;
end