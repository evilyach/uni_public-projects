SELECT public."Orders"."OrderID",
       public."Orders"."MasterID",
       public."Orders"."CarID",
       public."Orders"."Date",
       public."Orders"."Service",
       public."Orders"."Price" * 1.1 AS "Price with Overhead"
FROM public."Orders"
WHERE public."Orders"."Service" LIKE 'Покраска'

UNION

SELECT public."Orders"."OrderID",
       public."Orders"."MasterID",
       public."Orders"."CarID",
       public."Orders"."Date",
       public."Orders"."Service",
       public."Orders"."Price" * 1.2 AS "Price with Overhead"
FROM public."Orders"
WHERE public."Orders"."Service" LIKE 'Кузовные работы'

UNION

SELECT public."Orders"."OrderID",
       public."Orders"."MasterID",
       public."Orders"."CarID",
       public."Orders"."Date",
       public."Orders"."Service",
       public."Orders"."Price" * 1.3 AS "Price with Overhead"
FROM public."Orders"
WHERE public."Orders"."Service" LIKE 'Шиномонтаж'

UNION

SELECT *
FROM public."Orders"
WHERE public."Orders"."Service" NOT LIKE 'Покраска' AND
      public."Orders"."Service" NOT LIKE 'Кузовные работы' AND
      public."Orders"."Service" NOT LIKE 'Шиномонтаж'