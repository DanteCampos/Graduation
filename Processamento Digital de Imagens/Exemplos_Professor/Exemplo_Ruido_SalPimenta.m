original=imread('Exemplo_Ruidos.jpg');
ruidogauss=imnoise(original, 'salt & pepper');
restaurada=medfilt2(ruidogauss, [3 3]);
diferenca=imsubtract(original, restaurada);

figure; imshow(original); title('Imagem Original');
figure; imshow(ruidogauss); title('Ruido Sal e Pimenta');
figure; imshow(restaurada); title('Imagem Restaurada');
figure; imshow(diferenca); title('Diferenca entre Original e Restaurada');


