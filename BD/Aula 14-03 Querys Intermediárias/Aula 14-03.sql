-- Criar as tabelas
create table tb_estado (cd_estado char(2),
					   nm_estado varchar(30) NOT NULL);

create table tb_cliente (id_cliente integer,
						nm_cliente varchar(30) not null,
						cd_estado char(2) not null,
						nu_idade integer not null);
						
-- Criar as constraints
alter table tb_estado add constraint pk_cd_estado primary key(cd_estado);
alter table tb_estado add constraint ak_nm_estado unique(nm_estado);

alter table tb_cliente add constraint pk_id_cliente primary key(id_cliente);
alter table tb_cliente add constraint fk_cd_estado foreign key(cd_estado) references tb_estado(cd_estado);

-- Inserções dos dados
insert into tb_estado values('RS', 'RIO GRANDE DO SUL'),
							('SC', 'SANTA CATARINA'),
							('RJ', 'RIO DE JANEIRO'),
							('SP', 'SAO PAULO');
							
							
insert into tb_cliente values(1,'LUIS','RS',55),
							 (2,'PEDRO','SC',16),
							 (3,'DAVID','RJ',19),
							 (4,'MARTA','RS',32),
							 (5,'CARLA','RS',40),
							 (6,'JOSE','SC',28);
							 
-- Fazer as seleções dos dados
select * from tb_cliente;
select * from tb_estado;

-- Quantas pessoas existem por estado
select cd_estado, count(*) from tb_cliente group by cd_estado order by count(*) desc;

-- Listar os estados utilizados na tb_cliente
select cd_estado from tb_cliente group by cd_estado order by count(*) desc;
select distinct cd_estado from tb_cliente;

-- Por nome (utilizar join)
select nm_estado, count(*) as total from tb_cliente, 
tb_estado where tb_cliente.cd_estado = tb_estado.cd_estado group by nm_estado order by count(*) desc; -- as total para definir a coluna como total

--Selecionar a maior idade
select nm_cliente, nu_idade from tb_cliente order by nu_idade desc limit 1; -- Nome + idade do mais velho
select max(nu_idade) from tb_cliente;

--Selecionar a media de idade dos clientes
select avg(nu_idade) from tb_cliente;

--Selecionar a soma de todas as idades
select sum(nu_idade) from tb_cliente;

-- Listar o estado e a quantidade de clientes vinculados a este, porém somente aqueles estados que possuirem mais de 1 cliente
select cd_estado, count(*) from tb_cliente group by cd_estado having count(*) > 1 order by count(*) desc;
-- having sem group by? Não
-- group by sem having? Sim

-- Nome da pessoa com maior idade
select nm_cliente from tb_cliente order by nu_idade desc limit 1;
select nm_cliente from tb_cliente where nu_idade = (select max(nu_idade) from tb_cliente);
insert into tb_cliente values(7,'JOAQUIN','RS',80); -- Testar inserindo mais um dado
update tb_cliente set nm_cliente = 'JOAQUIM' where nm_cliente = 'JOAQUIN'; -- Atualizar o nome (apenas teste)

-- Selecionar todo mundo que começa com L
select nm_cliente from tb_cliente where nm_cliente like 'L%';

-- Inserir a maria (ordem do prof)
insert into tb_cliente values(8,'Maria','RS',30);

-- Selecionar todo mundo que termina com D
select nm_cliente from tb_cliente where nm_cliente like '%D';

-- Selecionar todos que tem A no nome
select nm_cliente from tb_cliente where nm_cliente ilike '%A%';

-- Selecionar nomes que possuem AR depois da primeira posição (underline define posição)
select nm_cliente from tb_cliente where nm_cliente ilike '_AR%';

-- like não é case sensitive
-- ilike é case sensitive

-- Listar as pessoas que tem letra minuscula no nome
select nm_cliente from tb_cliente where nm_cliente != upper(nm_cliente);

-- Listar o código do estado que mais tem clientes
select cd_estado from -- Selecionar o código do estado
(select cd_estado, count(*) as total from tb_cliente group by cd_estado) Y -- Lista a contagem de quantas pessoas tem em cada estado
where total = -- Selecionará o código que tem o maior número de pessoas "ONDE O TOTAL FOR (O MAIOR)"
(select max(total) from -- Seleciona o estado com mais clientes
(select cd_estado, count(*) as total from tb_cliente group by cd_estado) X); -- Lista a contagem de quantas pessoas tem em cada estado
-- Select max from de um resultado de sql precisa ter um nome, nesse caso o nome é X



-- Criar uma visão, ou seja, não ocupa um espaço dentro das tabelas do banco
-- Em view não é possível inserir
-- Tabela não física, ou seja, ela atualiza com base no que foi atualizado dentro do SQL que a view foi criada
-- Em outras palavras, mexer no SQL que criou a view manterá ela atualizada
create view vw_total_estado as select cd_Estado, count(*) as total from tb_cliente group by cd_estado;
select * from vw_total_estado;


-- Simplificar utilizando a view
select cd_estado from vw_total_estado where total = (select max(total) from vw_total_estado);


-- Criar uma view para idades
create view vw_cliente as select nm_cliente, nu_idade from tb_cliente; -- View para mostrar nome e idade
select * from vw_cliente;


-- TIPOS DE MANIPULAÇÕES
-- DQL = SELECT
-- DML = INSERT, UPDATE, DELETE
-- DDL = CREATE, ALTER, DROP
-- DCL = GRANT, REVOKE
-- DTL = BEGIN, COMMIT (PARAR/SALVAR), ROLLBACK(DESFAZER A AÇÃO)