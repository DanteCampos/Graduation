
public class Principal {

	public static void main(String[] args) {
		Endereco end = new Endereco ("Bandeirantes", 13584, "Limoeiro", "Pr�ximo ao Fadiga's Bar", "Cuiab�", "MT");
		Gerente ger = new Gerente ("Alu�so", "Pedreira", 5600.20);
		LojaConcreta matriz = new LojaConcreta ("185160000","Kimera's Lan House",end,ger);
		
		end = new Endereco ("Pindamonhabeira", 4831, "Caiza", "Ap�s o posto", "Primavera do Leste", "MT");
		ger = new Gerente ("Jorge", "Pinheiro", 4312.20);
		LojaConcreta filial1 = new LojaConcreta ("185160001","Kimera's Lan House 2",end,ger);
		
		end = new Endereco ("Get�lio Gon�alves", 9898, "Itatiaia", "Ao lado da pamonharia", "Rondon�polis", "MT");
		ger = new Gerente ("Luana", "Medreira", 6781.20);
		LojaConcreta filial2 = new LojaConcreta ("185160002","Kimera's Lan House 3",end,ger);
		
		System.out.println(matriz.mostraDados()+"\n");
		System.out.println(filial1.mostraDados()+"\n");
		System.out.println(filial2.mostraDados()+"\n");
		
		System.out.println("Abrindo as lojas...\n");
		matriz.registra_abertura_dia();
		filial1.registra_abertura_dia();
		filial2.registra_abertura_dia();
		System.out.println(matriz.mostraDados()+"\n");
		System.out.println(filial1.mostraDados()+"\n");
		System.out.println(filial2.mostraDados()+"\n");
		
		matriz.registra_abertura_dia();
		
		System.out.println("Fechando as lojas...\n");
		matriz.registra_fechamento_dia();
		filial1.registra_fechamento_dia();
		filial2.registra_fechamento_dia();
		System.out.println(matriz.mostraDados()+"\n");
		System.out.println(filial1.mostraDados()+"\n");
		System.out.println(filial2.mostraDados()+"\n");
		
		matriz.registra_fechamento_dia();
	}

}
