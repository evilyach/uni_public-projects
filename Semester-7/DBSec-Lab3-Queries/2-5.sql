SELECT *
FROM public."Cars"
WHERE public."Cars"."Brand" LIKE 'Л%' OR
      public."Cars"."Brand" LIKE 'И%' OR
      public."Cars"."Brand" LIKE 'М%'