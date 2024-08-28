% Cognome Nome
% Matricola
function [y] = esercizio2(x, params)
% ESERCIZIO2 - Esercizio 2 prova scritta di calcolo numerico del 19/01/2023
% Valuta la funzione
% descrizione 1
% descrizione 2
% descrizione 3
% descrizione 4
% SYNOPSIS
%   bla bla bla
% INPUT
%   bla bla bla
%   bla bla bla
% OUTPUT
%   bla bla bla

    % Controlli sui parametri di input
    if (isempty(x))
        error("Il vettore delle ascisse deve essere non vuoto");
    elseif (~isnumeric(x))
        error("Le ascisse devono essere numeri reali")
    end

    if (isempty(params))
        warning(sprintf("%s\n%s\n", ...
            "Paramentri non forniti: si assumono valori di default:", ...
            "a = 2, b = 0.4, c = 3, d = -1.2"));
        params = [0.23, 9.45, 3, 2];
    elseif (~isnumeric(params))
        error("Non sono ammessi parametri non numerici");
    elseif(abs(params(4)) < eps)
        warning("Quarto parametro numericamente troppo piccolo");
    end

    x = x(:); params = params(:);
    idxZeroDenom = find(params(3) + x < 0);
    if (~isempty(idxZeroDenom))
        warning("Presenza di radicandi negativi");
    end

    % Calcolo dei valori della funzione nelle ascisse x
    y = params(1)*x + params(2)*sqrt((params(3) + x) / params(4));
