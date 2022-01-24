
public class Curso {
	private String nome;
	private String sigla;
	private Departamento departamento;
	
	Curso(String nome){
		this.nome = nome;
	}
	
	public String toString() {
		return "Curso: "+this.nome+" ("+this.sigla+")\n"+this.departamento.toString();
	}
	
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public Departamento getDepartamento() {
		return departamento;
	}
	public void setDepartamento(Departamento departamento) {
		this.departamento = departamento;
	}
	public String getSigla() {
		return sigla;
	}
	public void setSigla(String sigla) {
		this.sigla = sigla;
	}
}
