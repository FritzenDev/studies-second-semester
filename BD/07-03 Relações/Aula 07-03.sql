create table tb_estado(cd_estado char(2) not null,
					  nm_estado varchar(30) not null);
					   
create table tb_cliente(id_cliente integer not null,
					   nm_cliente varchar(50) not null,
					   cd_estado char(2) not null);
					   
insert into tb_estado values('RS','RIO GRANDE DO SUL'),
('SC','SANTA CATARINA'),
('SP','SAO PAULO'),
('RJ','RIO DE JANEIRO');

insert into tb_cliente values('1','LUIS','SC'),
('2','PEDRO','SP'),
('3','MARIA','RS'),
('4','CARLA','SC');


--Adicionar uma regra a tabela tb_cliente onde a primary key será o ID do cliente já que não poderá repetir na tabela
alter table tb_cliente add constraint pk_id_cliente primary key(id_cliente);

--Diferença: Primary Key não recebe valores nulos, enquanto unique key receberá, uma tabela só poderá ter 1 única primary key, enquanto
--poderá ter inúmeras unique keys

--Adicionar uma regra a tabela tb_estado onde o nome do estado não poderá repetir na coluna
alter table tb_estado add constraint uk_nm_estado unique(nm_estado);

--Adicionar uma regra a tabela tb_estado onde a primary key sera o código do estado
alter table tb_estado add constraint pk_estado primary key(cd_estado);

--Adicionar uma regra a tabela tb_cliente onde relaciona os códigos de estados no estado
alter table tb_cliente add constraint cd_cliente_estado foreign key(cd_estado) references tb_estado(cd_estado);

--Contar quantos itens tem no cd_estado que equivale a RS
select count(*) from tb_cliente where cd_estado = 'RS';

--Mostrar a lista com o nome da pessoa, código do estado e o nome do estado
select nm_cliente, a.cd_estado, nm_estado from tb_cliente a, tb_estado b where a.cd_estado = b.cd_estado order by nm_estado;