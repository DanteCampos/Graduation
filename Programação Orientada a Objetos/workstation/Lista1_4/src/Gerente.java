public class Gerente extends Funcionario{
	private int senha;
	
	Gerente(String nome, String cpf){
		super(nome, cpf);
	}
	public String toString() {
		return super.toString()+"\nSenha: "+this.senha;
	}
	public double getLucroAnual() {
		return (this.salario+this.bonificacao())*12;
	}
	public double bonificacao(){
			return super.salario * 0.15;
	}

	
	public int getSenha() {
		return senha;
	}

	public void setSenha(int senha) {
		this.senha = senha;
	}
}