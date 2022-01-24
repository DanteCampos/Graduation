import java.util.ArrayList;

public class Principal {

	public static void main(String[] args) {
		
		ArrayList<Aluno> alunos = new ArrayList<Aluno>();
		
		Aluno aluno1 = new Aluno("Roberto Garcia");
		aluno1.setAno(2018);
		aluno1.setMatricula(201812345);
		Aluno aluno2 = new Aluno("Daniela Ribeiro");
		aluno2.setAno(2015);
		aluno2.setMatricula(201582347);
		Aluno aluno3 = new Aluno("Joaquina Sousa");
		aluno3.setAno(2016);
		aluno3.setMatricula(201614135);
		Aluno aluno4 = new Aluno("José Gomes");
		aluno4.setAno(2017);
		aluno4.setMatricula(201730814);
		Aluno aluno5 = new Aluno("Paula Alves");
		aluno5.setAno(2011);
		aluno5.setMatricula(201195348);
		Aluno aluno6 = new Aluno("Eduardo Maciel");
		aluno6.setAno(2014);
		aluno6.setMatricula(201430200);
		Aluno aluno7 = new Aluno("João Paulo");
		aluno7.setAno(2013);
		aluno7.setMatricula(201376300);
		Aluno aluno8 = new Aluno("Camila Pinheiro");
		aluno8.setAno(2012);
		aluno8.setMatricula(201200165);
		Aluno aluno9 = new Aluno("Guilherme Farias");
		aluno9.setAno(2018);
		aluno9.setMatricula(201864946);
		Aluno aluno10 = new Aluno("Cláudio Freitas");
		aluno10.setAno(2019);
		aluno10.setMatricula(201911111);
		Aluno aluno11 = new Aluno("Clara Oliveira");
		aluno11.setAno(2015);
		aluno11.setMatricula(201803246);
		
		Curso curso1 = new Curso ("Ciências da Computação");
		curso1.setSigla("CC");
		Curso curso2 = new Curso ("Sistemas de Informação");
		curso2.setSigla("SI");
		Curso curso3 = new Curso ("Engenharia de Software");
		curso3.setSigla("ES");
		Curso curso4 = new Curso ("Licenciatura em Matemática");
		curso4.setSigla("LM");
		Curso curso5 = new Curso ("Bacharelado em Matemática");
		curso5.setSigla("BM");
		
		Departamento departamento1 = new Departamento ("Instituto de Informática");
		departamento1.setSigla("INF");
		Departamento departamento2 = new Departamento ("Instituto de Matemática e Estatística");
		departamento2.setSigla("IME");
		
		curso1.setDepartamento(departamento1);
		curso2.setDepartamento(departamento1);
		curso3.setDepartamento(departamento1);
		curso4.setDepartamento(departamento2);
		curso5.setDepartamento(departamento2);
		
		aluno1.setCurso(curso1);
		alunos.add(aluno1);
		aluno2.setCurso(curso2);
		alunos.add(aluno2);
		aluno3.setCurso(curso3);
		alunos.add(aluno3);
		aluno4.setCurso(curso4);
		alunos.add(aluno4);
		aluno5.setCurso(curso5);
		alunos.add(aluno5);
		aluno6.setCurso(curso5);
		alunos.add(aluno6);
		aluno7.setCurso(curso2);
		alunos.add(aluno7);
		aluno8.setCurso(curso3);
		alunos.add(aluno8);
		aluno9.setCurso(curso1);
		alunos.add(aluno9);
		aluno10.setCurso(curso2);
		alunos.add(aluno10);
		aluno11.setCurso(curso4);
		alunos.add(aluno11);
		
		for (int i = 0; i<11; i++) System.out.println("Aluno "+(i+1)+"\n\n"+alunos.get(i).toString());
		
	}

}
