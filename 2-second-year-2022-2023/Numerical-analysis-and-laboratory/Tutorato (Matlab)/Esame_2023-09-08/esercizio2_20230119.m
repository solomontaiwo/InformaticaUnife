% Cognome Nome
% Matricola
% ---------
% Esercizio 2 - Esame del 20230119
% ---------

function [y] = esercizio2_20230119(x, params)
% ESERCIZIO2
% Valuta bla bla bla
%   f(
% SYNOPSIS
%   y = esercizio2_20230119(x, params)
% OUTPUT
%   y (double array) - vettore con risultati
% INPUT
%   x (double array) - vettore dei valori da valutare
%   params (double array) - vettore dei parametri

% Controlli sui parametri di input

if ( isempty(x) )
    error("x deve essere un vettore non vuoto")
end

if ( isempty(params) )
    warning("params è vuoto, impostazione valori di default");
    params(1) = 0.23; params(2) = 9.45; params(3) = 3; params(4) = 2;
end

if ( ~isnumeric(x) || ~isnumeric(params) )
    error("x e params devono contenere valori numerici");
end

x = x(:); params = params(:);
idxZeroDenom = find( params(3) + x < 0 );

if ( ~isempty(idxZeroDenom) )
    warning("Presenza di radicandi negativi");
end

y = (params(1) * x) + params(2) * sqrt( (params(3) + x) / params(4) );

end