SELECT s1."CarID"
FROM "Orders" s1, "Orders" s2
WHERE s1."CarID" = s2."CarID" AND
      s1."MasterID" = 1 AND
      s2."MasterID" = 3
GROUP BY s1."CarID"