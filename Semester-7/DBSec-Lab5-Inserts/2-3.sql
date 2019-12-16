CREATE TABLE "Payments" (
	"MasterID" integer NOT NULL,
	"StateSign" character varying(64) COLLATE pg_catalog."default" NOT NULL,
	"Price" integer NOT NULL
);

INSERT
INTO "Payments"
SELECT "Masters"."MasterID",
      "Cars"."StateSign",
	  "Orders"."Price"
FROM "Orders"
INNER JOIN "Cars" ON "Orders"."CarID" = "Cars"."CarID"
INNER JOIN "Masters" ON "Orders"."MasterID" = "Masters"."MasterID"