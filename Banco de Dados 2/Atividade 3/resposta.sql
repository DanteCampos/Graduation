-- Questão 1

SELECT c
FROM consulta c
INNER JOIN paciente p
ON p.nif = c.nif
WHERE p.nif = 'KNEU7061'
;

/* Resultado:
(101,1998-11-17,89,pE370,KNEU7061)
(1111,1959-10-24,88,l0104,KNEU7061)
(1852,1988-03-28,95,tAF89,KNEU7061)
(2993,1990-02-19,87,tF567,KNEU7061)
(5013,1982-11-09,68,tC940,KNEU7061)
(6450,1986-03-15,69,kDA23,KNEU7061)
(6611,1989-07-25,15,nA587,KNEU7061)
(6801,1984-01-26,23,l0093,KNEU7061)
(7230,2003-10-03,76,g5595,KNEU7061)
(7275,1999-08-02,66,k5D97,KNEU7061)
*/

-- Questão 2

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

-- Questão 3

SELECT *
FROM consulta c
WHERE EXTRACT(YEAR FROM c.data) = 2007
;

/*Resultado:
  117 | 2007-06-09 |   83 | bDC30 | YKIA4180
  203 | 2007-10-19 |   70 | j5674 | QBIE5866
  228 | 2007-12-22 |   62 | n2E03 | KI389
  248 | 2007-09-28 |   36 | v2052 | YNIU5533
  259 | 2007-03-26 |   19 | p8B47 | YGIU2414
  305 | 2007-02-20 |   47 | gBD60 | KTOO2835
  405 | 2007-04-03 |   48 | wF789 | HLUA7275
  452 | 2007-02-15 |   11 | rB606 | TCOI9443
  463 | 2007-12-07 |   47 | wF789 | RO035
  518 | 2007-12-08 |   31 | y7F55 | PTIA0898
*/

-- Questão 4

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

-- Questão 5

SELECT c.*
FROM consulta c
JOIN medico m 
USING(bi)
WHERE EXTRACT(MONTH FROM c.data) = 10
ORDER BY m.nome, c.data
;

/*Resultado:
  9790 | 1963-10-06 |   16 | vAE03 | DA754
  8883 | 1965-10-20 |   46 | vAE03 | CHOU4929
  2893 | 1966-10-27 |   96 | vAE03 | PI610
 11596 | 1968-10-09 |   80 | vAE03 | XQOU3467
  5786 | 1969-10-02 |   89 | vAE03 | QREO9261
  2759 | 1983-10-09 |   85 | vAE03 | LYIA9645
  8040 | 1988-10-24 |   83 | vAE03 | TROO9880
  9686 | 1995-10-16 |   21 | vAE03 | WBIE8674
  6765 | 1995-10-17 |   17 | vAE03 | VXOI3742
  4418 | 1999-10-06 |   41 | vAE03 | RZIA1719
*/

-- Questão 6

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

-- Questão 7

SELECT c.*
FROM consulta c
WHERE c.data = '1993-04-07'
ORDER BY c.num
LIMIT 4
OFFSET 3
;

/*Resultado:
  7007 | 1993-04-07 |   46 | g5595 | SBUA3402
 11444 | 1993-04-07 |   40 | k5D97 | WQII2464
 12055 | 1993-04-07 |   68 | jBA46 | RLUU6862
 13961 | 1993-04-07 |   43 | z2615 | QKIO7136
*/

-- Questão 8


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

-- Questão 9

SELECT c.*
FROM consulta c 
LEFT JOIN diagnosticada d
USING(num)
WHERE d.num IS NULL
;

/*Resultado:
   103 | 1976-07-26 |   47 | f0447 | YQEI3167
   108 | 2003-12-08 |    2 | h9F20 | BE215
   119 | 1986-03-26 |   23 | y7F55 | PFEO4156
   126 | 1972-08-07 |   89 | n2E03 | CTAA3688
   130 | 1973-08-27 |   11 | c1C19 | TTEA4893
   134 | 1985-12-10 |   31 | qDB93 | WVOU9502
   137 | 1960-01-01 |   41 | rB606 | TNUO3914
   141 | 2001-07-11 |   19 | m6224 | FSAU2330
   142 | 1988-03-25 |   41 | p8B47 | PBAO4763
   145 | 1994-04-09 |   23 | zDB43 | PJAA8376
*/

-- Questão 10

SELECT d.*
FROM doenca d
LEFT JOIN diagnosticada g
USING(ref)
WHERE g.ref IS NULL
;

/*Resultado:
    (0 rows)
*/

-- Questão 11

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

-- Questão 12

SELECT
    EXTRACT(YEAR FROM c.data) AS ano,
    COUNT(*) AS quantConsultasAno
FROM consulta c
GROUP BY EXTRACT(YEAR FROM c.data)
ORDER BY EXTRACT(YEAR FROM c.data) DESC
;

/*Resultado:
 2014 |                29
 2013 |                51
 2012 |                49
 2011 |                33
 2010 |                38
 2009 |                43
 2008 |                47
 2007 |                39
 2006 |                26
 2005 |                51
*/