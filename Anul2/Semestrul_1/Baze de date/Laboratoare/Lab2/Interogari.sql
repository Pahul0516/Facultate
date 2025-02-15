﻿--se extrag clientii, magazinele in care s-au inregistrat și notele date de aceștia angajaților din magazin
SELECT C.nume AS Nume_Client,
	   M.nume AS Magazin,
       A.nume AS Angajat,
	   NCA.nota AS Nota
FROM Client C
JOIN Magazin M ON C.ID_Magazin = M.ID_Magazin
JOIN Nota_Client_Angajat NCA ON C.ID_Client = NCA.ID_Client
JOIN Angajat A ON NCA.ID_Angajat = A.ID_Angajat
WHERE A.ID_Magazin = C.ID_Magazin;

-- se extrag clientii, magazinele, numele cafelei si notele unde notele sunt mai mari decat 8
SELECT C.nume AS Nume_Client,
       Cf.nume AS Nume_Cafea,
       NCC.nota AS Nota_Cafea,
	   M.nume AS Magazin

FROM Client C
JOIN Nota_Client_Cafea NCC ON C.ID_Client = NCC.ID_Client
JOIN Cafea Cf ON NCC.ID_Cafea = Cf.ID_Cafea
Join Magazin M ON C.ID_Magazin = M.ID_Magazin
WHERE NCC.nota >= 8;


-- se extrag persoanele cu salarul brut mai mare de 3800 si magazilele unde lucreaza si cine este managerul lor
SELECT A.nume AS Nume_Angajat,
       SUM(S.valoare_brut) AS Salariu_Total_Brut,
	   M.nume AS Magazin,
	   Man.nume AS Manager
FROM Angajat A
JOIN Salar S ON A.ID_Angajat = S.ID_Salar
JOIN Magazin M ON A.ID_Magazin = M.ID_Magazin
JOIN Manager Man On Man.ID_Manager = M.ID_Magazin
GROUP BY A.nume, M.nume, Man.nume
HAVING SUM(S.valoare_brut) >= 3800;



--interogare care verifica de cate zile au fost adaugatii biscuitii si care e magazinul, managerul si cati angajati lucreaza la acel magazin
SELECT M.nume AS Nume_magazin,
	   Man.nume AS Manager,
	   B.nume AS Nume_Biscuit,
       B.data_adaugarii AS Data_Adaugarii,
       DATEDIFF(DAY, B.data_adaugarii, GETDATE()) AS Zile_De_la_Adaugare,
	   COUNT (A.ID_Angajat) AS Numar_Angajati
FROM Magazin M
JOIN Biscuit B ON M.ID_Magazin = B.ID_Magazin
JOIN Manager Man ON M.ID_Magazin = Man.ID_Manager
JOIN Angajat A ON M.ID_Magazin = A.ID_Magazin
WHERE DATEDIFF(DAY, B.data_adaugarii, GETDATE()) > 30 -- presupunând că biscuiții expiră după 30 de zile
GROUP BY  M.nume, Man.nume, B.nume, B.data_adaugarii;


--sa extrag biscuitii care au termenul de valbilitate mai mare de 2000 de zile, magazinul, managerul si numarul de angajati
SELECT M.nume AS Magazin,
	   B.nume AS Nume_Biscuit,
	   Man.nume AS Manager,
	   COUNT(A.ID_Angajat) AS Numar_Angajati,
       DATEADD(DAY, 100, b.data_adaugarii) AS Data_Expirare
FROM Biscuit B
JOIN Magazin M ON B.ID_Magazin = M.ID_Magazin
JOIN Manager Man ON M.ID_Magazin = Man.ID_Manager
JOIN Angajat A ON M.ID_Magazin = A.ID_Magazin
GROUP BY B.nume, M.nume, Man.nume, B.data_adaugarii
HAVING DATEADD(DAY, 2000, b.data_adaugarii) < GETDATE();


--se extrag numele care sunt distincte ale clientilor, care locuiesc in romania, impreuna cu magazinul si managerul si numarul de note pe care le-au oferit angajatiolor
SELECT DISTINCT C.nume AS Nume_Client,
				M.nume AS Magazin,
				Man.nume AS Manager,
				COUNT(NCA.nota) AS Numar_Note
FROM Client C
JOIN Magazin M ON C.ID_Magazin = M.ID_Magazin
JOIN Manager Man ON M.ID_Magazin = Man.ID_Manager
JOIN Nota_Client_Angajat NCA On C.ID_Client =NCA.ID_Client
WHERE C.tara = 'Romania'
GROUP BY C.nume, M.nume, Man.nume
ORDER BY COUNT(NCA.nota) DESC;

-- se extrage numarul de clienti unici pentru fiecare angajat impreuna ca magazinul , managerul si numariul de note oferite cafelei
SELECT A.nume AS Nume_Angajat,
	   COUNT(DISTINCT C.ID_Client) AS Numar_Clienti_Unici,
	   M.nume AS Magazin,
	   Man.nume AS Manager
FROM Angajat A
JOIN Client C ON A.ID_Magazin = C.ID_Magazin
JOIN Magazin M ON A.ID_Magazin = M.ID_Magazin
Join Manager Man ON M.ID_Magazin = Man.ID_Manager
GROUP BY A.nume, M.nume, Man.nume;

-- selectam manageii care au mai mult de 2 ani de experinta impreuna cu magazinul la care lucreaza numarul de expresoare de la acel magazin si numarul de angajati
SELECT Man.nume AS Nume_Manager,
       Man.data_angajarii AS Data_Angajarii,
       DATEDIFF(YEAR, Man.data_angajarii, GETDATE()) AS Experienta_An,
	   COUNT(E.ID_Espresor) as Numar_espresoare,
	   COUNT(A.ID_Angajat) as Numar_angajati
FROM  Manager Man
JOIN Magazin M ON Man.ID_Manager = M.ID_Magazin
JOIN Espresor E On E.ID_Magazin = M.ID_Magazin
JOIN Angajat A ON A.ID_Magazin = M.ID_Magazin
WHERE DATEDIFF(YEAR, Man.data_angajarii, GETDATE()) >= 5
GROUP BY Man.nume, Man.data_angajarii;


--selectare expresoarelor care au pretul cuprins intre 1500 si 6000, magaziul de care apartin, managerul si salarul tuturor angajatilor care lucreaza la acel magazin(suma)
SELECT E.nume AS Nume_Espresor,
	   E.pret AS Pret_Espresor,
	   M.nume AS Magazin,
	   Man.nume AS Manager,
	   SUM(S.valoare_net) AS salarul_Total_de_la_magazin
FROM Espresor E
JOIN Magazin M ON E.ID_Magazin = M.ID_Magazin
JOIN Manager Man ON M.ID_Magazin = Man.ID_Manager
JOIN Angajat A ON M.ID_Magazin = A.ID_Magazin 
JOIN Salar S ON A.ID_Angajat = S.ID_Salar
WHERE e.pret < 1300 AND e.pret > 800
GROUP BY E.nume, E.pret, M.nume, Man.nume;

-- se extrag toate magazinele din Cluj, numele, managerul,numarul de cafele disponibile si numeru de note primite de cafea
SELECT M.nume AS Magazin,
	   Man.nume AS Manager,
	   COUNT(C.ID_Cafea) as Numar_cafele,
	   COUNT(NCC.ID_Cafea) as Numar_note 
FROM Magazin M
JOIN Manager Man ON M.ID_Magazin = Man.ID_Manager
JOIN Cafea C ON M.ID_Magazin = C.ID_Magazin
JOIN Nota_Client_Cafea NCC ON C.ID_Cafea = NCC.ID_Cafea 
WHERE M.locatie LIKE '%Cluj%'
GROUP BY M.nume, Man.nume; 
