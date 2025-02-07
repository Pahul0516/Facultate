INSERT INTO Magazin (nume, locatie, numar_de_telefon, data_infiintarii)
VALUES 
('CafeaBooster', 'Bucuresti', '0741234567', '2020-03-15'),
('EspressoHouse', 'Cluj', '0749876543', '2019-07-10'),
('CaffeArtisan', 'Iasi', '0734567890', '2021-01-20'),
('CoffeeSpot', 'Brasov', '0721123456', '2018-11-05'),
('MorningBuzz', 'Constanta', '0732233445', '2017-06-22'),
('JavaHouse', 'Sibiu', '0745566778', '2022-02-14'),
('CafeNuance', 'Timisoara', '0756781234', '2018-12-30'),
('BrewLab', 'Oradea', '0761122334', '2019-08-13'),
('ZigZagCoffee', 'Ploiesti', '0723456789', '2020-10-01'),
('MorningGrind', 'Arad', '0711122334', '2021-04-17');

INSERT INTO Manager (ID_Manager, nume, numar_de_telefon, adresa_de_email, data_angajarii, departamentul)
VALUES 
(1, 'Ion Popescu', '0721234567', 'ion.popescu@cafeabooster.com', '2020-03-16', 'Operations'),
(2, 'Maria Ionescu', '0738765432', 'maria.ionescu@espressohouse.com', '2019-08-01', 'Customer Service'),
(3, 'Alex Dumitrescu', '0721345678', 'alex.dumitrescu@caffeartisan.com', '2021-02-01', 'Sales'),
(4, 'Andreea Georgescu', '0719876543', 'andreea.georgescu@coffeespot.com', '2018-12-01', 'Marketing'),
(5, 'Daniela Vasile', '0743234567', 'daniela.vasile@morningbuzz.com', '2017-07-01', 'Human Resources'),
(6, 'Robert Marin', '0721987654', 'robert.marin@javahouse.com', '2022-03-01', 'Finance'),
(7, 'Gabriel Iliescu', '0745654321', 'gabriel.iliescu@cafenuance.com', '2019-01-15', 'Operations'),
(8, 'Cristina Tudor', '0723765432', 'cristina.tudor@brewlab.com', '2020-09-01', 'Sales'),
(9, 'Mihai Ene', '0725463728', 'mihai.ene@zigzagcoffee.com', '2020-11-01', 'IT'),
(10, 'Elena Tanase', '0733322111', 'elena.tanase@morninggrind.com', '2021-05-01', 'Marketing');

INSERT INTO Angajat (ID_Magazin, nume, numar_de_telefon, adresa_de_email, data_angajarii)
VALUES 
(1, 'Adrian Popa', '0723234567', 'adrian.popa@cafeabooster.com', '2020-04-01'),
(2, 'Ioana Dinca', '0732234567', 'ioana.dinca@espressohouse.com', '2019-09-01'),
(3, 'Vlad Munteanu', '0721567890', 'vlad.munteanu@caffeartisan.com', '2021-03-01'),
(4, 'Oana Marinescu', '0731234567', 'oana.marinescu@coffeespot.com', '2018-12-10'),
(5, 'Ana Moldovan', '0723456789', 'ana.moldovan@morningbuzz.com', '2017-08-01'),
(6, 'Cristi Petrescu', '0743234567', 'cristi.petrescu@javahouse.com', '2022-04-01'),
(7, 'Laura Neagu', '0744567890', 'laura.neagu@cafenuance.com', '2018-01-20'),
(8, 'Stefan Radu', '0736781234', 'stefan.radu@brewlab.com', '2020-10-01'),
(9, 'Alina Gheorghiu', '0711234567', 'alina.gheorghiu@zigzagcoffee.com', '2021-01-15'),
(10, 'Marius Dragnea', '0721334455', 'marius.dragnea@morninggrind.com', '2021-06-01');

INSERT INTO Salar (ID_Salar, valoare_brut, valoare_net, tva)
VALUES 
(1, 3500, 2500, 19.00),
(2, 4000, 2900, 19.00),
(3, 3000, 2100, 19.00),
(4, 2800, 2000, 19.00),
(5, 4500, 3300, 19.00),
(6, 3800, 2700, 19.00),
(7, 4200, 3100, 19.00),
(8, 3100, 2200, 19.00),
(9, 3600, 2500, 19.00),
(10, 3900, 2700, 19.00);

INSERT INTO Client (ID_Magazin, nume, adresa_de_email, numar_de_telefon, data_inregistrarii, tara)
VALUES 
(1, 'Dan Teodorescu', 'dan.teodorescu@gmail.com', '0721345678', '2021-05-15', 'Romania'),
(2, 'Mihaela Avram', 'mihaela.avram@gmail.com', '0734561234', '2019-10-30', 'Romania'),
(3, 'Victor Serban', 'victor.serban@gmail.com', '0712345678', '2021-02-10', 'Romania'),
(4, 'Andreea Maxim', 'andreea.maxim@gmail.com', '0729876543', '2018-07-20', 'Romania'),
(5, 'Ionut Rusu', 'ionut.rusu@gmail.com', '0734455667', '2020-09-15', 'Romania'),
(6, 'Raluca Nedelcu', 'raluca.nedelcu@gmail.com', '0721234567', '2022-03-10', 'Romania'),
(7, 'Adina Iacob', 'adina.iacob@gmail.com', '0718765432', '2019-04-05', 'Romania'),
(8, 'Cosmin Toma', 'cosmin.toma@gmail.com', '0739988776', '2020-06-23', 'Romania'),
(9, 'Monica Ionescu', 'monica.ionescu@gmail.com', '0712345987', '2021-08-17', 'Romania'),
(10, 'Florin Stefan', 'florin.stefan@gmail.com', '0722345678', '2021-11-12', 'Romania');

INSERT INTO Cafea (ID_Magazin, nume, descriere, pret, intensitate, tara_origine, data_adaugarii)
VALUES 
(1, 'Espresso', 'Strong espresso with bold flavor', 15, 9, 'Brazil', '2021-03-01'),
(2, 'Latte', 'Smooth latte with steamed milk', 18, 5, 'Colombia', '2019-08-15'),
(3, 'Cappuccino', 'Classic cappuccino with a creamy texture', 20, 6, 'Italy', '2021-02-20'),
(4, 'Mocha', 'Espresso with chocolate and milk', 22, 7, 'Ethiopia', '2018-12-10'),
(5, 'Americano', 'Diluted espresso for a milder taste', 12, 4, 'Vietnam', '2020-11-05'),
(6, 'Ristretto', 'Shorter and stronger than espresso', 16, 10, 'Peru', '2022-03-18'),
(7, 'Macchiato', 'Espresso with a splash of milk', 14, 8, 'Kenya', '2019-05-12'),
(8, 'Flat White', 'Velvety espresso with steamed milk', 19, 5, 'Australia', '2020-07-07'),
(9, 'Affogato', 'Espresso poured over ice cream', 25, 9, 'Indonesia', '2021-01-15'),
(10, 'Cold Brew', 'Cold brewed coffee with smooth flavor', 17, 4, 'Guatemala', '2021-06-22');

INSERT INTO Biscuit (ID_Magazin, nume, pret, ingriedente_si_mod_de_preparare, data_adaugarii)
VALUES 
(1, 'Almond Biscuit', 7, 'Flour, almonds, butter, sugar', '2021-03-01'),
(2, 'Chocolate Chip', 8, 'Flour, chocolate chips, butter, sugar', '2019-09-15'),
(3, 'Oatmeal Raisin', 6, 'Oats, raisins, butter, sugar', '2021-02-20'),
(4, 'Shortbread', 5, 'Butter, sugar, flour', '2018-12-10'),
(5, 'Ginger Snap', 7, 'Flour, ginger, butter, sugar', '2020-11-05'),
(6, 'Peanut Butter', 8, 'Flour, peanut butter, sugar', '2022-03-18'),
(7, 'Coconut Delight', 9, 'Flour, coconut flakes, sugar', '2019-05-12'),
(8, 'Lemon Zest', 6, 'Flour, lemon zest, sugar', '2020-07-07'),
(9, 'Hazelnut Crunch', 10, 'Flour, hazelnuts, butter', '2021-01-15'),
(10, 'Vanilla Wafer', 5, 'Flour, vanilla, butter', '2021-06-22');

INSERT INTO Espresor (ID_Magazin, nume, descriere, pret, tip)
VALUES 
(1, 'DeLonghi EC155', 'Compact espresso machine', 500, 'Manual'),
(2, 'Breville Bambino', 'Quick heating espresso machine', 700, 'Semi-Automat'),
(3, 'Philips 3200', 'Fully automatic espresso machine', 1200, 'Automat'),
(4, 'Gaggia Classic', 'Professional manual espresso machine', 800, 'Manual'),
(5, 'Nespresso Vertuo', 'Versatile coffee and espresso machine', 300, 'Automat'),
(6, 'Jura E8', 'High-end fully automatic machine', 1500, 'Automat'),
(7, 'Smeg ECF01', 'Stylish manual espresso machine', 650, 'Manual'),
(8, 'Krups EA8150', 'Compact and powerful', 750, 'Automat'),
(9, 'Mr. Coffee Café', 'Affordable and reliable', 400, 'Semi-Automat'),
(10, 'Rancilio Silvia', 'Premium manual machine', 900, 'Manual');



INSERT INTO Nota_Client_Cafea (ID_Client, ID_Cafea, nota)
VALUES 
(1, 1, 9),
(2, 2, 8),
(3, 3, 7),
(4, 4, 10),
(5, 5, 6),
(6, 6, 9),
(7, 7, 8),
(8, 8, 7),
(9, 9, 10),
(10, 10, 9);

INSERT INTO Nota_Client_Angajat (ID_Client, ID_Angajat, nota)
VALUES 
(1, 1, 8),
(2, 2, 7),
(3, 3, 9),
(4, 4, 10),
(5, 5, 6),
(6, 6, 8),
(7, 7, 7),
(8, 8, 9),
(9, 9, 8),
(10, 10, 10);
