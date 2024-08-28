% Cognome Nome
% Numero Matricola
function [z] = esercizio2(x, a, c)
% ESERCIZIO 2 - Esercizio prova scritta di calcolo numerico del 19/07/2023
%   Valuta la funzione
%    f_a(t) = c(1)*a^(n-1)*t) + c(2)^(n-2)*t) + ... + c(n-1)*a^(t) + c(n)
%    nel punto x, vode 'a' e' un parametro scalaere ed i coefficienti c(i)
%    sono assegnati, i = 1, ..., n.
% SYNOPSIS
%   [z] = esercizio2(x, a, c)
% INPUT
%   x (double)        - Punto nel quale valutare la funzione f_a(t)
%   a (double)        - Base delle funzioni esponenziali, a > 0
%   c (double array)  - Vettore dei coefficienti della combinazione lineare
%                      di funzioni esponenziali
%                      [Non espressamente richiesto, ma molto opportuno]
% OUTPUT
%   z (double array)  - Vettore colonna di tre elementi, tale che:
%                       z(1) = valutazione di f_a(x) con un ciclo for
%                       z(2) = valutazione di f_a(x) con polyval
%                       z(3) = valutazione di f_a(x) con operazioni vettoriali

% Controlli sull'input
if (isempty(x) || ~isnumeric(x) || ~isscalar(x))
    error("Il parametro di input 'x' deve essere uno scalare non vuoto");
end

if (isempty(a) || ~isnumeric(a) || ~isscalar(a) || (a <= 0))
    error("Il parametro di input 'a' deve essere uno scalare positivo non vuoto");
end

if (isempty(c) || any(~isnumeric(c)))
    error("Il parametro di input 'c' deve essere un vettore non vuoto di numeri");
end

% Esecuzione dei valcolo
n = numel(c); c = c(:);
z = zeros(3, 1);
z(1) = c(end);

for k = n-1 : -1 : 1
    z(1) = z(1) + c(k) * a^((n-k)*x);
end
y = a^x;
z(2) = polyval(c, y);
z(3) = sum(c(1:(end-1)) .* (a.^([n-1: -1:1]'*x))) + c(end);
end
