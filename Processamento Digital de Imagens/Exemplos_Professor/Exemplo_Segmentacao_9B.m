function crescimento = Exemplo_Segmentacao_9B(igray, linha, coluna, rang1, rang2)

l1 = linha-1;
l2 = linha+1;
c1 = coluna-1;
c2 = coluna+1;
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

flag_achou=1;
while (flag_achou == 1)
    flag_achou = 0;
    for l = l1 : l2
        for c = c1 : c2
            if ((igray(l,c) >= rang1) && (igray(l,c) <= rang2))
                igray(l,c) = -1;
                flag_achou = 1;
            end
        end
    end
    if (flag_achou == 1)
        l1 = l1 - 1;
        l2 = l2 + 1;
        c1 = c1 - 1;
        c2 = c2 + 1;
    end
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
end

crescimento = igray;
end