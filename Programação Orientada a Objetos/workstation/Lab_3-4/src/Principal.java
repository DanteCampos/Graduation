import java.util.ArrayList;

public class Principal {

	public static void main(String[] args) {
		
		ArrayList <Cliente> clientes = new ArrayList <Cliente>();
		
		Cliente cliente1 = new Cliente("Ana Cláudia");
		Cliente cliente2 = new Cliente("Raquel Santos");
		Cliente cliente3 = new Cliente("Juliano Lopes");
		
		cliente1.setCpf("138.559.138-54");
		cliente2.setCpf("078.431.871-36");
		cliente3.setCpf("184.486.158-49");
		
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
		
		cliente1.setEndereco(endereco1);
		cliente2.setEndereco(endereco2);
		cliente3.setEndereco(endereco3);
		
		clientes.add(cliente1);
		clientes.add(cliente2);
		clientes.add(cliente3);
		
		for (int i = 0; i<3; i++) System.out.println("Cliente "+(i+1)+"\n"+clientes.get(i).toString()+"\n");
	}

}