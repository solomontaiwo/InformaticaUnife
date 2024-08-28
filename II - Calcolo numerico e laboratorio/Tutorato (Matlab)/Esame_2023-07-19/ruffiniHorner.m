function [r, q] = ruffiniHorner(p, a)
% RUFFINIHORNER - Schema di Ruffini -Horner
%   Calcola il valore di un polinomio p(x) nel punto x = a e i coefficienti
%   del polinomio quoziente q(x) = p(x) / (x - a)
% SYNOPSIS
%   [r, q] = ruffiniHorner(p, a)
% INPUT
%   p (double array) - Vettore dei coefficienti del polinomio, ordinati
%                       da quello di grado piu’ alto a quello di grado zero
%   a (double) - Punto (numero reale) in cui calcolare il polinomio
% OUTPUT
%   r (double) - Valore del polinomio nel punto x = a
%   q (double array) - Vettore dei coefficienti del polinomio quoziente
%                       q(x) = p(x) / (x - a)
%

r = [];
if ( isempty(p) )
    q = [];
    warning("Il vettore p dei coefficienti e’ vuoto"); 
    return
elseif ( isempty(a) ) 
    q = p;
    warning("Il punto ’a’ in cui valutare il polinomio e’ vuoto");
    return 
else
    n = numel(p) - 1; % grado del polinomio
    q = zeros(n, 1); q(1) = p(1);
    for i = 2 : n+1
        q(i) = q(i-1)*a + p(i);
    end
    r = q(n+1);
    q = q(1:n);
end
end % fine della function ruffiniHorner