CREATE TABLE paciente (
	nif varchar(10) NOT NULL,
	nome varchar(60) NOT NULL,
	morada varchar(80) NOT NULL, 
	CONSTRAINT  pkPaciente PRIMARY KEY (nif)
);

CREATE TABLE medico (
	bi varchar(10) NOT NULL,
	nome varchar (50) NOT NULL,
	morada varchar (80) NOT NULL,
	CONSTRAINT pkMedico PRIMARY KEY (bi)
);

CREATE TABLE doenca (
	ref integer NOT NULL,
	designacao varchar(300),
	CONSTRAINT pkDoenca PRIMARY KEY (ref)
);

CREATE TABLE consulta (
	num integer NOT NULL,
	data date NOT NULL,
	sala integer NOT NULL,
	bi varchar(10) NOT NULL,
	nif varchar(10) NOT NULL,
	CONSTRAINT pkConsulta PRIMARY KEY (num),
	CONSTRAINT fk_consulta_medico FOREIGN KEY (bi) 
		REFERENCES medico(bi),
	CONSTRAINT fk_consulta_paciente FOREIGN KEY (nif) 
		REFERENCES paciente(nif)
);
CREATE TABLE diagnosticada (
	ref integer NOT NULL,
	num integer NOT NULL,
	CONSTRAINT pkDiagnosticada PRIMARY KEY (ref, num),
	CONSTRAINT fk_diagnosticada_doenca FOREIGN KEY (ref) 
		REFERENCES doenca(ref),
	CONSTRAINT fk_diagnosticada_consulta FOREIGN KEY (num) 
		REFERENCES consulta (num)
);

