
public class Departamento {
	private String nome;
	private String sigla;
	
	Departamento(String nome){
		this.nome = nome;
	}
	
	public String toString() {
		return "Departamento do Curso: "+this.nome+" ("+this.sigla+")\n";
	}
	
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public String getSigla() {
		return sigla;
	}
	public void setSigla(String sigla) {
		this.sigla = sigla;
	}
}
