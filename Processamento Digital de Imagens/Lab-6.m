% Laboratório 6 - Processamento Digital de Imagens
% Daniel Campos da Silva - 201801485

% Para visualizar as questões, basta colocar entre %{ e %} as que deseja ignorar

pkg load image

%{

% Questão 1

x = [53 23 43 55 02 13];
y = [53 23 44 55 02 13];

D = norm(x-y)



% Questão 2

x = [53 23 43 55 02 13];
y = [53 23 44 55 02 13];
z = [
    41 05 04 52 30 33;
    09 39 37 49 43 41;
    36 30 10 11 29 47;
    06 59 42 27 01 05;
    01 19 46 06 16 02;
    19 40 07 13 22 47;
    56 38 21 20 03 05;
    53 17 38 04 47 37;
    55 43 56 54 08 60;
    25 04 18 57 21 38
    ];

min_dist_y = Inf;
min_dist_x = Inf;
min_line_y = 0;
min_line_x = 0;
for i = 1:size(z,1)
    Dx = norm(z(i,:)-x);
    Dy = norm(z(i,:)-y);
    if Dx < min_dist_x
        min_dist_x = Dx;
        min_line_x = i;
    end
    if Dy < min_dist_y
        min_dist_y = Dy;
        min_line_y = i;
    end
endfor

printf("Linha mais próxima de x: %d\n",min_line_x);
printf("Linha mais próxima de y: %d\n",min_line_y);



% Questão 3

load Laboratorio_Imagens/Laboratorio_6_3_X.dat;
nx = numel(Laboratorio_6_3_X)/6; % Número de colunas
X1 = reshape(Laboratorio_6_3_X,6,nx); % Recebe os dados como uma matriz 6 x nx
X = X1.'; % Recebe X1 transposto

y1 = [09 43 37 49 41 39];
y2 = [53 17 38 04 47 37];
y3 = [25 05 19 57 20 38];

for i = 1:size(X,1)
    Dx1 = norm(X(i,:)-y1);
    Dx2 = norm(X(i,:)-y2);
    Dx3 = norm(X(i,:)-y3);
    if Dx1 == 0
        printf("y1 está na linha %d de X\n",i);
    endif
    if Dx2 == 0
        printf("y2 está na linha %d de X\n",i);
    endif
    if Dx3 == 0
        printf("y3 está na linha %d de X\n",i);
    endif
endfor



% Questão 4

load Laboratorio_Imagens/Laboratorio_6_3_Y.dat;
nx = numel(Laboratorio_6_3_Y)/6; % Número de colunas
X1 = reshape(Laboratorio_6_3_Y,6,nx); % Recebe os dados como uma matriz 6 x nx
X = X1.'; % Recebe X1 transposto

y1 = [09 43 37 49 41 39];
y2 = [53 17 38 04 47 37];
y3 = [25 05 19 57 20 38];

for i = 1:size(X,1)
    Dx1 = norm(X(i,:)-y1);
    Dx2 = norm(X(i,:)-y2);
    Dx3 = norm(X(i,:)-y3);
    if Dx1 == 0
        printf("y1 está na linha %d de Y\n",i);
    endif
    if Dx2 == 0
        printf("y2 está na linha %d de Y\n",i);
    endif
    if Dx3 == 0
        printf("y3 está na linha %d de Y\n",i);
    endif
endfor

%}

% Questão 5

load Laboratorio_Imagens/Laboratorio_6_3_X.dat;
nx = numel(Laboratorio_6_3_X)/6; % Número de colunas
X1 = reshape(Laboratorio_6_3_X,6,nx); % Recebe os dados como uma matriz 6 x nx
X = X1.'; % Recebe X1 transposto

load Laboratorio_Imagens/Laboratorio_6_3_Y.dat;
ny = numel(Laboratorio_6_3_Y)/6; % Número de colunas
Y1 = reshape(Laboratorio_6_3_Y,6,ny); % Recebe os dados como uma matriz 6 x ny
Y = Y1.'; % Recebe Y1 transposto

norm(X-Y)