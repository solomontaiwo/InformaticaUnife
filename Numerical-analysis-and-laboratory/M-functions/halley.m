function [x,it]= halley(fname, fpname, fsname,x0,tolx, tolf, maxit);
%metodo di Halley
x=x0;
fx=feval(fname,x);
%fprintf('it=%d   x=%g   fx=%g  \n',0,x,fx);
for it=1:maxit
    f1=feval(fpname,x);
    num=fx/f1;
    f2=feval(fsname,x);
    d=num/(1-num*f2/f1);
    x=x-d;
    fx=feval(fname,x);
    %fprintf('it=%d   x=%g   fx=%g \n',it,x,fx);
    if (abs(fx)<tolf && abs(d)<tolx*abs(x)) ||fx==0
        break
    end
end
if it>=maxit
    fprintf('Raggiunto il massimo numero di iterazioni\n');
end

    