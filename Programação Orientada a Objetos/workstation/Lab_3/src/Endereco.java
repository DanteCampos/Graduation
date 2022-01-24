
public class Endereco {
	private String rua;
	private int numero;
	private int quadra;
	private int lote;
	private String complemento;
	private String bairro;
	private String cidade;
	private String estado;
	
	Endereco (String rua, int numero){
		this.rua = rua;
		this.numero = numero;
	}
	
	public String getRua (){
		return this.rua;
	}
	
	public int getNumero (){
		return this.numero;
	}
	
	public int getQuadra (){
		return this.quadra;
	}
	
	public int getLote (){
		return this.lote;
	}
	
	public String getComplemento (){
		return this.complemento;
	}
	
	public String getBairro (){
		return this.bairro;
	}
	
	public String getCidade (){
		return this.cidade;
	}
	
	public String getEstado (){
		return this.estado;
	}
	
	public void setRua (String rua){
		this.rua = rua;
	}
	
	public void setNumero (int numero){
		this.numero = numero;
	}
	
	public void setQuadra (int quadra){
		this.quadra = quadra;
	}
	
	public void setLote (int lote){
		this.lote = lote;
	}
	
	public void setComplemento (String complemento){
		this.complemento = complemento;
	}
	
	public void setBairro (String bairro){
		this.bairro = bairro;
	}
	
	public void setCidade (String cidade){
		this.cidade = cidade;
	}
	
	public void setEstado (String estado){
		this.estado = estado;
	}
}
