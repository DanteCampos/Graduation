SELECT c.*
FROM medico m
JOIN consulta c
USING (bi)
WHERE m.bi = 'l0093'
ORDER BY c.data ASC
LIMIT 5
;

/*Resultado
   102 | 1959-06-27 |   83 | l0093 | XGEI9585
   791 | 1961-03-09 |   16 | l0093 | ZDOU9774
  3803 | 1962-02-22 |   79 | l0093 | FJEU1433
 12649 | 1962-06-13 |   67 | l0093 | WTII2593
  2563 | 1962-09-18 |   52 | l0093 | BNAU5599
*/