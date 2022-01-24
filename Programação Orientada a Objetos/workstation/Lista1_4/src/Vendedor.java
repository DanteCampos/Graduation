
public class Vendedor extends Funcionario{
	private int vendas[] = new int[12];
	private double comissao;
	
	Vendedor(String nome, String cpf){
		super(nome, cpf);
	}
	public String toString() {
		String str=super.toString()+"\nComissao: "+String.format("%.2f", this.comissao)+"\nVendas:";
		for (int i = 0; i<12; i++) str+=" "+this.vendas[i];
		return str;
	}
	public double getLucroAnual() {
		double total=0;
		for (int i = 0; i<12; i++) total += super.salario + (this.vendas[i]*this.comissao);
		return total;
	}
	
	public int getVendas (int i) {
		return this.vendas[i];
	}
	public void setVendas (int i, int vendas) {
		this.vendas[i] = vendas;
	}
	public double getComissao() {
		return this.comissao;
	}
	public void setComissao(double comissao) {
		this.comissao=comissao;
	}
	
}
