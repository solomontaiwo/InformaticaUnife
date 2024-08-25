% Cognome Nome
% Matricola
% Esercizio 2 - esame del 2023.02.08

function [Y, varargout] = esercizio2(x, c, N)
% ESERCIZIO 2
%   Valuta la funzione
%   f_k(t) = ( c(1)*exp(k*t/2) - c(2) ) / ( c(3) + c(4)*exp(-k*t) )
%   nel punto t = x per tutti i k da 1 a N
% SYNOPSIS
%   [Y[, tempo]] = esercizio2( x, c, N )
% INPUT
%   x (double) - Punto o vettore colonna di punti in cui valutare la
%   funzione f_k(t) per tutti i k da 1 a N
%   c (double array) - Vettore dei coefficienti della funzione, c(3) e c(4) non entrambi nulli
%   N (integer) - Numero di funzioni diverse da valutare (intero positivo maggiore di zero)
% OUTPUT
%   Y (double array) - Vettore riga o matrice di N colonne, contenente i valori di f_k(x) per tutti i k da 1 a N nel/i
%   punto/i x
%   tempo (opzionale) - Se richiesto in output, vettore di due elementi
%                       contenente il tempo di valutazione delle funzioni
%                       f_k(t) in tutti i punti x con sitassi vettoriale
%                       (tempo(1)) e senza sintassi vettoriale (tempo(2))

% Controllo dei parametri di ingresso
if ( (N <= 0) || (N ~= fix(N)) )
    error("Il parametro N deve essere intero positivo"); end 
c = c(:);
if ( (numel(c) ~= 4) || (~isnumeric(c)) )
    error("Il parametro c deve essere un vettore di quattro valori reali"); end 
if ( any(c(3:4) <= 1.0E-4) )
    error("I parametri c(3) e c(4) devono essere entrambi > 1.0E-4"); end

% Calcolo della funzione
x = x(:); n = numel(x); tic;
Y = x * [1:N]; % diade
Y = ( c(1)*exp(0.5*Y) - c(2) ) ./ ( c(3) + c(4)*exp(-Y) ); % Oppure (ma meno efficientemente):
% Y = zeros(n,N);
% for k = 1 : N
% Y(:,k) = ( c(1)*exp(0.5*k*x) - c(2) ) ./ ( c(3) + c(4)*exp(-Y) ); % end
if (nargout == 1), return; end 
tempo(1) = toc; tic;
Y = zeros(n,N);
for k = 1 : N
    for i = 1 : n
        Y(i,k) = ( c(1)*exp(0.5*k*x(i)) - c(2) ) / ( c(3) + c(4)*exp(-k*x(i)) ); 
    end
end
tempo(2) = toc; 
varargout{1} = tempo;
end