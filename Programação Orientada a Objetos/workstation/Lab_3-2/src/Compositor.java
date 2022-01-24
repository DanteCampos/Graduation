
public class Compositor {
	private String nome;
	private String nacionalidade;
	
	Compositor(String nome){
		this.nome = nome;
	}
	
	public String toString() {
		return this.nome+" ("+this.nacionalidade+")";
	}
	
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public String getNacionalidade() {
		return nacionalidade;
	}
	public void setNacionalidade(String nacionalidade) {
		this.nacionalidade = nacionalidade;
	}
}
