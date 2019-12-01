SELECT public."Cars"."Brand",
       COUNT(public."Cars"."Brand") AS "Quantity"
FROM public."Cars"
GROUP BY public."Cars"."Brand"