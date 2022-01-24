public class Autor {
	//Atributos
	
	private String nome;
	private String sobrenome;
	
	//M�todos
	Autor (String nome, String sobrenome){
		this.nome = nome.toUpperCase();
		this.sobrenome = sobrenome.toUpperCase();
	}
	
	
	//Getters e Setters
	
	public String getNome() {
		return nome;
	}

	public String getSobrenome() {
		return sobrenome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public void setSobrenome(String sobrenome) {
		this.sobrenome = sobrenome;
	}
	
}
