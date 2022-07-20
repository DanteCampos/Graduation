% img_ori = imread('Exemplo_DetectoresBorda.jpg');
% img_ori = imread('Exemplo_Filtros_PassaBaixa.jpg');
 img_ori = imread('Exemplo_Media_A.bmp');

img_gray = rgb2gray(img_ori);

figure;
imshow(img_gray);
title('Escala de Cinza');

figure;
img_roberts = edge(img_gray,'Roberts');
imshow(img_roberts);
title('Roberts');

figure;
img_canny = edge(img_gray,'Canny');
imshow(img_canny);
title('Canny');

figure;
img_sobel = edge(img_gray,'Sobel');
imshow(img_sobel);
title('Sobel');
