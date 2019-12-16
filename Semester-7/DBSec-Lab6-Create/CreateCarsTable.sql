-- Table: public."Cars"

-- DROP TABLE public."Cars";

CREATE TABLE public."Cars"
(
    "CarID" integer NOT NULL DEFAULT nextval('"Cars_CarID_seq"'::regclass),
    "StateSign" character varying(64) COLLATE pg_catalog."default" NOT NULL,
    "Brand" character varying(64) COLLATE pg_catalog."default" NOT NULL,
    "Color" character varying(64) COLLATE pg_catalog."default" NOT NULL,
    "Year" integer NOT NULL,
    CONSTRAINT "CarID" PRIMARY KEY ("CarID")
)

TABLESPACE pg_default;

ALTER TABLE public."Cars"
    OWNER to postgres;