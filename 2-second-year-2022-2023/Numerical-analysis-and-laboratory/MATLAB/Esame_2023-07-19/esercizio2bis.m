% Cognome Nome
% Matricola
% ------
% Esercizio 2 - Esame Calcolo Numerico del 2023.07.19
% ------

function [z] = esercizio2bis( x, a, c )
% ESERCIZIO2 - Esercizio 2 prova scritta del 2023.07.19
%   Valuta la funzione
%   f(t; a) = c(1) * a^((n-1)*t) + c(2)*a^((n-2)*t) + ... + c(n-1)*a^(t) 
%   + c(n)
%   nel punto x, dove 'a' è un parametro scalare e i coefficienti c(i)
%   sono assegnati, i = 1, ..., n.
% SYNOPSIS
%   [z] = esercizio2( x, a, c )
% INPUT
%   x (double) - Punto in cui valutare la funzione
%   a (double) - Base delle funzioni esponenziali, a > 0
%   c (double array) - Vettore dei coefficienti della comb. lineare 
%                      di funzioni esponenziali.
% OUTPUT
%   z (double array) - Vettore colonna di tre elementi

% Controlli sull'input

if ( isempty(x) || ~isnumeric(x) || ~isscalar(x) )
    error("Il parametro di input 'x' deve essere uno scalare non " + ...
        "vuoto");
end

if ( isempty(a) || ~isnumeric(a) || ~isscalar(a) || a <= 0 )
    error("Il parametro di input 'a' deve essere uno scalare " + ...
        "positivo non vuoto");
end

if ( isempty(c) || any(~isnumeric(c) ) )
    error("Il parametro di input 'c' deve essere un vettore non " + ...
        "vuoto di numeri");
end

% Esecuzione dei calcoli
n = numel(c); c = c(:);
z = zeros(3, 1);

for k = n-1 : -1 : 1
    z(1) = z(1) + c(k) * a^((n-k)*x);
end
y = a^x;
z(2) = polyval(c, y);
z(3) = sum( c(1:(end-1)) .* (a.^([n-1:-1:1]'*x)) ) + c(end);
end
