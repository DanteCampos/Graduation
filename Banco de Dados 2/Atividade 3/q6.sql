SELECT c.*
FROM consulta c 
WHERE c.data = '1993-04-07'
ORDER BY c.num
LIMIT 3
;

/*Resultado:
  159 | 1993-04-07 |   73 | v4927 | WBIA8252
 2036 | 1993-04-07 |   59 | jD110 | MO956
 2748 | 1993-04-07 |   84 | k1403 | HPEA0400
*/