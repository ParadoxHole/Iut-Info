CREATE TABLE NATIONALITE (
  num_nationalité NUMERIC (5) PRIMARY KEY NOT NULL,
  libelle VARCHAR2(50) NOT NULL);

CREATE TABLE EQUIPE (
  num_equipe NUMERIC(5) PRIMARY KEY NOT NULL,
  nom VARCHAR2(20) NOT NULL,
  capaciteStade NUMERIC (5) NOT NULL CHECK ( capaciteStade>0 AND capaciteStade<80000),
  budget NUMERIC (5) NOT NULL CHECK ( budget >0));

CREATE TABLE COMPETITION (
  num_comp NUMERIC (5) PRIMARY KEY NOT NULL,
  nom VARCHAR2(20) NOT NULL,
  type_comp VARCHAR2(20) NOT NULL);
  
CREATE TABLE JOUEUR (
  num_joueur NUMERIC(5) PRIMARY KEY NOT NULL,
  nom VARCHAR2(20) NOT NULL,
  prenom VARCHAR2(20) NOT NULL,
  age NUMERIC (5) NOT NULL CHECK ( age >10 and age <40),
  num_nationalité NUMERIC(5),
  nbSelect NUMERIC (3) NOT NULL CHECK ( nbSelect >=0),
  activite NUMERIC (1) NOT NULL,
  FOREIGN KEY (num_nationalité) REFERENCES NATIONALITE (num_nationalité));
  
CREATE TABLE APPARTENIR (
  numJoueur NUMERIC (5) NOT NULL ,
  numEquipe NUMERIC (5) NOT NULL ,
  dateDeb Date NOT NULL,
  dateFin Date NOT NULL,
  Poste Varchar2(50),
  numMaillot NUMERIC(3) NOT NULL,
  PRIMARY KEY (numJoueur, numEquipe, dateDeb),
  FOREIGN KEY (numJoueur) REFERENCES JOUEUR (num_joueur),
  FOREIGN KEY (numEquipe) REFERENCES EQUIPE (num_equipe));

CREATE TABLE PRETER (
  numJoueur NUMERIC (5) NOT NULL ,
  numEquipe NUMERIC (5) NOT NULL ,
  dateDeb Date NOT NULL,
  dateFin Date NOT NULL,
  Poste Varchar2(50),
  numMaillot NUMERIC(3) NOT NULL,
  PRIMARY KEY (numJoueur, numEquipe, dateDeb),
  FOREIGN KEY (numJoueur) REFERENCES JOUEUR (num_joueur),
  FOREIGN KEY (numJoueur) REFERENCES EQUIPE (num_equipe));
  
CREATE TABLE PARTICIPER (
  numEquipe NUMERIC (5) NOT NULL ,
  numCompétition NUMERIC (5) NOT NULL ,
  Resultat Varchar2(50),
  PRIMARY KEY (numEquipe,numCompétition),
  FOREIGN KEY (numEquipe) REFERENCES EQUIPE (num_equipe),
  FOREIGN KEY (numCompétition) REFERENCES COMPETITION (num_comp));

INSERT INTO EQUIPE VALUES(96969,'CLGornets',55555,10000);
INSERT INTO COMPETITION VALUES(98465,'WOWOW LE FOOT LA','coupe');
INSERT INTO COMPETITION VALUES(85647,'laCoupeDeCheveux','coupe');



DROP TABLE PRETER;
RENAME PARTICIPATION TO PARTICIPER ;

ALTER TABLE JOUEUR ADD ballonOR NUMERIC(1);
ALTER TABLE JOUEUR DROP COLUMN ballonOR;
ALTER TABLE JOUEUR MODIFY activites NUMERIC(4);
ALTER TABLE JOUEUR RENAME COLUMN activites TO activite;

UPDATE COMPETITION SET nom='CoupeDuMonde' WHERE nom='test';



  

