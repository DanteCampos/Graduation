SELECT m.*
FROM medico m
LEFT JOIN consulta c
USING (bi)
WHERE c.bi IS NULL
;

/*Resultado:
 hE325 | Kristen Petty  | 3073 Lobortis Rd.
 nA797 | Karina Sampson | Ap #205-6292 Purus Av.
 l8F15 | Dillon Lester  | P.O. Box 200, 6449 A, Rd.
*/