function SYS = linearize_model(parameters, X0, control)

%Esta funcao eh responsavel por obter um modelo linearizado da dinamica
%longitudinal da aeronave. Tal procedimento eh feito a partir da obtencao
%das derivadas parciais que hão de compor a matriz de evolução de estados
%(A) no modelo em espaço de estados do sistema. 

%As derivadas parciais sao obtidas a partir de sua definicao numerica, ou
%seja, mantendo-se todas as grandezas constantes a menos de uma e
%aplicando uma pertrbacao infinitesimal delta nesta grandeza, obtem-se
%entao o quanto variou o valor da funcao devido a perturbacao infinitesimal
%aplicada.

%Estados na condicao de equilibrio
%  [xv  xv_dot xv_dot2 P1  P2  xp  xp_dot]
Xe=X0;

dt = -1;

%Perturbacao infinitesimal
delta = 1*10^(-4);
delta = [1*10^(-4) 1*10^(-4) 1*10^(-4) 1000 1000 1*10^(-4) 1*10^(-4)];

%% Calculando as matrizes A e B do sistema linearizado
control2 = control;

for i=1:length(X0)
    
    xe = Xe;
    xe(i) = xe(i) + delta(i); 
    apls = dynamics(0,xe,control2,dt,parameters); 
    
    xe=Xe;
    xe(i) = xe(i) - delta(i); 
    amns=dynamics(0,xe,control2,dt,parameters); 
    
    A(:,i)=(apls-amns)/(2*delta(i));
end

control2 = control + delta(i);
apls=dynamics(0,xe,control2,dt,parameters); 

control2 = control - delta(i);
amns=dynamics(0,xe,control2,dt,parameters); 

B(:,1)=(apls-amns)/(2*delta(i));

%% Definindo as matrizes C e D do sistema linearizado
C=[1 0 0 0 0 0 0; 0 0 0 1 -1 0 0; 0 0 0 0 0 1 0];

D=0;

%% Modelo completo do sistema linearizado
SYS = ss(A,B,C,D);
eig(A);