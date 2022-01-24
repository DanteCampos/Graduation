import java.util.ArrayList;

public class Principal {

	public static void main(String[] args) {
		ArrayList <Funcionario> funcionarios = new ArrayList <Funcionario>();
		
		Gerente gerente = new Gerente("Júlio", "Gonçalves");
		gerente.setBonificacao(200.50);
		gerente.setSalarioMensal(5600.80);
		funcionarios.add(gerente);
		
		Horista horista = new Horista ("Amanda", "Campos");
		horista.setHorasTrabalhadas(160);
		horista.setValorHora(15.60);
		funcionarios.add(horista);
		
		horista = new Horista ("Luiz", "Pinto");
		horista.setHorasTrabalhadas(150);
		horista.setValorHora(11.56);
		funcionarios.add(horista);
	
		Comissionado comissionado = new Comissionado ("Luíza","Oliveira");
		comissionado.setPercentualComissao(10.23);
		comissionado.setSalarioMensal(8900.23);
		comissionado.setTotalVendas(25);
		funcionarios.add(comissionado);
		
		comissionado = new Comissionado ("Alacyr","Pedreira");
		comissionado.setPercentualComissao(12.36);
		comissionado.setSalarioMensal(5623.53);
		comissionado.setTotalVendas(23);
		funcionarios.add(comissionado);
		
		comissionado = new Comissionado ("Marina","Bolsas");
		comissionado.setPercentualComissao(16.23);
		comissionado.setSalarioMensal(9654.78);
		comissionado.setTotalVendas(30);
		funcionarios.add(comissionado);
		
		Administrador administrador = new Administrador ("Daniel","Urias");
		administrador.setSalarioMensal(12654.12);
		funcionarios.add(administrador);
		
		administrador = new Administrador ("Ulemar","Pereira");
		administrador.setSalarioMensal(4265.21);
		funcionarios.add(administrador);
		
		administrador = new Administrador ("Sandro","Pacheco");
		administrador.setSalarioMensal(7564.12);
		funcionarios.add(administrador);
		
		administrador = new Administrador ("Yuri","Farias");
		administrador.setSalarioMensal(14875.64);
		funcionarios.add(administrador);
		
		int tamanho = funcionarios.size();
		
		for (int i = 0; i < tamanho; i++) {
			if (funcionarios.get(i) instanceof Gerente) System.out.println(((Gerente)funcionarios.get(i)).mostraDados());
			else if (funcionarios.get(i) instanceof Administrador) System.out.println(((Administrador)funcionarios.get(i)).mostraDados());
			else if (funcionarios.get(i) instanceof Comissionado) System.out.println(((Comissionado)funcionarios.get(i)).mostraDados());
			else System.out.println(((Horista)funcionarios.get(i)).mostraDados());
		}
		
	}

}
