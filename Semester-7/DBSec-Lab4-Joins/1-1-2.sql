SELECT public."Masters"."SecondName",
       public."Cars"."Brand",
	   public."Orders"."Date",
	   public."Orders"."Price"
	FROM public."Orders"
	INNER JOIN public."Masters" ON public."Orders"."MasterID" = public."Masters"."MasterID"
	INNER JOIN public."Cars" ON public."Orders"."CarID" = public."Cars"."CarID";