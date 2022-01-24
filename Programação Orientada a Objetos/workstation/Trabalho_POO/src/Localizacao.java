public class Localizacao {
	//Atributos
	
	private String endereco;
	private String bairro;
	private String cidade;
	private String estado;
	
	//M�todos
	Localizacao (String endereco, String bairro, String cidade, String estado){
		this.endereco = endereco.toUpperCase();
		this.bairro =  bairro.toUpperCase();
		this.cidade = cidade.toUpperCase();
		this.estado = estado.toUpperCase();
	}
	
	
	//Getters e Setters
	
	public String getEndereco() {
		return endereco;
	}

	public String getBairro() {
		return bairro;
	}

	public String getCidade() {
		return cidade;
	}

	public String getEstado() {
		return estado;
	}
	
}
