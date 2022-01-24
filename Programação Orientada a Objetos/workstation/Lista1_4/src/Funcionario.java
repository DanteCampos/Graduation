public class Funcionario {
	protected String nome;
	protected String cpf;
	protected double salario;
	
	Funcionario(String nome, String cpf){
		this.nome=nome;
		this.cpf=cpf;
	}
	public String toString() {
		return this.nome+"\nCPF: "+this.cpf+"\nSalario: "+String.format("%.2f", this.salario);
	}
	void aumentaSalario(double porcentual) {
		this.salario *= 1+(porcentual/100);
	}
	public double getLucroAnual() {
		return this.salario*12;
	}
	public double bonificacao(){
		double b = salario * 0.10;
		return b;
	}
	
	public double getSalario() {
		return salario;
	}
	public void setSalario(double salario) {
		this.salario = salario;
	}
}