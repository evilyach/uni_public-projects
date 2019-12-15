SELECT public."Masters".*,
       public."Orders"."Date"
FROM public."Masters"
RIGHT JOIN public."Orders" ON public."Orders"."MasterID" = public."Masters"."MasterID"