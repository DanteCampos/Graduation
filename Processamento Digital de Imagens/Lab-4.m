% Laboratório 4 - Processamento Digital de Imagens
% Daniel Campos da Silva - 201801485

% Para visualizar as questões, basta colocar entre %{ e %} as que deseja ignorar

pkg load image

%{

% Questão 1
img_4_1 = imread("Laboratorio_Imagens/Laboratorio_4_1.tif");
filter_dilatate = [0 1 0; 1 1 1; 0 1 0];
dilated_img_4_1 = imdilate(img_4_1, filter_dilatate);
figure('Name', 'Imagem original'), imshow(img_4_1);
figure('Name', 'Imagem dilatada'), imshow(dilated_img_4_1);
pause()



% Questão 2
img_4_2 = imread("Laboratorio_Imagens/Laboratorio_4_2.png");

figure('Name', 'Imagem original'), imshow(img_4_2);
figure('Name', 'Dilatada com filtro horizontal tamanho 5'), imshow(imdilate(img_4_2, strel("line",5,0)));
figure('Name', 'Dilatada com filtro diagonal tamanho 5'), imshow(imdilate(img_4_2, strel("line",5,45)));
figure('Name', 'Dilatada com filtro horizontal tamanho 11'), imshow(imdilate(img_4_2, strel("line",11,0)));
figure('Name', 'Dilatada com filtro diagonal tamanho 11'), imshow(imdilate(img_4_2, strel("line",11,45)));
figure('Name', 'Dilatada com filtro diamante tamanho 1'), imshow(imdilate(img_4_2, strel("diamond",1)));
figure('Name', 'Dilatada com filtro diamante tamanho 5'), imshow(imdilate(img_4_2, strel("diamond",5)));
figure('Name', 'Dilatada com filtro diamante tamanho 11'), imshow(imdilate(img_4_2, strel("diamond",11)));
pause()



% Questão 3

img_4_3 = imread("Laboratorio_Imagens/Laboratorio_4_3.png");
figure('Name', 'Imagem original'), imshow(img_4_3);
for i = 1:11
    figure('Name', ['Dilatada com filtro disco tamanho ', int2str(i)]), imshow(imdilate(img_4_3, strel("disk",i,0)));
end
pause()



% Questão 4

img_4_4 = imread("Laboratorio_Imagens/Laboratorio_4_4.tif");
figure('Name', 'Imagem original'), imshow(img_4_4);

for i = 5:15
    square_filtered = imopen(img_4_4, strel("square",i));
    square_filtered - imclose(square_filtered, strel("square",i));
    disk_filtered = imopen(img_4_4, strel("disk",i,0));
    disk_filtered - imclose(disk_filtered, strel("disk",i,0));
    figure('Name', ['Arberta e fechada com filtro quadrado tamanho ', int2str(i)]), imshow(square_filtered);
    figure('Name', ['Arberta e fechada com filtro disco tamanho ', int2str(i)]), imshow(disk_filtered);
end

pause()



% Questão 5

img_4_5 = imread("Laboratorio_Imagens/Laboratorio_4_5.tif");
figure('Name', 'Imagem original'), imshow(img_4_5);

square_filtered = imopen(img_4_5, strel("square", 2));
square_filtered = imclose(square_filtered, strel("square", 2));
figure('Name', 'Aberta e fechada com filtro quadrado tamanho 2'), imshow(square_filtered);

disk_filtered = imopen(img_4_5, strel("disk", 2,0));
disk_filtered = imclose(square_filtered, strel("disk", 2,0));
figure('Name', 'Aberta e fechada com filtro disco tamanho 2'), imshow(disk_filtered);
pause()

%}

% Questão 6

img_4_6 = imread("Laboratorio_Imagens/Laboratorio_4_6.tif");
figure('Name', 'Imagem original'), imshow(img_4_6);

opened_img = imerode(img_4_6, strel("square", 3));
opened_img = imerode(opened_img, strel("square", 3));
figure('Name', 'Imagem aberta'), imshow(opened_img);

figure('Name', 'Diferença das imagens'), imshow(imabsdiff(opened_img, img_4_6));
pause()

% A imagem aberta "cresce" e difere principalmente nas bordas
% Portanto, a diferença entre elas denota um claro contorno