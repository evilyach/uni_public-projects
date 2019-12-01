SELECT public."Cars"."Brand",
       MIN(public."Cars"."Year") AS "Minimal Year"
FROM public."Cars"
WHERE public."Cars"."Brand" LIKE 'М%'
GROUP BY public."Cars"."Brand"