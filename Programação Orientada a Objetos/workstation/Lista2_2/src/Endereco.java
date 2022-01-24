public class Endereco {
	private String rua;
	private int numero;
	private String bairro;
	private String complemento;
	private String cidade;
	private String estado;
	
	Endereco (String rua, int numero, String bairro, String complemento, String cidade, String estado){
		this.bairro = bairro;
		this.cidade = cidade;
		this.complemento = complemento;
		this.estado = estado;
		this.numero = numero;
		this.rua = rua;
	}
	
	public String mostraDados() {
		return "Rua "+this.rua+", N° "+this.numero+
				"\nBairro "+this.bairro+
				"\n"+this.complemento+
				"\n"+this.cidade+" - "+this.estado;
	}
}