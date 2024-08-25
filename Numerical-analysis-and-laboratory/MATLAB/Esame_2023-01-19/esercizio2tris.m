% Cognome Nome
% Matricola
% ---------
% Esercizio 2 - Esame Calcolo Numerico del 2923.01.19
% --------

function [y] = esercizio2tris( x, params )
% ESERCIZIO2TRIS
%   Valuta la funzione f(t; a, b, c, d) = a*t + b*sqrt( (c+t)/d ) per ogni
%   fissato vettore x di valori
% SYNOPSIS
%   [y] = esercizio2tris( x, params )
% INPUT
%   x (double array) - vettore di valori in cui valutare la funzione
%   params (double array) - vettore di parametri fissati dall'utente
% OUTPUT
%   y (double array) - vettore contenente le valutazioni eseguite

% Controllo dell'input
if ( isempty(x) )
    error("Il vettore x deve essere non vuoto");
elseif ( ~isnumeric(x) )
    error("Il vettore deve contenere valori numerici");
end

if ( isempty(params) )
    warning("Il vettore è vuoto, inserimento parametri " + ...
        "di default");
    params = [0.23 9.45 3 2];
elseif( ~isnumeric(params) )
    error("Il vettore params deve contenere valori numerici");
elseif ( params(4) < 0 )
    warning("Parametro di denominatore minore di 0")
end

x = x(:); params = params(:);

y = ( params(1) * x ) + params(2) * sqrt( ( params(3) + x ) / params(4) );

end