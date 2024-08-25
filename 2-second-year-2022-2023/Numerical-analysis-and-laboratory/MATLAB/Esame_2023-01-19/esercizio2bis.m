% Cognome Nome
% Matricola
% ---------
% Esercizio 2 - Esame Calcolo Numerico del 2023.01.19
% ---------

function [y] = esercizio2bis( x, params )
% ESERCIZIO2BIS
%   Valuta la funzione f(t; a,b,c,d) = a*t + b*sqrt( (c + t) / d )
%   nel punto x, per fissati valori dei parametri reali 'a', 'b', 'c' e
%   'd'.
%   Versione con controlli sull'input e parametri potenzialmente
%   vettoriali)
% SYNOPSIS
%   y = esercizio2bis( x, params ) 
% INPUT
%   x (double array)    -   Vettore di valori nei quali valutare la
%                           funzione f(t)
%   params (double array)   Vettore dei parametri: params(1) = a, params(2)
%                           = b, params(3) = c, params(4) = d
% OUTPUT
%   y (double array)    -   Vettore dei valori della funzione f(t) nei
%                           punti x
%

% Controllo degli input

if ( isempty(x) )
    error("Il vettore x deve essere non vuoto")
end

if ( isempty(params) )
    warning("Il vettore params deve essere non vuoto, " + ...
        "assegnazione valori di default...");   
    params = [0.23 9.45 3 2];
end

if ( ~isnumeric(x) )
    error("Il vettore x deve contenere valori numerici");
end

if ( ~isnumeric(params) )
    error("Il vettore params deve contenere valori numerici");
end

if ( params(4) < eps )
    error("Il quarto parametro è numericamente troppo piccolo");
end

% Caloclo della funzione

x = x(:); params = params(:);

y = params(1)*x + params(2)*sqrt( (params(3)+x) / params(4) );

end



