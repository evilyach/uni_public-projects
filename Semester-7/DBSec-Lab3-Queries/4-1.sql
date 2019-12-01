SELECT public."Masters"."Speciality"
FROM public."Masters"
GROUP BY public."Masters"."Speciality"
HAVING COUNT(public."Masters"."MasterID") = 1