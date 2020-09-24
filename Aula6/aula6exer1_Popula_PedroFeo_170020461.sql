-- --------  << aula6exer1_Popula >>  ----------
--
--           SCRIPT DE POPULA (DML)
--
-- Data Criacao ...........: 24/09/2020
-- Autor(es) ..............: Pedro Henrique Andrade Féo
-- Banco de Dados .........: MySQL 8.0
-- Base de Dados (nome) ...: aula6exer1
--
--
-- PROJETO => 01 Base de Dados
--         => 03 Tabelas
--
-- ---------------------------------------------------------

USE aula6exer1;

INSERT INTO CURSO(nome)
VALUES
('Engenharia de Energia'),
('Engenharia Aeroespacial'),
('Engenharia de Software'),
('Engenharia Automotiva'),
('Engenharia Eletronica');

INSERT INTO ALUNO(nome, rg, telefone, codigo)
VALUES
('Pedro Andrade', 201630515, 61945678900, 1),
('Ivan Dobbin', 384405873, 61945678901, 2),
('Gustavo Pereira', 109838786, 61945678902, 3),
('Victor Melo', 363294417, 61945678903, 4),
('Henrique Miguel', 369308761, 61945678904, 5);

INSERT INTO DISCIPLINA(nome, codigo)
VALUES
('Engenharia e Ambiente', 1),
('Física 1', 2),
('Sistema de Banco de Dados 1', 3),
('Eletromagnetismo', 4),
('Circuitos 1', 5);