
SELECT p.*
FROM paciente p 
LEFT JOIN consulta c
USING(nif)
WHERE c.num IS NULL
;

/*Resultado:
 KI582    | Yoshi Randall  Kaufman      | 262-9518 Fringilla St.
 HU026    | Rosalyn Signe  Chan         | Ap #654-110 Iaculis Av.
 PE984    | Katelyn Martina  Foster     | 112-3655 Elementum Ave
 YE838    | Harding Rhiannon  Rojas     | 959-2586 Pulvinar St.
 PE939    | Ila Germaine  Bradshaw      | 885-2581 Erat Street
 DA493    | Jade Stone  Sandoval        | 6802 Est. St.
 KI749    | Devin Avye  Harrison        | 697-5689 Neque Road
 MU169    | Denton Scott  Whitfield     | P.O. Box 918, 3609 Curabitur St.
 MU408    | Savannah Leonard  Lyons     | 3935 Nec Rd.
 SE576    | Aretha Zachary  Mueller     | P.O. Box 802, 815 Neque Avenue
*/