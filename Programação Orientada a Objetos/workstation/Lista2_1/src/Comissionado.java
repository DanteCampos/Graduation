
public class Comissionado extends Funcionario{
	private double salarioMensal;
	private int totalVendas;
	private double percentualComissao;
	//o percentual da comiss�o � em cima do sal�rio mensal, vale pra cada venda
	
	Comissionado (String nome, String sobrenome){
		super(nome, sobrenome);
	}
	
	public double getSalarioMensal() {
		return salarioMensal;
	}

	public void setSalarioMensal(double salarioMensal) {
		this.salarioMensal = salarioMensal;
	}

	public int getTotalVendas() {
		return totalVendas;
	}

	public void setTotalVendas(int totalVendas) {
		this.totalVendas = totalVendas;
	}

	public double getPercentualComissao() {
		return percentualComissao;
	}

	public void setPercentualComissao(double percentualComissao) {
		this.percentualComissao = percentualComissao;
	}

	public String mostraDados() {
		return super.mostraDados()+
				"Comissionado"+"\n"+
				"Sal�rio mensal: "+String.format("%.2f", this.salarioMensal)+"\n"+
				"Total de vendas: "+this.totalVendas+"\n"+
				"Percentual de comiss�o: "+String.format("%.2f", this.percentualComissao)+"%\n"+
				"Total por m�s: "+String.format("%.2f", this.ganhoMensal())+"\n";
	}
	
	public double ganhoMensal() {
		return this.salarioMensal + (percentualComissao/100)*this.salarioMensal*this.totalVendas;
	}
}
