SELECT public."Masters"."Speciality"
FROM public."Masters"
WHERE public."Masters"."Speciality" LIKE 'М%'
GROUP BY public."Masters"."Speciality"
HAVING COUNT(public."Masters"."MasterID") = 1