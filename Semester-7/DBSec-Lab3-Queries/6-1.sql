SELECT *
FROM public."Cars"
WHERE public."Cars"."Brand" LIKE 'Л%'

UNION

SELECT *
FROM public."Cars"
WHERE public."Cars"."Brand" LIKE 'И%'

UNION

SELECT *
FROM public."Cars"
WHERE public."Cars"."Brand" LIKE 'М%'