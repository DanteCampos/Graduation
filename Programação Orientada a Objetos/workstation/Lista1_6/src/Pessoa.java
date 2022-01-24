
public class Pessoa {
	private String nome;
	private String sobrenome;
	private String nomeintermed;
	
	Pessoa (String nome, String nomeintermed, String sobrenome){
		this.nome = nome;
		this.sobrenome=sobrenome;
		this.nomeintermed=nomeintermed; 
	}
	
	public String nomeFormatado () {
		String str = this.sobrenome+", "+this.nome.charAt(0)+". "+this.nomeintermed.charAt(0)+".";
		return str.toUpperCase();
	}
}
