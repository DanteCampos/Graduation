SELECT d.*
FROM doenca d
LEFT JOIN diagnosticada g
USING(ref)
WHERE g.ref IS NULL
;

/*Resultado:
    (0 rows)
*/