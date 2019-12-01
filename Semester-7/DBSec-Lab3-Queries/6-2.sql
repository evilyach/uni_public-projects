SELECT public."Cars"."CarID",
       public."Cars"."StateSign",
	   public."Cars"."Brand",
	   public."Cars"."Color",
	   public."Cars"."Year"
FROM public."Cars"
WHERE public."Cars"."Color" IS NOT NULL

UNION

SELECT public."Cars"."CarID",
       public."Cars"."StateSign",
	   public."Cars"."Brand",
	   'не указан',
	   public."Cars"."Year"
FROM public."Cars"
WHERE public."Cars"."Color" IS NULL