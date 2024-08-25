close all
clear all
clc

A=[15,1,4,6;1,14,-5,-2;4,-5,5,4;6,-2,4,4];
b=[-2,1,0,1]';
[Lchol,flag]=chol(A,'lower');
if (~ flag)
    fprintf('\n Matrice A definita positiva');
    fprintf('\n Fattore di Cholesky:');Lchol
    disp('Soluzione con Cholesky:')
    xs=solupper(Lchol',sollower(Lchol,b))
else
    warning('A non e'' definita positiva\n');
    fprintf('Uso fattorizzazione LU con pivoting parziale\n');
    [Lpar,Upar,ppar]=lu(A,'vector')
    disp('Soluzione con pivoting parziale:');
    xs=solupper(Upar,sollower(Lpar,b(ppar)))
end

xTeoria=[-25/4,-7/2,-24,255/8]';
diffmaxabssol=norm(xs-xTeoria,"inf");
fprintf('\n DIfferenza assoluta massima in modulo nella soluzione:\n');
disp(diffmaxabssol);

%calcolo il residuo
residuo=b-A*xs;
norma=norm(b,"inf");
fprintf('\n Residuo normalizzato:\n');
disp(norm(residuo,"inf")/norma);

%seconda parte uso gauss totale B=[0 A
                                 % A 0]
B=[zeros(size(A)),A;A,zeros(size(A))];
[L_B,R_B,P_B,Q_B]=gauss_pivtot1(B);
deterB=det(B);
%PBQ=LR
absdiff=abs(P_B*B*Q_B-L_B*R_B);
if (any(any(absdiff>eps*norm(B,"inf"))))
    disp('Forte propagazione degli errori');
else
    disp('Fattrizzazione numericamente accettabile');
end
