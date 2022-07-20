clear all;
clc;

img_ori = imread('Exemplo_Alargamento.jpg');
img_gray = rgb2gray(img_ori);

figure;
subplot(1,2,1);
imshow(img_ori);
title('Imagem Original');
hold;

cor = 0;
for i = 1:size(img_gray,1)
    for j = 1:size(img_gray,2)
        if ((img_gray(i,j) >= 0) && (img_gray(i,j) < 27))
            cor = 0;
        end
        if ((img_gray(i,j) >= 27) && (img_gray(i,j) < 50))
            cor = 100;
        end
        if ((img_gray(i,j) >= 50) && (img_gray(i,j) < 256))
            cor = 255;
        end
        img_gray(i,j) = cor;
    end
end


subplot(1,2,2);
imshow(img_gray);
title('Imagem com Alargamento de Contraste');
