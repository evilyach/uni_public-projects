SELECT public."Masters".*,
       public."Orders"."Date"
FROM public."Masters"
LEFT JOIN public."Orders" ON public."Orders"."MasterID" = public."Masters"."MasterID";