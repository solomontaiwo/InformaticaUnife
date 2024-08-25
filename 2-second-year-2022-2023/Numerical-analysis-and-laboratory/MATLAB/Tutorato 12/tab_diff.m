function d=tab_diff(x,y);
n=length(x);
d=y;
for i=2:n
d(i:n)=(d(i:n)-d(i-1:n-1))./(x(i:n)-x(1:n-(i-1)));
end;