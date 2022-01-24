public class Gerente {
	private String nome;
	private String sobrenome;
	private double salario;
	
	Gerente (String nome, String sobrenome, double salario){
		this.nome = nome;
		this.sobrenome = sobrenome;
		this.salario = salario;
	}

	public String mostraDados () {
		return this.nome+" "+this.sobrenome+
				"\nSalário: "+String.format("%.2f", this.salario);
	}
}