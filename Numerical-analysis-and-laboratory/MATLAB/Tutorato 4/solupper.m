function [ x ] = solupper (R , b )
% SOLUPPER - Soluzione di sistema triangolare superiore non singolare ( per righe )
% SYNOPSIS
% [x] = solupper (R, b)
% INPUT
% R ( double array ) - Matrice triangolare superiore non singolare
% b ( double array ) - Vettore dei termini noti
% OUTPUT
% x ( double array ) - Vettore soluzione del sistema
%
[m , n ] = size ( R ) ;
if ( m ~= n )
error ('Matrice di coefficienti non quadrata ') ;
elseif ( any( find ( abs( diag ( R ) ) < eps * norm (R , inf ) ) ) )
error ('Almeno un elemento diagonale di R e'' numericamente troppo piccolo ') ;
else
x = b ;
x ( n ) = x ( n ) / R (n , n ) ;
for i = n -1 : -1 : 1
% SDOT - BLAS1
x ( i ) = x ( i ) - R (i , i +1: n ) * x ( i +1: n ) ;
x ( i ) = x ( i ) / R (i , i ) ;
end
end
end