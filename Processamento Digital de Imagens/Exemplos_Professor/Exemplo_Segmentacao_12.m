clear all;
clc;

a=imread('Exemplo_Segmentacao_12_Mapa.jpg');
figure;
subplot(2,2,1);
imshow(a);
title('Mapa Original');

b = rgb2gray(a);
c=(im2bw(b, 0.93));
subplot(2,2,2);
imshow(c);
title('Mapa de Quadras');

d=imread('Exemplo_Segmentacao_12_Mask.jpg');
e=im2bw(rgb2gray(d));

f=c-e;
subplot(2,2,3);
imshow(f);
title('Mapa sem as Ruas');

g=imerode(f, strel('square' ,3));
subplot(2,2,4);
imshow(g);
title('Mapa sem as Ruas e Com Separacao dos Imoveis');

%%
% Um novo Exemplo para a Imagem das pe?as de Lego
%%

original = imread('Exemplo_Segmentacao_4.jpg');
azuis = original(:,:,1) < 90;
figure;
subplot(2,2,2);
imshow(azuis);
title('Pecas Azuis');

[B,L] = bwboundaries(azuis, 'noholes');
stats = regionprops(L, 'Area');
qtd_azuis = sum([stats.Area] > 50);
subplot(2,2,1);
imshow(original);
title(sprintf('\\fontsize{12}{Existem %d objetos azuis nessa imagem}', qtd_azuis));

subplot(2,2,3);
hold on
for k = 1:length(B)
    area = stats(k).Area;

    if area > 50
        boundary = B{k};
        plot(boundary(:,2), boundary(:,1), 'black', 'LineWidth', 2);
        text(boundary(1,2), boundary(1,1), sprintf('%.0f',area),...
            'Color', 'white',...
            'FontSize', 12,...
            'FontWeight', 'bold',...
            'BackgroundColor', 'black');
    end
end
title('Apenas os Azuis Detectados');
hold off



