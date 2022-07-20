clear all;
clc;

img1 = rgb2gray(imread('Exemplo_Frequencia_8.png'));
sobel = fspecial('sobel');
img2 = imfilter(double(img1), sobel, 0, 'conv');

pad = Exemplo_Frequencia_8B(size(img1));
f = fft2(double(img1), pad(1), pad(2));
h = fft2(double(sobel), pad(1), pad(2));
f_fh = h.*f;
ffi = ifft2(f_fh);
ffi = ffi(2:size(f,1), 2:size(f,2));

figure;
imshow(img1);
title('Imagem Original');

figure;
imshow(img2, []);
title('Imagem com Sobel');

figure;
imshow(ffi, []);
title('Imagem com FFT');

