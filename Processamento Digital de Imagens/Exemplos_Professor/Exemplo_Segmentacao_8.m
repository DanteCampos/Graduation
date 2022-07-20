clear all;
clc;

%im=rgb2gray(imread('Lena.bmp'));
im=rgb2gray(imread('Exemplo_Equalizacao_C.jpg'));
im=im2double(im);

gfilter= [0  0   1  0  0;
          0  1   2  1  0;
          1  2 -16  2  1;
          0  1   2  1  0;
          0  0   1  0  0];
   
smim=conv2(im,gfilter);

[rr,cc]=size(smim);
zc=zeros([rr,cc]);

for i=2:rr-1
    for j=2:cc-1
        if (smim(i,j)>0)
             if (smim(i,j+1)>=0 && smim(i,j-1)<0) || (smim(i,j+1)<0 && smim(i,j-1)>=0)
                zc(i,j)= smim(i,j+1);
            elseif (smim(i+1,j)>=0 && smim(i-1,j)<0) || (smim(i+1,j)<0 && smim(i-1,j)>=0)
                    zc(i,j)= smim(i,j+1);
            elseif (smim(i+1,j+1)>=0 && smim(i-1,j-1)<0) || (smim(i+1,j+1)<0 && smim(i-1,j-1)>=0)
                  zc(i,j)= smim(i,j+1);
            elseif (smim(i-1,j+1)>=0 && smim(i+1,j-1)<0) || (smim(i-1,j+1)<0 && smim(i+1,j-1)>=0)
                  zc(i,j)=smim(i,j+1);
            end
        end
    end
end

otpt=im2uint8(zc);
otptth= otpt>105;

figure;
subplot(2,3,1);
imshow(im);
title('Original');

subplot(2,3,2);
imshow(otptth);
title('Marr-Hildreth');

subplot(2,3,3);
imshow(edge(im,'Roberts'));
title('Roberts');

subplot(2,3,4);
imshow(edge(im,'Canny'));
title('Canny');

subplot(2,3,5);
imshow(edge(im,'Prewitt'));
title('Prewitt');

subplot(2,3,6);
imshow(edge(im,'Sobel'));
title('Sobel');
