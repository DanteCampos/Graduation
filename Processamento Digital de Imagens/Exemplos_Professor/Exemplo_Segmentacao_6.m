clear all;
clc;

a=imread('Exemplo_Segmentacao_6B.png'); 

figure;
subplot(1,2,1);
imshow(a);
title('Original');

Rmin = 30;
Rmax = 65;

subplot(1,2,2);
imshow(a);
[centersBright, radiiBright] = imfindcircles(a,[Rmin Rmax],'ObjectPolarity','bright');
[centersDark, radiiDark] = imfindcircles(a,[Rmin Rmax],'ObjectPolarity','dark');
viscircles(centersBright, radiiBright,'Color','b');
viscircles(centersDark, radiiDark,'LineStyle','--');
title('Deteccao de Circulos');
