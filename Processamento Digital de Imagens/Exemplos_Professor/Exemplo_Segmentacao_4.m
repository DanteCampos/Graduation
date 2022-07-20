clear all;
clc;

original = imread('Exemplo_Segmentacao_4.jpg');

azuis = original(:,:,1) < 90;
imshow(azuis);

[B,L] = bwboundaries(azuis, 'noholes');

stats = regionprops(L, 'Area');
qtd_azuis = sum([stats.Area] > 50);

imshow(original);
title(sprintf('Existem %d objetos azuis nessa imagem', qtd_azuis));

hold on
for k = 1:length(B)
    area = stats(k).Area;

    if area > 50
        boundary = B{k};
        plot(boundary(:,2), boundary(:,1), 'black', 'LineWidth', 2);
        text(boundary(1,2), boundary(1,1), sprintf('%.0f',area),...
            'Color', 'white',...
            'FontSize', 10,...
            'FontWeight', 'normal',...
            'BackgroundColor', 'black');
    end
end
hold off