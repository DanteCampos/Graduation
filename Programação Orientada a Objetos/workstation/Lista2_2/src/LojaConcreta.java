public class LojaConcreta extends Loja{
	Endereco endereco;
	Gerente gerente;
	
	LojaConcreta (String cnpj, String razaoSocial, Endereco endereco, Gerente gerente){
		super (cnpj, razaoSocial);
		this.endereco = endereco;
		this.gerente = gerente;
	}
	
	public String mostraDados(){
		return super.razaoSocial+
				"\nCNPJ: "+super.cnpj+
				"\n"+(super.aberta?"Aberta":"Fechada")+
				"\nGerente: "+this.gerente.mostraDados()+
				"\nEndereço:\n"+this.endereco.mostraDados();
	}
	
}