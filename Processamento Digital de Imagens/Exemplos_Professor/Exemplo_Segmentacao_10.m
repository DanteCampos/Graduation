clear all;
clc;

%img=imread('Exemplo_Segmentacao_10.jpg');
img=imread('Exemplo_Segmentacao_10B.jpg');

figure;
subplot(2,2,1);
imshow(img);
title('Original');

igray = rgb2gray(img);
filtro = fspecial('average', [9 9]);
igray = imfilter(igray, filtro);

for i = 1:size(igray,1)
    for j = 1:size(igray,2)
        if (igray(i,j) > 130) 
            igray(i,j) = 255;
        else
            igray(i,j) = 0;
        end
    end
end

subplot(2,2,2);
imshow(igray);
title('Pre-Processada');

contador = 0;

for i=10: 10 : (size(igray,1) - 10)
    for j=10: 10 : (size(igray,2) - 10)
        l1 = i-1;
        l2 = i+1;
        c1 = j-1;
        c2 = j+1;
        if (l1 < 1) 
            l1 = 1;
        end
        if (l2 > size(igray,1))
            l2 = size(igray,1);
        end
        if (c1 < 1) 
            c1 = 1;
        end
        if (c2 > size(igray,2))
            c2 = size(igray,2);
        end
                
        flag_contar = 0;
        flag_achou = 1;
        menor_l=l1;
        maior_l=l2;
        menor_c=c1;
        maior_c=c2;
        while (flag_achou == 1)
            flag_achou = 0;
            for i2 = l1 : l2
                for j2 = c1 : c2
                    if ((igray(i2,j2) == 0)  && (igray(i2,j2) <= 15))
                        igray(i2,j2) = 150;
                        if (i2 < menor_l)
                            menor_l = i2;
                        end
                        if (i2 > maior_l)
                            maior_l = i2;
                        end
                        if (j2 < menor_c)
                            menor_c = j2;
                        end
                        if (j2 > maior_c)
                            maior_c = j2;
                        end
                        flag_achou = 1;
                    end
                end
            end
            if (flag_achou == 1)
                flag_contar = 1;
                l1 = menor_l - 1;
                l2 = maior_l + 1;
                c1 = menor_c - 1;
                c2 = maior_c + 1;
            
                if (l1 < 1) 
                    l1 = 2;
                end
                if (l2 > size(igray,1))
                    l2 = size(igray,1);
                end
                if (c1 < 1) 
                    c1 = 1;
                end
                if (c2 > size(igray,2))
                    c2 = size(igray,2);
                end
            else
                break;
            end
        end
        if (flag_contar == 1)
            contador = contador + 1;
        end
    end
end

subplot(2,2,3);
imshow(igray);
title('Segmentada');

texto = sprintf('Pecas encontradas: %d', contador);
display(texto);
