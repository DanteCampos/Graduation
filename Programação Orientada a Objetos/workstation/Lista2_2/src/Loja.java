
public abstract class Loja implements Registro{
	String cnpj;
	String razaoSocial;
	boolean aberta;
	
	Loja (String cnpj, String razaoSocial){
		this.cnpj = cnpj;
		this.razaoSocial = razaoSocial;
		this.aberta = false;
	}

	public String getCnpj() {
		return cnpj;
	}

	public String getRazaoSocial() {
		return razaoSocial;
	}

	public boolean isAberta() {
		return aberta;
	}
	
	public void registra_abertura_dia() {
		if (this.aberta == false) {
				this.aberta = true;
				System.out.println(this.razaoSocial+" abriu!\n");
		}else System.out.println(this.razaoSocial+" já está aberta!\n");
	}
	
	public void registra_fechamento_dia() {
		if (this.aberta == true) {
				this.aberta = false;
				System.out.println(this.razaoSocial+" fechou!\n");
		}else System.out.println(this.razaoSocial+" já está fechada!\n");
	}
	
}
