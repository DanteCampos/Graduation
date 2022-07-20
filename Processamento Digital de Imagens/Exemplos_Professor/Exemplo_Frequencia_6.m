clear all;
clc;

ImagemOriginal=imread('Lena.bmp');
ImagemGrayLevel=rgb2gray(ImagemOriginal);
[cA,cH,cV,cD] = dwt2(ImagemGrayLevel,'db1');
figure; imshow(ImagemOriginal); title('Original');
figure; imshow(cA); title('cA');
figure; imshow(cH); title('cH');
figure; imshow(cV); title('cV');
figure; imshow(cD); title('cD');
