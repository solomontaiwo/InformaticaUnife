% Cognome Nome
% Matricola
% -----
% Esercizio 2 - Esame Calcolo Numerico del 2023.09.08
% -----

function [y] = esercizio2( x, params )
% ESERCIZIO2 - Esercizio 2 esame scritto di Calcolo Numerico del 2023.09.08
%   Valuta la funzione
%   f(t; a,b,c,d) = a * cos( b*t ) ./ ( log( t / c ) - 5^( d * t ) )
%   nel punto x, per fissati valori dei parametri reali 'a', 'b', 'c', 'd'.
% SYNOPSIS
%   y = esercizio2( x, params )
% INPUT
%   x (double array) - Vettore di valori in cui valutare f(t)
%   params (double array) - Vettore dei parametri della funzione f(t)
% OUTPUT
%   y (double array) - Vettore dei valori della funzione f(t) nei punti x

y = params(1) * cos( params(2) * x ) ./ ( log( x/params(3) ) ... 
    - 5.^( params(4)*x) );
end