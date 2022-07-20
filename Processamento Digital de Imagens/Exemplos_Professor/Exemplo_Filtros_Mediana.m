img = imread('Exemplo_Filtros_Mediana.png');
subplot(1,3,1);
imshow(img);
title('Imagem Original');

img_noise = rgb2gray(imnoise(img,'salt & pepper',0.02));
subplot(1,3,2);
imshow(img_noise);
title('Com Ruido - Sal e Pimenta');

img_mediana = medfilt2(img_noise);
subplot(1,3,3);
imshow(img_mediana);
title('Filtro Mediana');