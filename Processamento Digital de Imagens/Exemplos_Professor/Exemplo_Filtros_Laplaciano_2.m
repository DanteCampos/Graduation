original = imread('Exemplo_Filtros_Laplaciano_2.tif');
% pesos = [ -1 2 -1; -1 2 -1; -1 2 -1]; % Verticais
% pesos = [ 2 -1 -1; -1 2 -1; -1 -1 2]; % -45
% pesos = [ -1 -1 2; -1 2 -1; 2 -1 -1]; % +45
 pesos = [ -1 -1 -1; 2 2 2; -1 -1 -1]; % Horizontais
% pesos = [ -3 -3 -3; 6 6 6; -3 -3 -3]; % Horizontais
filtrada = imfilter(double(original),pesos);
T = max(filtrada(:));
filtrada = filtrada>=T-40;
figure; subplot(1,2,1); imshow(original, []); title('Original');
hold; subplot(1,2,2); imshow(filtrada); title('Filtrada');
