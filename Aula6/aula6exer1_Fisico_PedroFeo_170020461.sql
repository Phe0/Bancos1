-- --------  << aula6exer1_Fisico >>  ----------
--
--           SCRIPT DE CRIACAO (DDL)
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

CREATE DATABASE IF NOT EXISTS aula6exer1;

USE aula6exer1;

CREATE TABLE CURSO(
    codigo INT NOT NULL AUTO_INCREMENT,
    nome VARCHAR(100) NOT NULL,
    CONSTRAINT CURSO_PK PRIMARY KEY(codigo)
) AUTO_INCREMENT=1;

CREATE TABLE ALUNO(
    matricula INT NOT NULL AUTO_INCREMENT,
    nome VARCHAR(50) NOT NULL,
    rg INT NOT NULL,
    telefone BIGINT(11) NOT NULL,
    codigo INT NOT NULL,
    CONSTRAINT ALUNO_PK PRIMARY KEY(matricula),
    CONSTRAINT ALUNO_CURSO_FK FOREIGN KEY(codigo) 
        REFERENCES CURSO (codigo)
) AUTO_INCREMENT=1;

CREATE TABLE DISCIPLINA(
    idDisciplina INT NOT NULL AUTO_INCREMENT,
    nome VARCHAR(50) NOT NULL,
    codigo INT NOT NULL,
    CONSTRAINT DISCIPLINA_PK PRIMARY KEY(idDisciplina),
    CONSTRAINT DISCIPLINA_CURSO_FK FOREIGN KEY(codigo)
        REFERENCES CURSO(codigo)
) AUTO_INCREMENT=1;