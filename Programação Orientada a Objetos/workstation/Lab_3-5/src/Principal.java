import java.util.ArrayList;

public class Principal {
	public static void main(String[] args) {
		ArrayList <Empregado> empregados = new ArrayList<Empregado>();
		
		Empregado empregado1 = new Empregado("Carlos Pereira");
		Empregado empregado2 = new Empregado("Luciana Cunha");
		Empregado empregado3 = new Empregado("Lucas Pístori");
		Empregado empregado4 = new Empregado("Naiara Suzuki");
		Empregado empregado5 = new Empregado("Chico Gomes");
		
		empregado1.setMatricula(138489644);
		empregado2.setMatricula(718615486);
		empregado3.setMatricula(140841066);
		empregado4.setMatricula(940310816);
		empregado5.setMatricula(308901210);
		
		Empresa empresa1 = new Empresa("PepsiCo, Inc");
		Empresa empresa2 = new Empresa("Google LLC");
		Empresa empresa3 = new Empresa("VALE S.A.");
		
		empresa1.setCnpj("18.013.084/8385-97");
		empresa2.setCnpj("30.301.795/0185-48");
		empresa3.setCnpj("19.182.435/1300-73");
		
		Endereco endereco1 = new Endereco();
		Endereco endereco2 = new Endereco();
		Endereco endereco3 = new Endereco();
		
		endereco1.setRua("Planalto");
		endereco2.setRua("Adenil Falcão");
		endereco3.setRua("Anhanguera");
		
		endereco1.setNumero(350);
		endereco2.setNumero(8522);
		endereco3.setNumero(13);
		
		endereco1.setBairro("Limoeiro");
		endereco2.setBairro("Jomafa");
		endereco3.setBairro("Tomba");
		
		endereco1.setComplemento("Próximo ao Fadiga's Bar");
		endereco2.setComplemento("Após sinaleira");
		endereco3.setComplemento("Esquina com a Avenida Jurubeba");
		
		endereco1.setCidade("Rio de Janeiro");
		endereco2.setCidade("Feira de Santana");
		endereco3.setCidade("Itaparica");
		
		endereco1.setEstado("Rio de Janeiro");
		endereco2.setEstado("Bahia");
		endereco3.setEstado("Bahia");
		
		empresa1.setEndereco(endereco1);
		empresa2.setEndereco(endereco2);
		empresa3.setEndereco(endereco3);
		
		empregado1.setEmpresa(empresa1);
		empregado2.setEmpresa(empresa2);
		empregado3.setEmpresa(empresa2);
		empregado4.setEmpresa(empresa3);
		empregado5.setEmpresa(empresa3);
		
		empregados.add(empregado1);
		empregados.add(empregado2);
		empregados.add(empregado3);
		empregados.add(empregado4);
		empregados.add(empregado5);
		
		for (int i = 0; i<5; i++)
			System.out.println("Empregado "+(i+1)+"\n\n"+empregados.get(i).toString()+"\n");
	}
}