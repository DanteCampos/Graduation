SELECT c.*
FROM consulta c
JOIN medico m
USING(bi)
WHERE EXTRACT(YEAR FROM c.data) = 2005
ORDER BY (m.nome)
;

/*Resultado:
 1570 | 2005-05-15 |   96 | vAE03 | MBAA8814
 2167 | 2005-07-10 |   99 | p8B47 | KQUE0974
 2049 | 2005-11-03 |   39 | x1C95 | FO839
  151 | 2005-03-06 |    1 | p8210 | SZUI9424
  763 | 2005-03-19 |   89 | qFA97 | SMUU2590
 2358 | 2005-02-05 |   41 | cF641 | MTEI4520
  253 | 2005-11-13 |   84 | w2192 | XA685
  450 | 2005-09-04 |   82 | w2192 | ZWOI5913
  756 | 2005-09-06 |   66 | y9F80 | ZRAO4026
 1441 | 2005-03-19 |   38 | pF481 | JA218
 */