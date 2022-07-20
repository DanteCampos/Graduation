img_1 = imread('Exemplo_Add1.png');
img_2 = imread('Exemplo_Add2.png');
img_3 = imread('Exemplo_Add3.png');
img_4 = imread('Exemplo_Add4.png');
img_5 = imread('Exemplo_Add5.png');
img_6 = imread('Exemplo_Add6.png');
img_7 = imread('Exemplo_Add7.png');

figure;
subplot(3,3,1);
imshow(img_1);
title('Original');

hold;

imagem = imadd(img_1,img_2);
subplot(3,3,2);
imshow(imagem);
title('Add + 1');
hold;

imagem = imadd(imagem,img_3);
subplot(3,3,3);
imshow(imagem);
title('Add + 2');
hold;

imagem = imadd(imagem,img_4);
subplot(3,3,4);
imshow(imagem);
title('Add + 3');
hold;

imagem = imadd(imagem,img_5);
subplot(3,3,5);
imshow(imagem);
title('Add + 4');
hold;

imagem = imadd(imagem,img_6);
subplot(3,3,6);
imshow(imagem);
title('Add + 5');
hold;

imagem = imadd(imagem,img_7);
subplot(3,3,7);
imshow(imagem);
title('Add + 6');
hold;
