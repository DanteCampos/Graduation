
public class Empregado {
	private String nome;
	private int matricula;
	private Empresa empresa;
	
	Empregado (String nome){
		this.setNome(nome);
	}
	
	public String toString() {
		return "Nome: "+this.nome+"\nMatricula: "+this.matricula+"\nEmpresa:\n"+this.empresa.toString();
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public int getMatricula() {
		return matricula;
	}

	public void setMatricula(int matricula) {
		this.matricula = matricula;
	}

	public Empresa getEmpresa() {
		return empresa;
	}

	public void setEmpresa(Empresa empresa) {
		this.empresa = empresa;
	}
}
