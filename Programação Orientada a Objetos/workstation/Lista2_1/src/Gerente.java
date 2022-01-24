
public class Gerente extends Funcionario{
	private double salarioMensal;
	private double bonificacao;
	
	Gerente (String nome, String sobrenome){
		super(nome, sobrenome);
	}
	
	public double getSalarioMensal() {
		return salarioMensal;
	}

	public void setSalarioMensal(double salarioMensal) {
		this.salarioMensal = salarioMensal;
	}

	public double getBonificacao() {
		return bonificacao;
	}

	public void setBonificacao(double bonificacao) {
		this.bonificacao = bonificacao;
	}

	public String mostraDados() {
		return super.mostraDados()+
				"Gerente"+"\n"+
				"Sal�rio mensal: "+String.format("%.2f", this.salarioMensal)+"\n"+
				"Bonifica��o: "+String.format("%.2f", this.bonificacao)+"\n"+
				"Total por m�s: "+String.format("%.2f", this.ganhoMensal())+"\n";
	}
	
	public double ganhoMensal() {
		return this.bonificacao+this.salarioMensal;
	}
}
