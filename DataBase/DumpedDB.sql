PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS "mainLogin" (
	"ID"	INTEGER UNIQUE,
	"login"	TEXT UNIQUE,
	"password"	TEXT,
	PRIMARY KEY("ID")
);
INSERT INTO mainLogin VALUES(0,'admin','1111');
INSERT INTO mainLogin VALUES(1,'NewUser','12345');
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
INSERT INTO flights VALUES(1,'2020-02-01',1,12,5,2,5000,'no');
INSERT INTO flights VALUES(2,'2020-02-01',2,20,3,5,12000,'yes');
INSERT INTO flights VALUES(3,'2020-02-02',4,4,8,3,5600,'no');
INSERT INTO flights VALUES(4,'2020-02-04',3,3,3,2,4050,'no');
INSERT INTO flights VALUES(5,'2020-02-05',4,1,7,7,13750,'yes');
INSERT INTO flights VALUES(6,'2020-02-07',1,18,15,4,7000,'no');
INSERT INTO flights VALUES(7,'2020-02-08',2,17,20,10,14000,'yes');
INSERT INTO flights VALUES(8,'2020-02-08',3,1,7,2,4050,'no');
INSERT INTO flights VALUES(9,'2020-02-10',4,3,1,5,5650,'no');
INSERT INTO flights VALUES(10,'2020-02-11',1,13,15,3,7000,'no');
INSERT INTO flights VALUES(11,'2020-02-11',4,3,3,2,5670,'no');
CREATE TABLE IF NOT EXISTS "helicopter" (
	"name"	TEXT,
	"ID"	INTEGER UNIQUE,
	"data_of_creation"	TEXT,
	"п║apacity"	INTEGER,
	"date_of_repair"	TEXT,
	"flying_resourse"	INTEGER,
	PRIMARY KEY("ID")
);
INSERT INTO helicopter VALUES('MI-26',1,'2011-02-23',20,'2020-02-23',1095);
INSERT INTO helicopter VALUES('MI-26',2,'2014-11-11',20,'2020-11-11',1000);
INSERT INTO helicopter VALUES('MI-171',3,'2014-12-09',4,'2020-12-09',1010);
INSERT INTO helicopter VALUES('MI-38',4,'2017-12-09',6,'2020-12-09',1010);
CREATE TABLE IF NOT EXISTS "statusSurname" (
	"ID"	INTEGER UNIQUE,
	"status"	INTEGER,
	PRIMARY KEY("ID")
);
INSERT INTO statusSurname VALUES(0,'admin');
INSERT INTO statusSurname VALUES(1,'member');
CREATE TABLE IF NOT EXISTS "crew" (
	"ID"	INTEGER UNIQUE,
	"position"	TEXT,
	"experiens"	INTEGER,
	"date_of_birth"	TEXT,
	"ID_helicopter"	INTEGER,
	"surname"	INTEGER,
	PRIMARY KEY("ID")
);
INSERT INTO crew VALUES(1,'second pilot',1090,'1985-05-05',1,'Shestopalov');
INSERT INTO crew VALUES(2,'third pilot',900,'1990-10-10',1,'Paloshestov');
INSERT INTO crew VALUES(3,'second pilot',1067,'1991-11-11',2,'Pirsky');
INSERT INTO crew VALUES(4,'third pilot',567,'1992-12-12',2,'Kotletov');
INSERT INTO crew VALUES(5,'second pilot',999,'1989-12-21',3,'Kalinchuk');
INSERT INTO crew VALUES(6,'third pilot',765,'1988-04-13',3,'Opanasenko');
INSERT INTO crew VALUES(7,'second pilot',833,'1990-06-18',4,'Goptev');
INSERT INTO crew VALUES(8,'third pilot',900,'1991-07-13',4,'Kleshev');
INSERT INTO crew VALUES(9,'ллллллллллллллллллллллллллллллллллллллллллллХ',1000,'2000.10.10',4,'dsdsdsd');
INSERT INTO crew VALUES(10,'ллллллллллллллллллллллллллллллллллллллллллллп',2000,'2000.01.01',NULL,'Lihovets');
INSERT INTO crew VALUES(11,'лллллллллллллллллллллллллллллллллллллллллллл═',4000,'2000.10.10',NULL,'Shelkov');
COMMIT;
