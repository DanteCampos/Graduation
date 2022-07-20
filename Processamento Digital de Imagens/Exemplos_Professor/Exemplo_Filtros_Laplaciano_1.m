original = imread('Exemplo_Filtros_Laplaciano_1.tif');
originalgray = rgb2gray(original);
pesos = [-1 -1 -1; -1 8 -1; -1 -1 -1];
filtro = imfilter(originalgray, pesos);
pontosdetectados = im2bw(filtro);
subplot(1,2,1); imshow(originalgray); title('Original');
subplot(1,2,2); imshow(pontosdetectados); title('Pontos Detectados');

% Ajustes para a Aula de Segmentacao
% Depois de ser visto Morfologia Matem?tica
%se=strel('disk', 5);
%aula_segmentacao=imdilate(pontosdetectados,se);
%figure;
%imshow(aula_segmentacao);
%title('Pontos Identificados - Dilatados');
