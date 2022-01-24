import java.util.Scanner;

public class Principal {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Insira a quantidade de produtos:");
		int a = sc.nextInt();
		sc.nextLine();
		
		Produto[] p = new Produto[a];
		
		int c;
		int q;
		float preco;
		String n;
		String t;
		int escolha;
		
		for (int i = 0; i<a; i++) {
			System.out.println("PRODUTO "+(i+1)+"\nDigite o codigo do produto:");
			c = sc.nextInt();
			sc.nextLine();
			
			System.out.println("Selecione quais informacoes deseja inserir:\n\n0 Nenhuma\n1 Nome do produto\n2 Nome do produto e quantidade no estoque\n3 Nome do produto, quantidade no estoque, tipo do produto e preco\n");
			escolha = sc.nextInt();
			sc.nextLine();
			
			switch (escolha) {
				case (0):
					
					p[i] = new Produto (c);
					break;
					
				case(1):
					System.out.println("Digite o nome do produto:");
					n = sc.nextLine();
					
					p[i] = new Produto (c,n);
					break;
				
				case(2):
					System.out.println("Digite o nome do produto:");
					n = sc.nextLine();
					System.out.println("Digite a quantidade no estoque:");
					q = sc.nextInt();
					sc.nextLine();
					
					p[i] = new Produto (c,n,q);
					break;
					
				case(3):
					System.out.println("Digite o nome do produto:");
					n = sc.nextLine();
					System.out.println("Digite a quantidade no estoque:");
					q = sc.nextInt();
					sc.nextLine();
					System.out.println("Digite o tipo do produto:");
					t = sc.nextLine();
					System.out.println("Digite o preco do produto (use virgula):");
					preco = sc.nextFloat();
					sc.nextLine();
					
					p[i] = new Produto (c,n,q,t,preco);
					break;
			}
			
			System.out.println ("Produto adicionado!\n");
		}
		
		int i;
		int u;
		float novopreco;
		while (true) {
			System.out.println("Comandos:\n");
			
			System.out.println("1 Inserir informacoes no produto\n2 Vender unidades do produto\n3 Comprar unidades do produto\n4 Comprar unidades e atualizar o preco do produto\n5 Colsultar informacoes do produto\n6 Comparar dois produtos\n0 Fechar programa\n");
			escolha = sc.nextInt();
			sc.nextLine();
			
			
			switch (escolha) {
				case(0):
					return;
				
				case(1):
					System.out.println("Digite o índice do produto em que deseja inserir informacoes (entre 1 e "+a+")");
					i = sc.nextInt();
					i--;
					sc.nextLine();
					
					System.out.println("Digite o nome do produto:");
					n = sc.nextLine();
					System.out.println("Digite a quantidade no estoque:");
					q = sc.nextInt();
					sc.nextLine();
					System.out.println("Digite o tipo do produto:");
					t = sc.nextLine();
					System.out.println("Digite o preco do produto (use virgula):");
					preco = sc.nextFloat();
					sc.nextLine();
					
					p[i].inserir(n, q, t, preco);
					System.out.println("Produto inserido com sucesso!");
					break;
				
				case(2):
					System.out.println("Digite o índice do produto que deseja vender (entre 1 e "+a+")");
					i = sc.nextInt();
					i--;
					sc.nextLine();
					
					System.out.println("Digite a quantidade de unidades que deseja vender:");
					u = sc.nextInt();
					sc.nextLine();
					
					p[i].vender(u);
					break;
					
				case(3):
					System.out.println("Digite o índice do produto que deseja comprar (entre 1 e "+a+")");
					i = sc.nextInt();
					i--;
					sc.nextLine();
					
					System.out.println("Digite a quantidade de unidades que deseja comprar:");
					u = sc.nextInt();
					sc.nextLine();
					
					p[i].comprar(u);
					break;
				
				case(4):
					System.out.println("Digite o índice do produto que deseja comprar e atualizar o preco (entre 1 e "+a+")");
					i = sc.nextInt();
					i--;
					sc.nextLine();
					
					System.out.println("Digite a quantidade de unidades que deseja comprar:");
					u = sc.nextInt();
					sc.nextLine();
					
					System.out.println("Digite o novo preco do produto (use virgula):");
					novopreco = sc.nextFloat();
					sc.nextLine();
					
					p[i].comprar(u, novopreco);
					break;
				
				case(5):
					System.out.println("Digite o índice do produto que deseja consultar (entre 1 e "+a+")");
					i = sc.nextInt();
					i--;
					sc.nextLine();
					
					p[i].consultar();
					break;
					
				case(6):
					System.out.println("Digite so índices dos produtos que deseja comparar (entre 1 e "+a+"), separando-os por um espaco");
					i = sc.nextInt();
					i--;
					u = sc.nextInt();
					u--;
					sc.nextLine();
					
					if (p[i].igual(p[u])) System.out.println("Os produtos sao iguais!");
					else System.out.println("Os produtos sao diferentes!");
			}
			System.out.println();
		}
	}
}
