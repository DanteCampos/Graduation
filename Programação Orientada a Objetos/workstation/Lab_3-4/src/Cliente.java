
public class Cliente {
	private String nome;
	private String cpf;
	private Endereco endereco;
	
	Cliente (String nome){
		this.nome = nome;
	}
	
	public String toString() {
		return "Nome: "+this.nome+"\nCPF: "+this.cpf+"\nEndereço:\n"+this.endereco.toString();
	}
	
	public Endereco getEndereco() {
		return endereco;
	}
	public void setEndereco(Endereco endereco) {
		this.endereco = endereco;
	}
	public String getCpf() {
		return cpf;
	}
	public void setCpf(String cpf) {
		this.cpf = cpf;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
}
