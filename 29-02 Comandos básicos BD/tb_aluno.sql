--PARTE 1 DA AULA
--Criar a tabela
create table tb_aluno (ID_ALUNO INTEGER NOT NULL,
					  NM_ALUNO VARCHAR(50) NOT NULL,
					  NU_IDADE INTEGER NOT NULL);
					  
--Inserir o aluno 1					  
insert into tb_aluno values(1,'Luis Fernando',55);

--Mostrar a tabela inteira
select * from tb_aluno;

--Inserir o aluno 2
insert into tb_aluno values(2,'RENAN',16);

--Mostrar apenas os nomes dos alunos
select nm_aluno from tb_aluno;

--Inserir o 3° aluno de acordo com outra ordem
insert into tb_aluno(nm_aluno,id_aluno,nu_idade) values ('SANDRA',4,23);

--Mostrar a quantidade de itens dentro da tabela
select count(*) from tb_aluno;

--Inserir mais de um dado
insert into tb_aluno values(6,'MARIA',45),(7,'CARLOS',18);


--PARTE 2 DA AULA

--Ler a tabela em ordem alfabética (Default -> ascendente)
select nm_aluno from tb_aluno order by nm_aluno;
--select nm_aluno from tb_aluno order by nm_aluno desc (code descendente)

--Inserir um dado
insert into tb_aluno values (9,'andre',34);

--Deletar um dado da tabela
delete from tb_aluno where id_aluno = 9;

--Mostrar toda a tabela
select * from tb_aluno;

--Ler a tabela com todos os nomes maiusculos e minúsculos
select UPPER(NM_ALUNO) from tb_aluno;
select LOWER(NM_ALUNO) from tb_aluno;

--Atualizar os dados da tabela para tudo maiúsculo ou minúsculo
update tb_aluno set nm_aluno = upper(nm_aluno);
update tb_aluno set nm_aluno = lower(nm_aluno);

--Deletar toda a tabela
delete from tb_aluno;

--Realizar funções -> Soma, maior idade, menor idade e idade média
select sum(nu_idade) from tb_aluno; --sum = soma
select max(nu_idade) from tb_aluno; --max = máxima
select min(nu_idade) from tb_aluno; --min = mínima
select avg(nu_idade) from tb_aluno; --avg = average -> média

--Mostrar toda a tabela
select * from tb_aluno;


--PARTE 3 DA AULA

--DDL = Data definition language | DML = Data manipulation language
--Alter = DDL | Update = DML

--Remover uma coluna da tabela
alter table tb_aluno drop column nu_idade;

--Adicionar uma coluna na tabela
alter table tb_aluno add column nu_idade integer;

--Atualizar 1 dado da coluna idade
update tb_aluno set nu_idade = 55 where id_aluno = 1;

--Mostrar toda a tabela
select * from tb_aluno;


--PARTE 4 DA AULA

--Selecionar um campo onde tenha a coluna nu_idade como null, = != is
select nm_aluno from tb_aluno where nu_idade is null;

--Atualizar a idade do aluno de id 2
update tb_aluno set nu_idade = 18 where id_aluno = 2;

--Inserir aluno de mesmo nome, porém idade e id diferente
insert into tb_aluno values (10,'RENAN',50);
insert into tb_aluno values (11,'RENAN DA SILVA',30);
insert into tb_aluno values (12,'LUIZ RENAN DA SILVA',35);

--Mostrar todos os usuários com x nome | Like = abrange mais possibilidades, tais quais % (ignora o antes e depois)
select count(*) from tb_aluno where nm_aluno like '%RENAN%';
select nm_aluno from tb_aluno where nm_aluno like '%RENAN%'; --Listar por nome todos que tem renan

--Selecionar no máximo 1 registro da tabela, por default o primeiro
select * from tb_aluno limit 1;

--Atualizar todos os campos nulos
update tb_aluno set nu_idade = 27 where nu_idade is null;

--Selecionar em ordem ascendente por default pela coluna idade
select * from tb_aluno order by nu_idade;

--Selecionar por campo a menor idade e a maior idade
select * from tb_aluno order by nu_idade limit 1; --menor idade
select * from tb_aluno order by nu_idade desc limit 1; --maior idade

--Selecionar apenas o nome da pessoa com maior e menor idade
select nm_aluno from tb_aluno where nu_idade = (select min(nu_idade) from tb_aluno); --trocar min por max para obter a maior idade


--PARTE 5 DA AULA

--Alterar o nome da tabela
alter table tb_aluno rename to tb_cliente;
alter table tb_cliente rename to tb_aluno;

--Alterar nome da coluna
alter table tb_aluno rename column nu_idade to nu_idade_aluno;

--Mostrar todos os itens da tabela
select * from tb_aluno;