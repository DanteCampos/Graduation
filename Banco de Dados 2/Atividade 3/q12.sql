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