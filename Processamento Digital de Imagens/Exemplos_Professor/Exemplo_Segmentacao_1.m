clear all;
clc;

a=imread('Exemplo_Segmentacao_1.bmp');
b=rgb2gray(a);
c=im2bw(b,0.75);
d=b;
for i=1:size(d,1)
    for j=1:size(d,2)
        if (d(i,j) < 50) 
            d(i,j) = 0;
        end
        if ((d(i,j) >= 50) && (d(i,j) < 150))
            d(i,j) = 100;
        end
        if (d(i,j) >= 150)
            d(i,j) = 255;
        end
    end
end

figure;
subplot(2,2,1);
imshow(a);
title('Original');

subplot(2,2,2);
imshow(b);
title('Tons de Cinza');

subplot(2,2,3);
imshow(c);
title('Limiar 75%');

subplot(2,2,4);
imshow(d);
title('Limiar 3 Niveis');

