
public class Horista extends Funcionario {
	private double valorHora;
	private double horasTrabalhadas;
	//as horas trabalhadas são do mês inteiro
	
	Horista (String nome, String sobrenome){
		super(nome, sobrenome);
	}

	public double getValorHora() {
		return valorHora;
	}

	public void setValorHora(double valorHora) {
		this.valorHora = valorHora;
	}

	public double getHorasTrabalhadas() {
		return horasTrabalhadas;
	}

	public void setHorasTrabalhadas(double horasTrabalhadas) {
		this.horasTrabalhadas = horasTrabalhadas;
	}

	public String mostraDados() {
		return super.mostraDados()+
				"Horista"+"\n"+
				"Valor da hora: "+String.format("%.2f", this.valorHora)+"\n"+
				"Horas trabalhadas no mês: "+this.horasTrabalhadas+"\n"+
				"Total por mês: "+String.format("%.2f", this.ganhoMensal())+"\n";
	}
	
	public double ganhoMensal() {
		return this.valorHora*this.horasTrabalhadas;
	}
}
