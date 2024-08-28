function [STR]=conv10toBETA_int(ALPHA,BETA)

if(~isnumeric(ALPHA) || (ALPHA~=fix(ALPHA)) || (ALPHA<0))
    error('ALPHA deve essere un numero decimale positivo');
end

if(~isnumeric(BETA) || BETA~=fix(BETA) || (BETA<2) || (BETA>36))
    error('BETA deve essere un numero intero positivo fra 2 e 36');
end

d=char([double('0'):double('9'),double('A'):double('Z')]);

%algoritmo delle divisioni successive
q=ALPHA;
STR='';
while(q~=0)
    r=q-fix(q/BETA)*BETA;
    q=fix(q/BETA);
    STR=strcat(d(r+1),STR);
end

