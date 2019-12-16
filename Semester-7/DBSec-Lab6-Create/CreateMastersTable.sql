-- Table: public."Masters"

-- DROP TABLE public."Masters";

CREATE TABLE public."Masters"
(
    "MasterID" integer NOT NULL DEFAULT nextval('"Masters_MasterID_seq"'::regclass),
    "SecondName" character varying(64) COLLATE pg_catalog."default",
    "Speciality" character varying(64) COLLATE pg_catalog."default",
    "WorkExperience" integer,
    CONSTRAINT "MasterID" PRIMARY KEY ("MasterID")
)

TABLESPACE pg_default;

ALTER TABLE public."Masters"
    OWNER to postgres;