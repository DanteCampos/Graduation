import java.util.ArrayList;

public class Genero {
	private String nome;
	private int quantidade=1;
	public static int totaldegeneros=0;
	public static ArrayList <Genero> listadegeneros = new ArrayList <Genero>();
	
	Genero (String nome){
		this.nome = nome;
	}
	public static void verifica(String str) {
		int i;
		for (i=0;i<Genero.totaldegeneros;i++) {
			if (str.equals(listadegeneros.get(i).nome)) {
				listadegeneros.get(i).incrementa();
				break;
			}
		}
		
		if (i==Genero.totaldegeneros) {
			listadegeneros.add(new Genero(str));
			Genero.totaldegeneros++;
		}
	}
	public void incrementa () {
		this.quantidade++;
	}
	
	public int getQuantidade() {
		return this.quantidade;
	}
	public String getNome() {
		return this.nome;
	}
	
}
