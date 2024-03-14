--1
create table tb_pessoa(i_cd_pessoa integer not null,
					   s_nm_pessoa varchar(60) not null,
					   b_fl_sexo boolean not null default false,
					   b_fl_ativo boolean,
					   s_nu_cpf varchar(11),
					   i_nu_idade integer not null check(i_nu_idade >= 1 and i_nu_idade <= 99));

--2
insert into tb_pessoa values(1,'CARLOS SILVA',true,true,47891589003,23),
(2,'PEDRO ANDRADE',true,false,61541336003,17),
(3,'Lidia KRUG',default,true,36566172017,20),
(4,'LAURA SANTOS',default,false,70652458025,38),
(5,'Desmond Pedro',true,false,33345648008,18),
(6,'Bruno Scarpari',true,true,31053381018,19),
(7,'Alyson Marques',true,true,07851067073,14),
(8,'Maria Eduarda',default,true,null,20),
(9,'Daiane Santos',default,true,40913281050,31),
(10,'Pietro Gomes',true,false,null,33),
(11,'THIAGO MENDES',true,true,null,30),
(12,'marcos henrique',true,false,null,58),
(13,'Lucas Franke',true,false,08672070003,15),
(14,'Bianca Andrade',default,true,17214488027,19),
(15,'marcia santos',default,true,null,40),
(16,'ORLANDO MANUEL',true,false,31890905054,23),
(17,'manuel romulo',true,true,52267454009,32),
(18,'Natan KRUG',true,false,07201310062,39),
(19,'Iago SANTOS',true,true,null,49),
(20,'Lucas Lora',true,true,16687843001,69);

--3
create table tb_seguranca as select * from tb_pessoa;
select * from tb_seguranca;

--4
select * from tb_pessoa;

--5
select count(*) from tb_pessoa;

--6
select count(tb_pessoa) from tb_pessoa where s_nu_cpf is null;

--7
select s_nm_pessoa from tb_pessoa order by s_nm_pessoa;

--8
select s_nm_pessoa from tb_pessoa where b_fl_sexo = false;

--9
select count(*) from tb_pessoa where b_fl_ativo = true;

--10
select count(*) from tb_pessoa where b_fl_ativo = true and s_nu_cpf is null;

--11
delete from tb_pessoa where b_fl_ativo = false;

--12
drop table tb_pessoa;

--13
create table tb_pessoa as select * from tb_seguranca;

--14
select count(*) from tb_pessoa where s_nm_pessoa != lower(s_nm_pessoa);

--15
select s_nm_pessoa from tb_pessoa where i_nu_idade between 18 and 25;

--16
select s_nm_pessoa from tb_pessoa where i_nu_idade >= 18 and i_nu_idade <= 25;

--17
select s_nm_pessoa from tb_pessoa where s_nm_pessoa like '%SILVA';

--18
select count(*) from tb_pessoa where s_nm_pessoa like '%ANDRADE';

--19
select s_nm_pessoa from tb_pessoa where s_nm_pessoa like 'L% KRUG';

--20
update tb_pessoa set s_nm_pessoa = upper(s_nm_pessoa);

select * from tb_pessoa;