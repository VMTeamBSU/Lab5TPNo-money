PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS "mainLogin" (
	"ID"	INTEGER UNIQUE,
	"login"	TEXT UNIQUE,
	"password"	TEXT,
	PRIMARY KEY("ID")
);
CREATE TABLE IF NOT EXISTS "flights" (
	"ID"	INTEGER UNIQUE,
	"date"	TEXT,
	"ID_helicopter"	INTEGER,
	"weight_of_goods"	INTEGER,
	"num_of_people"	INTEGER,
	"duration"	INTEGER,
	"price"	INTEGER,
	"special"	TEXT,
	PRIMARY KEY("ID")
);

CREATE TABLE IF NOT EXISTS "helicopter" (
	"name"	TEXT,
	"ID"	INTEGER UNIQUE,
	"data_of_creation"	TEXT,
	"Сapacity"	INTEGER,
	"date_of_repair"	TEXT,
	"flying_resourse"	INTEGER,
	PRIMARY KEY("ID")
);
CREATE TABLE IF NOT EXISTS "LoginStatus" (
	"ID"	INTEGER UNIQUE,
	"status"	INTEGER,
	PRIMARY KEY("ID")
);
CREATE TABLE IF NOT EXISTS "crew" (
	"ID"	INTEGER UNIQUE,
	"position"	TEXT,
	"experiens"	INTEGER,
	"date_of_birth"	TEXT,
	"ID_helicopter"	INTEGER,
	"surname"	INTEGER,
	PRIMARY KEY("ID")
);
COMMIT;
