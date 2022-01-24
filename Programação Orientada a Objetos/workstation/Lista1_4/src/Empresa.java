import java.util.ArrayList;

public class Empresa {
	private String cnpj;
	private String nome;
	private int qfuncionarios=0;
	private ArrayList <Funcionario> funcionarios = new ArrayList <Funcionario>();
	
	Empresa (String cnpj, String nome){
		this.cnpj = cnpj;
		this.nome = nome;
	}
	
	public void add(Funcionario f) {
		this.funcionarios.add(f);
		this.qfuncionarios++;
	}
	public Funcionario getFuncionario (int i) {
		return this.funcionarios.get(i);
	}
	
	public String toString () {
		String str=this.nome+"\nCNPJ: "+this.cnpj+"\n\nFuncionarios:\n";
		for (int i = 0; i<this.qfuncionarios; i++)
			str+= "\n"+funcionarios.get(i).toString()+"\nLucro Anual: "
			+String.format("%.2f",funcionarios.get(i).getLucroAnual())+"\n";
		return str;
	}
	
}
