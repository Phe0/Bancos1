/* aula4exer5Evolucao5_Logico_PedroFeo-170020461: */

CREATE TABLE MEDICO (
    nomeMedico varchar(50) NOT NULL,
    numeroCrm int NOT NULL,
    estadoCrm varchar(2) NOT NULL,
    idMedico int PRIMARY KEY
);

CREATE TABLE PACIENTE (
    nomePaciente varchar(50) NOT NULL,
    dataNascimento date NOT NULL,
    idPaciente int NOT NULL PRIMARY KEY,
    sexo char NOT NULL,
    numero int NOT NULL,
    bairro varchar(50) NOT NULL,
    cidade varchar(50) NOT NULL,
    complemento varchar(50) NOT NULL,
    cep int NOT NULL,
    logradouro varchar(50) NOT NULL
);

CREATE TABLE CONSULTA (
    idConsulta int NOT NULL PRIMARY KEY,
    dataConsulta date NOT NULL,
    horaConsulta time NOT NULL,
    idPaciente int NOT NULL,
    idMedico int
);

CREATE TABLE RECEITA (
    dataEmissao date NOT NULL,
    idReceita int NOT NULL PRIMARY KEY,
    orientacao varchar(100) NOT NULL,
    posologia int NOT NULL,
    idConsulta int NOT NULL
);

CREATE TABLE ESPECIALIDADE (
    idEspecialidade int NOT NULL PRIMARY KEY,
    nomeEspecialidade varchar(50) NOT NULL
);

CREATE TABLE MEDICAMENTO (
    idMedicamento int NOT NULL PRIMARY KEY,
    nomeMedicamento varchar(50) NOT NULL
);

CREATE TABLE telefone (
    idPaciente int NOT NULL,
    telefone int NOT NULL
);

CREATE TABLE tem (
    idMedico int NOT NULL,
    estadoCrm varchar(2) NOT NULL,
    idEspecialidade int NOT NULL
);

CREATE TABLE possui (
    idReceita int NOT NULL,
    idMedicamento int NOT NULL
);
 
ALTER TABLE CONSULTA ADD CONSTRAINT FK_CONSULTA_2
    FOREIGN KEY (numeroCrm???, estadoCrm???, idMedico???)
    REFERENCES ??? (???);
 
ALTER TABLE CONSULTA ADD CONSTRAINT FK_CONSULTA_3
    FOREIGN KEY (idPaciente)
    REFERENCES PACIENTE (idPaciente);
 
ALTER TABLE RECEITA ADD CONSTRAINT FK_RECEITA_2
    FOREIGN KEY (idConsulta)
    REFERENCES CONSULTA (idConsulta)
    ON DELETE CASCADE;
 
ALTER TABLE telefone ADD CONSTRAINT FK_telefone_1
    FOREIGN KEY (idPaciente)
    REFERENCES PACIENTE (idPaciente);
 
ALTER TABLE tem ADD CONSTRAINT FK_tem_1
    FOREIGN KEY (idMedico???, estadoCrm???)
    REFERENCES ??? (???)
    ON DELETE RESTRICT;
 
ALTER TABLE tem ADD CONSTRAINT FK_tem_2
    FOREIGN KEY (idEspecialidade)
    REFERENCES ESPECIALIDADE (idEspecialidade)
    ON DELETE RESTRICT;
 
ALTER TABLE possui ADD CONSTRAINT FK_possui_1
    FOREIGN KEY (idReceita)
    REFERENCES RECEITA (idReceita)
    ON DELETE RESTRICT;
 
ALTER TABLE possui ADD CONSTRAINT FK_possui_2
    FOREIGN KEY (idMedicamento)
    REFERENCES MEDICAMENTO (idMedicamento)
    ON DELETE SET NULL;