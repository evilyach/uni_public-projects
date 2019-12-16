CREATE TABLE "Volga_Orders" (
    "OrderID" integer NOT NULL DEFAULT nextval('"Orders_OrderID_seq"'::regclass),
    "MasterID" integer NOT NULL DEFAULT nextval('"Orders_MasterID_seq"'::regclass),
    "CarID" integer NOT NULL DEFAULT nextval('"Orders_CarID_seq"'::regclass),
    "Date" date NOT NULL,
    "Service" character varying(256) COLLATE pg_catalog."default",
    "Price" integer NOT NULL,

    CONSTRAINT "Volga_Orders_pkey" PRIMARY KEY ("OrderID"),

    CONSTRAINT "CarID" FOREIGN KEY ("CarID")
        REFERENCES public."Cars" ("CarID") MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION,
    CONSTRAINT "MasterID" FOREIGN KEY ("MasterID")
        REFERENCES public."Masters" ("MasterID") MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION
);

INSERT
INTO "Volga_Orders"
SELECT "Orders".*
FROM "Orders"
WHERE "Orders"."CarID" IN (
    SELECT "Cars"."CarID"
    FROM "Cars"
    WHERE "Cars"."Brand" = 'Волга'
);