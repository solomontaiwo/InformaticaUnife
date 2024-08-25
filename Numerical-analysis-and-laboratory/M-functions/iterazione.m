function [x, it] = iterazione(gname, x0, tol, maxit)
% Metodo di iterazione funzionale (con visualizz. delle iterate)
% INPUT: gname (string/fhandle) - Function per funz. d’iterazione
% x0 (double) - Iterato iniziale
% tol (double) - Tolleranza per l’arresto
% maxit (integer) - Numero massimo di iterazioni
% OUTPUT: x (double) - Approssimazione della soluzione
% it (integer) - Numero di iterazioni eseguite
maxX = 1.0e100; % soglia per la divergenza della successione
it = 0; x = feval(gname, x0);
stop = ( abs(x - x0) <= tol + eps*abs(x0) || abs(x) >= maxX );
while ( ~stop )
    it = it + 1;
    x0 = x;
    x = feval(gname, x);
    fprintf('\nit = %d \tx = %g \tx0 = %g', it, x, x0);
    stop = ( abs(x - x0) <= tol + eps*abs(x0) || it == maxit || abs(x) >= maxX );

end
if ( it == maxit )
    fprintf('\nRaggiunto il limite massimo di iterazioni.\n');
elseif ( abs(x) >= maxX )
    fprintf('\nSuccessione numericamente divergente.\n');
end
end