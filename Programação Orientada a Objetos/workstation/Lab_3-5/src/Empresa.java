
public class Empresa {
	private String cnpj;
	private String razao;
	private Endereco endereco;
	
	Empresa (String razao){
		this.razao=razao;
	}
	
	public String toString() {
		return"Razão Social: "+this.razao+"\nCNPJ: "+this.cnpj+"\nEndereço da empresa:\n"
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
