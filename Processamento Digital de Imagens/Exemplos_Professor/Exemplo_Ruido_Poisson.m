original=imread('Exemplo_Ruidos.jpg');
ruidogauss=imnoise(original, 'poisson');
restaurada=medfilt2(ruidogauss, [5 5]);
diferenca=imsubtract(original, restaurada);
figure; imshow(original); title('Imagem Original');
figure; imshow(ruidogauss); title('Ruido Poisson');
figure; imshow(restaurada); title('Imagem Restaurada');
figure; imshow(diferenca); title('Diferenca entre Original e Restaurada');
