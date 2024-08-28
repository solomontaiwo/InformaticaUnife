function [x, it] = newton_multipli(fname, fpname, x0, tolx, tolf, maxit,m)
% INPUT: fname (string o fhandle) - Function della funzione
% fpname (string o fhandle) - Function della derivata prima
% x0 (double) - Stima iniziale
% tolx (double) - Distanza minima fra iterati successivi
% tolf (double) - Soglia verso zero dei valori di f(x)
% maxit (integer) - Numero massimo di interazioni
%m (integer) - Valore della molteplicità
% OUTPUT: x (double) - Approssimazione della soluzione
% it (integer) - Numero di iterazioni eseguite
tolfp = min( tolf, 10*eps );
% Metodo di Newton
x = x0; fx = feval(fname, x); it = 0;
stop = ( abs(fx) < tolf );
while ( ~stop )
    it = it + 1;
    fpx = feval(fpname, x);
%     if (abs(fpx) < tolfp), error('|f''(xk)| troppo piccolo.'); end
    d = fx / fpx; x = x - m*d; fx = feval(fname, x);
    stop = ( (abs(fx) < tolf && abs(d) < tolx*abs(x))|| (fx == 0) || (it == maxit) );

end
if ( it >= maxit )
    fprintf('\nRaggiunto il massimo numero di iterazioni.\n');
end
end