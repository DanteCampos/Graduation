clear;
clc;

img = imread ('Exemplo_Textura_1.png');
gray = rgb2gray(img);

figure; imshow(img); title('Imagem Original');
figure; imshow(gray);  title('Imagem Tons de Cinza');

figure;
mata1 = gray(1100:1200, 890:990);
glcm_mata1 = graycomatrix(mata1);
stats_mata1 = graycoprops(glcm_mata1);
str_mata1 = sprintf('Mata1 - Contraste:%f ; Correlacao:%f ; Energia:%f ; Homogeneidade:%f', stats_mata1.Contrast, stats_mata1.Correlation, stats_mata1.Energy, stats_mata1.Homogeneity);
subplot(2,3,1); imshow(mata1); title({'Mata Proximo a Turtle Pound';'1100:1200 - 890:990'});

mata2 = gray(60:160, 1470:1570);
glcm_mata2 = graycomatrix(mata2);
stats_mata2 = graycoprops(glcm_mata2);
str_mata2 = sprintf('Mata2 - Contraste:%f ; Correlacao:%f ; Energia:%f ; Homogeneidade:%f', stats_mata2.Contrast, stats_mata2.Correlation, stats_mata2.Energy, stats_mata2.Homogeneity);
subplot(2,3,2); imshow(mata2); title({'Mata Proximo a The Pool';'60:160 - 1470:1570'});

lago = gray(520:620, 1270:1370);
glcm_lago = graycomatrix(lago);
stats_lago = graycoprops(glcm_lago);
str_lago = sprintf('Lago - Contraste:%f ; Correlacao:%f ; Energia:%f ; Homogeneidade:%f', stats_lago.Contrast, stats_lago.Correlation, stats_lago.Energy, stats_lago.Homogeneity);
subplot(2,3,3); imshow(lago); title({'Lago';'520:620 - 1270:1370'});

city1 = gray(420:520, 570:670);
glcm_city1 = graycomatrix(city1);
stats_city1 = graycoprops(glcm_city1);
str_city1 = sprintf('Cid1 - Contraste:%f ; Correlacao:%f ; Energia:%f ; Homogeneidade:%f', stats_city1.Contrast, stats_city1.Correlation, stats_city1.Energy, stats_city1.Homogeneity);
subplot(2,3,4); imshow(city1); title({'Cidade - Esquerda do Lago';'420:520 - 570:670'});

city2 = gray(720:820, 570:670);
glcm_city2 = graycomatrix(city2);
stats_city2 = graycoprops(glcm_city2);
str_city2 = sprintf('Cid2 - Contraste:%f ; Correlacao:%f ; Energia:%f ; Homogeneidade:%f', stats_city2.Contrast, stats_city2.Correlation, stats_city2.Energy, stats_city2.Homogeneity);
subplot(2,3,5); imshow(city2); title({'Cidade - Direita do Lago';'720:820 - 570:670'});

rio = gray(330:430, 240:340);
glcm_rio = graycomatrix(rio);
stats_rio = graycoprops(glcm_rio);
str_rio = sprintf('Rio - Contraste:%f ; Correlacao:%f ; Energia:%f ; Homogeneidade:%f', stats_rio.Contrast, stats_rio.Correlation, stats_rio.Energy, stats_rio.Homogeneity);
subplot(2,3,6); imshow(rio); title({'Rio';'330:430 - 240:340'});

display(str_mata2, str_mata1);
display(str_city2, str_city1);
display(str_lago, str_rio);
