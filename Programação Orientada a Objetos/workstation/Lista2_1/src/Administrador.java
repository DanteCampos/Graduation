
public class Administrador extends Funcionario{
	private double salarioMensal;
	
	Administrador (String nome, String sobrenome){
		super(nome, sobrenome);
	}
	
	public double getSalarioMensal() {
		return salarioMensal;
	}

	public void setSalarioMensal(double salarioMensal) {
		this.salarioMensal = salarioMensal;
	}

	public String mostraDados() {
		return super.mostraDados()+
				"Administrador"+"\n"+
				"Salário mensal: "+String.format("%.2f", this.salarioMensal)+"\n"+
				"Total por mês: "+String.format("%.2f", this.ganhoMensal())+"\n";
	}
	
	public double ganhoMensal() {
		return this.salarioMensal;
	}
}
