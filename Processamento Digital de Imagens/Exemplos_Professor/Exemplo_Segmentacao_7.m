clear all;
clc;

a = imread('Exemplo_Segmentacao_7.png');

figure;
subplot(1,2,1);
imshow(a);
title('Original');

[centers, radii, metric] = imfindcircles(a,[15 50]);

centersStrong5 = centers(1:5,:); 
radiiStrong5 = radii(1:5);
metricStrong5 = metric(1:5);

subplot(1,2,2);
imshow(a);
viscircles(centersStrong5, radiiStrong5,'EdgeColor','b');
title('Circulos Detectados');
