
public class Funcionario {
	private int cpf;
	private int matricula;
	private String nome;
	private String cargo;
	private double salario;
	private String departamento;
	private Endereco endereco;
	
	Funcionario (String nome, int cpf, int matricula){
		this.nome = nome;
		this.cpf = cpf;
		this.matricula = matricula;
	}
	
	public void aumentaSalario (double percentual){
		this.salario *= 1.0 + (percentual/100.0);
	}
	
	public String mostraDados (){
		return (""+this.cpf+" - "+this.matricula+" - "+this.nome+
				" - Departamento: "+this.departamento+" - Cargo: "+this.cargo);
	}
	
	public int getCpf (){
		return this.cpf;
	}
	
	public int getMatricula (){
		return this.matricula;
	}
	
	public String getNome (){
		return this.nome;
	}
	
	public String getCargo (){
		return this.cargo;
	}
	
	public double getSalario (){
		return this.salario;
	}
	
	public String getDepartamento (){
		return this.departamento;
	}
	
	public Endereco getEndereco (){
		return this.endereco;
	}
	
	public void setCpf (int cpf){
		this.cpf = cpf;
	}
	
	public void setMatricula (int matricula){
		this.matricula = matricula;
	}
	
	public void setNome (String nome){
		this.nome = nome;
	}
	
	public void setCargo (String cargo){
		this.cargo = cargo;
	}
	
	public void setSalario (double salario){
		this.salario = salario;
	}
	
	public void setDepartamento (String departamento){
		this.departamento = departamento;
	}
	
	public void setEndereco (Endereco endereco){
		this.endereco = endereco;
	}
	
}
