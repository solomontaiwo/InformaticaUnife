function [ x ] = sollower (L , b )
% SOLLOWER - Soluzione di sistema triangolare inferiore non singolare ( per righe )
% SYNOPSIS
% [x] = sollower (L, b)
% INPUT
% L ( double array ) - Matrice triangolare inferiore non singolare
% b ( double array ) - Vettore dei termini noti
% OUTPUT
% x ( double array ) - Vettore soluzione del sistema
%
[m , n ] = size ( L ) ;
if ( m ~= n )
error ('Matrice di coefficienti non quadrata ') ;
elseif ( any( find ( diag ( L ) < eps * norm (L , inf ) ) ) )
error ('Almeno un elemento diagonale di L e'' numericamente troppo piccolo ') ;
else
x = b ;
x (1) = x (1) / L (1 ,1) ;
for i = 2 : n
% SDOT
x ( i ) = x ( i ) - L (i , 1: i -1) * x (1: i -1) ;
x ( i ) = x ( i ) / L (i , i ) ;
end
end
end % fine della function sollower