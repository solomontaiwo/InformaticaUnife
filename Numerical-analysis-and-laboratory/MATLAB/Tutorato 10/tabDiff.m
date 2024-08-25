function [d] = tabDiff(x, y)
% TABDIFF - Tabella delle differenze divise sui nodi x e i valori y
n = length(x);
d = y;
for k = 2 : n
    d(k:n) = ( d(k:n) - d(k-1:n-1) ) ./ ( x(k:n) - x(1:n-k+1) );
end
end