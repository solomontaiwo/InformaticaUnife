function [x,it]= newton(fname, fpname, x0,tolx, tolf, maxit);
%metodo di Netwon
x=x0;
fx=feval(fname,x);
fprintf('it=%d   x=%g   fx=%g  \n',0,x,fx);
for it=1:maxit
    d=fx/feval(fpname,x);
    x=x-d;
    fx=feval(fname,x);
    fprintf('it=%d   x=%g   fx=%g \n',it,x,fx);
    if (abs(fx)<tolf && abs(d)<tolx*abs(x)) ||fx==0
        break
    end
end
if it>=maxit
    fprintf('Raggiunto il massimo numero di iterazioni\n');
end

    