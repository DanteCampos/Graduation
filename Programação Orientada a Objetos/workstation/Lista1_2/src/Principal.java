import java.util.ArrayList;
import java.util.Scanner;

public class Principal {

	private static Scanner sc;
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		ArrayList <Filme> filmes = new ArrayList<Filme>();
		int comando;
		Filme filme;
		
		System.out.println("Digite, em ordem: Código, nome, genero, ano e ator, separados por um enter."+
				"Inserir 0 como codigo termina o programa.\n\n");
		
		for (comando=Integer.parseInt(sc.nextLine()); comando != 0; comando=Integer.parseInt(sc.nextLine())) {
			filme = new Filme(comando,sc.nextLine());
			filme.setGenero(sc.nextLine());
			filme.setAno(Integer.parseInt(sc.nextLine()));
			filme.setAtor(sc.nextLine());
			filmes.add(filme);
			
			System.out.println(filme.toString()+"\n\n");
		}
		
		System.out.println("Total de filmes: "+Filme.getTotal());
	}

}
