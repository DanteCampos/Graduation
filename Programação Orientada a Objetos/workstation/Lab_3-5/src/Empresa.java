
public class Empresa {
	private String cnpj;
	private String razao;
	private Endereco endereco;
	
	Empresa (String razao){
		this.razao=razao;
	}
	
	public String toString() {
		return"Raz�o Social: "+this.razao+"\nCNPJ: "+this.cnpj+"\nEndere�o da empresa:\n"
			+this.endereco.toString();
	}
	
	public String getCnpj() {
		return cnpj;
	}
	public void setCnpj(String cnpj) {
		this.cnpj = cnpj;
	}
	public String getRazao() {
		return razao;
	}
	public void setRazao(String razao) {
		this.razao = razao;
	}
	public Endereco getEndereco() {
		return endereco;
	}
	public void setEndereco(Endereco endereco) {
		this.endereco = endereco;
	}
}
