SELECT public."Orders".*,
       public."Masters"."SecondName"
    FROM public."Orders"
    INNER JOIN public."Masters" ON public."Orders"."MasterID" = public."Masters"."MasterID";