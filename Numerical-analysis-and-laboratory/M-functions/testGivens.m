% testGivens: fattorizzazione QR con le rotazioni di Givens
rng(2);
m = 5; n = m; A = rand(m, n+1); Im = eye(m); b = A(:, end); A0 = A(:, 1:n);
Q = Im; 

for jcol = 1 : n
    iriga = find( A( [jcol+1:end], jcol ) )
    if ( ~isempty(iriga) )
        iriga = iriga + jcol;
        for k = 1 : numel(iriga)
            G = Im;
            [G1, y1] = planerot( A( [jcol, iriga(k)], jcol ) );
            G( [jcol, iriga(k)], [jcol, iriga(k)] ) = G1;
            A = G*A; 
            Q = G*Q; 
        end
    end
end
y = A(:,end); A(:,end) = [];
R = triu(A)
Q = Q'


