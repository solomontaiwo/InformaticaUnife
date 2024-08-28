function [x,it,xm]=secante(fname, x0,x1,tolx,tolf,maxit)
% METODO DELLA SECANTE
% x: approssimazione della soluzione
% it: numero di passi
xm(1)=x0;
xm(2)=x1;
  con=2;

fx0=feval(fname,x0);
fx1=feval(fname,x1);
for it=1:maxit
    con=con+1;
    t=fx0/fx1;
    d=(x1-x0)/(1-t);
    x=x1-d;
    xm(con)=x;
    fx=feval(fname,x);
    % test di fine calcolo
        if abs(fx)<=tolf & abs(d)<=tolx*abs(x) | fx==0
            break
end
    x0=x1;
    x1=x;
    fx0=fx1;
    fx1=fx;
end
if it>=maxit
    fprintf('Raggiunto il massimo numero di iterazioni \n');
end

