-- Table: public."Orders"

-- DROP TABLE public."Orders";

CREATE TABLE public."Orders"
(
    "OrderID" integer NOT NULL DEFAULT nextval('"Orders_OrderID_seq"'::regclass),
    "MasterID" integer NOT NULL DEFAULT nextval('"Orders_MasterID_seq"'::regclass),
    "CarID" integer NOT NULL DEFAULT nextval('"Orders_CarID_seq"'::regclass),
    "Date" date NOT NULL,
    "Service" character varying(256) COLLATE pg_catalog."default",
    "Price" integer NOT NULL,
    CONSTRAINT "Orders_pkey" PRIMARY KEY ("OrderID"),
    CONSTRAINT "CarID" FOREIGN KEY ("CarID")
        REFERENCES public."Cars" ("CarID") MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION,
    CONSTRAINT "MasterID" FOREIGN KEY ("MasterID")
        REFERENCES public."Masters" ("MasterID") MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION
)

TABLESPACE pg_default;

ALTER TABLE public."Orders"
    OWNER to postgres;