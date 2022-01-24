
public class Aluno {
	private String nome;
	private int matricula;
	private int ano;
	private Curso curso;
	
	Aluno(String nome){
		this.nome = nome;
	}
	
	public String toString() {
		return "Nome: "+this.nome+"\nMatrícula: "+this.matricula+"\nAno: "+this.ano+"\n"+this.curso.toString();
	}
	
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public int getAno() {
		return ano;
	}
	public void setAno(int ano) {
		this.ano = ano;
	}
	public Curso getCurso() {
		return curso;
	}
	public void setCurso(Curso curso) {
		this.curso = curso;
	}
	public int getMatricula() {
		return matricula;
	}
	public void setMatricula(int matricula) {
		this.matricula = matricula;
	}
	
	
}
