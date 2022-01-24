public class Principal {

	public static void main(String[] args) {
		Empresa empresa = new Empresa("123455","Padaria da Joana");
		
		Funcionario funcionario1 = new Funcionario("Roberta Goncalves", "138.185.972-94");
		funcionario1.setSalario(1400.35);
		empresa.add(funcionario1);
		
		Funcionario funcionario2 = new Funcionario("Adalto Teixeira", "164.382.731-91");
		funcionario2.setSalario(2354.12);
		empresa.add(funcionario2);
		
		Funcionario funcionario3 = new Funcionario("Gustavo Portinari", "137.425.060-13");
		funcionario3.setSalario(3210.98);
		empresa.add(funcionario3);
		
		Funcionario funcionario4 = new Funcionario("Ana Pacheco", "015.430.761-32");
		funcionario4.setSalario(989.32);
		empresa.add(funcionario4);
		
		Funcionario funcionario5 = new Funcionario("Caio Souza", "132.120.470-20");
		funcionario5.setSalario(1121.65);
		empresa.add(funcionario5);
		
		Gerente gerente1 = new Gerente ("Xuxa Silva", "351.021.980-60");
		gerente1.setSalario(4032.65);
		gerente1.setSenha(134568742);
		empresa.add(gerente1);
		
		Gerente gerente2 = new Gerente ("Amanda Campos", "654.321.908-90");
		gerente2.setSalario(2156.32);
		gerente2.setSenha(138754834);
		empresa.add(gerente2);
		
		Vendedor vendedor1 = new Vendedor ("Xavier Garcia", "879.959.321-99");
		vendedor1.setComissao(120.65);
		vendedor1.setSalario(1568.31);
		for (int i = 0; i<12; i++)vendedor1.setVendas(i, i+1);
		empresa.add(vendedor1);
		
		Vendedor vendedor2 = new Vendedor ("Ulema Pinto", "652.345.102-90");
		vendedor2.setComissao(752.94);
		vendedor2.setSalario(3210.48);
		for (int i = 0; i<12; i++)vendedor2.setVendas(i, 2*i+1);
		empresa.add(vendedor2);

		Vendedor vendedor3 = new Vendedor ("Rita Rocha", "123.456.789-00");
		vendedor3.setComissao(205.97);
		vendedor3.setSalario(2315.12);
		for (int i = 0; i<12; i++)vendedor3.setVendas(i, i+3);
		empresa.add(vendedor3);

		Vendedor vendedor4 = new Vendedor ("Pedro Montes", "987.654.321-10");
		vendedor4.setComissao(321.54);
		vendedor4.setSalario(4135.12);
		for (int i = 0; i<12; i++)vendedor4.setVendas(i, 2*i+5);
		empresa.add(vendedor4);

		
		Vendedor vendedor5 = new Vendedor ("Aracele Pacheco", "135.468.790-13");
		vendedor5.setComissao(978.65);
		vendedor5.setSalario(1354.61);
		for (int i = 0; i<12; i++)vendedor5.setVendas(i, 3*i+1);
		empresa.add(vendedor5);

		System.out.println(empresa.toString());
		for (int i = 0; i<12; i++) empresa.getFuncionario(i).aumentaSalario(10);
		System.out.println(empresa.toString());
	}
	
	

}
