function [xs , it] = bisezione (fname , a, b, tol)
% BISEZIONE - Metodo di bisezione per radici di equazioni non lineari
% Applica il metodo di bisezione per determinare una approssimazione di
% una radice in [a,b] dell ' equazione non lineare f(x) = 0.
% SYNOPSIS :
% [xs , it] = bisezione (fname , a, b, tol)
% INPUT : fname ( string / fhandle ) - Function o function handle che calacola f(x)
% a, b ( double ) - Estremi dell ' intervallo
% tol ( double ) - Tolleranza di approssimazione della soluzione
% OUTPUT : xs ( double ) - Approssimazione della soluzione
% it ( integer ) - Numero di iterazioni eseguite
%
fa = feval (fname , a); fb = feval (fname , b);
if ( sign (fa)* sign (fb) > 0 )
error ('Intervallo non corretto ');
else
% Metodo di bisezione
maxit = ceil ( log2 ( (b - a)/tol ) );
fprintf ('\nNumero di passi necessari = %d', maxit );
arresto = 0; it = 0;
while ( ~ arresto )
it = it + 1;
xs = a + (b - a) *0.5;
fxs = feval (fname , xs);
if ( fxs == 0 ), break ; end
if ( sign (fxs)* sign (fa) > 0 )
a = xs; fa = fxs ;
else
b = xs; fb=fxs ;
end ;
arresto = ( abs (b - a) < tol ) || ( it == maxit );
end
end
end % fine della function bisezione