--(1)
create table AUTO_SHOP(ID_SHOP number(5) PRIMARY KEY, CITY varchar(25), STREET varchar2(25));
select * from auto_shop;
--(2)
create table AUTO(ID_CAR number(5) PRIMARY KEY, ID_SHOP number(5) REFERENCES auto_shop(ID_SHOP),MARK_AUTO varchar2(25),COUNTRY_AUTO varchar2(25),
COLOUR varchar2(25));
select * from auto;
--(3)
create table RENTER(ID_RENTER number (5) PRIMARY KEY, F_NAME varchar2(25), L_NAME varchar2(25),
BIRTHDATE date, ADDRESS varchar2(50), PHONE_NUMBER varchar(20));
select * from renter;
--(4)
create table CAR_FOR_RENT(ID_TAKEN_CAR number(5) PRIMARY KEY, ID_RENTER number(5) REFERENCES renter(ID_RENTER),
ID_CAR number(5) REFERENCES auto(ID_CAR), ID_SHOP number(5) REFERENCES auto_shop(ID_SHOP),DATE_OF_TAKE date, RETURN_TO date,
RETURNED date, FINE char(20));
select * from car_for_rent;

--Прописываем ограничения и проверки
--AUTO_SHOP
alter table auto_shop add CONSTRAINT CHECK_ID_SHOP CHECK(ID_SHOP>=10000 and ID_SHOP<=99999);
alter table auto_shop MODIFY(CITY not null, STREET not null);
alter table auto_shop add CONSTRAINT CHECK_START_LETTER CHECK (REGEXP_LIKE(CITY, '^[А-Я]'));
--AUTO
alter table auto add CONSTRAINT CHECK_ID_AUTO CHECK(ID_CAR>=100 and ID_CAR<=999);
alter table auto MODIFY(COLOUR not null, MARK_AUTO not null);
--RENTER
alter table renter MODIFY(F_NAME not null, L_NAME not null, PHONE_NUMBER not null);
alter table renter add CONSTRAINT CHECK_PHONE_NUMBER CHECK(REGEXP_LIKE(PHONE_NUMBER, '\+.{11,14}'));
--CAR_FOR_RENT
alter table car_for_rent MODIFY(DATE_OF_TAKE not null, RETURN_TO not null);

--Добавление значений
--AUTO_SHOP
insert into auto_shop values(10000, 'Краснодар', 'ул. Красная');
insert into auto_shop values(10001, 'Краснодар', 'ул. Ставропольская');
insert into auto_shop values(10002, 'Краснодар', 'ул. Школьная');
insert into auto_shop values(10003, 'Краснодар', 'ул. Северная');
insert into auto_shop values(10004, 'Краснодар', 'ул. Уральская');

--AUTO
insert into auto values(100, '10000', 'BMW', 'Германия', 'Чёрный');
insert into auto values(101, '10001', 'MERCEDES', 'Германия', 'Белый');
insert into auto values(102, '10002', 'HYUNDAI', 'Чехия', 'Серый');
insert into auto values(103, '10003', 'DODGE CHALLENGER', 'США', 'Чёрный');
insert into auto values(104, '10004', 'FORD MUSTANG', 'США', 'Красный');

--RENTER
insert into renter values(1,'Александр', 'Дмитриевич', TO_DATE('01-01-1990', 'DD-MM-YYYY'), 'ул. Кавказская', '+79187869901');
insert into renter values(2,'Иван', 'Петров', TO_DATE('15-07-1985', 'DD-MM-YYYY'), 'ул. Ленина', '+79123456789');
insert into renter values(3,'Елена', 'Смирнова', TO_DATE('25-03-1992', 'DD-MM-YYYY'), 'ул. Пушкина', '+79051234567');
insert into renter values(4,'Алексей', 'Авдеев', TO_DATE('10-11-2007', 'DD-MM-YYYY'), 'ул. Гагарина', '+79234567890');
insert into renter values(5,'Мария', 'Козлова', TO_DATE('02-06-2000', 'DD-MM-YYYY'), 'ул. Московская', '+79875618890');

--CAR_FOR_RENT
insert into car_for_rent values(200, 1, 100, 10000, TO_DATE('15-05-2020', 'DD-MM-YYYY'), TO_DATE('20-05-2020', 'DD-MM-YYYY'),
TO_DATE('20-05-2020', 'DD-MM-YYYY'), '1000 рублей');
insert into car_for_rent values(201, 2, 101, 10001, TO_DATE('25-07-2015', 'DD-MM-YYYY'), TO_DATE('30-07-2015', 'DD-MM-YYYY'),
TO_DATE('30-07-2015', 'DD-MM-YYYY'), 'Нет штрафа');
insert into car_for_rent values(202, 3, 102, 10002, TO_DATE('17-01-2012', 'DD-MM-YYYY'), TO_DATE('05-02-2012', 'DD-MM-YYYY'),
TO_DATE('05-02-2012', 'DD-MM-YYYY'), 'Нет штрафа');
insert into car_for_rent values(203, 4, 103, 10003, TO_DATE('10-04-2021', 'DD-MM-YYYY'), TO_DATE('01-08-2021', 'DD-MM-YYYY'),
TO_DATE('08-08-2021', 'DD-MM-YYYY'), '2500 рублей');
insert into car_for_rent values(204, 5, 104, 10004, TO_DATE('01-10-2022', 'DD-MM-YYYY'), TO_DATE('01-02-2023', 'DD-MM-YYYY'),
TO_DATE('10-02-2023', 'DD-MM-YYYY'), '3000 рублей');

--Изменения таблиц
alter table auto_shop MODIFY(city varchar2(50), street varchar2(50));
alter table auto modify(ID_CAR number(3));
--delete from AUTO where colour='Белый';
--alter table auto_shop drop constraint check_start_letter;
--delete from auto_shop where STREET='ул. Северная';
alter table renter modify(PHONE_NUMBER char(15));
alter table renter modify(ID_RENTER number(2));
alter table car_for_rent modify(ID_TAKEN_CAR number(3));
alter table car_for_rent modify(ID_RENTER number(2));
alter table car_for_rent modify(ID_CAR number(3));
update car_for_rent set FINE='Нет штрафа' where return_to='20.05.2020';
update car_for_rent set RETURN_TO='15.07.2020' where returned='20.05.2020';
update car_for_rent set RETURNED='15.07.2020' where returned='20.05.2020';
update car_for_rent set RETURN_TO='25.10.2015' where returned='30.07.2015';
update car_for_rent set RETURNED='25.10.2015' where returned='30.07.2015';
update car_for_rent set RETURN_TO='17.06.2012' where returned='05.02.2012';
update car_for_rent set RETURNED='17.06.2012' where returned='05.02.2012';
update renter set BIRTHDATE=TO_DATE('10-11-2001', 'DD-MM-YYYY') where BIRTHDATE=TO_DATE('10-11-2007', 'DD-MM-YYYY');


--Изменение для даты
alter session set nls_date_format='DD.MM.YYYY';

