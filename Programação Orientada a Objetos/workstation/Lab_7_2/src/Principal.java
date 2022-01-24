import java.util.ArrayList;
import java.util.Observer;

public class Principal {
	public static void main (String[] args){
		ArrayList<Assinante> assinantes = new ArrayList <Assinante>();
		ArrayList<RevistaVeja> revistas = new ArrayList <RevistaVeja>();
		
		for (int i = 1; i <5; i++) assinantes.add(new AssinanteAnual(i));
		for (int i = 1; i <5; i++) assinantes.add(new AssinanteMensal(i));
		
		revistas.add(new RevistaVeja("Mundo Estranho", 45));
		revistas.add(new RevistaVeja("Veja", 456));
		revistas.add(new RevistaVeja("EDGE", 13));
		revistas.add(new RevistaVeja("Game Power", 9));
		
		for (int j=0; j<4; j++){
			for (int i = 0; i < 8; i++) (revistas.get(j)).addObserver((Observer)assinantes.get(i));
		}
		
		for (int i = 0; i < 4; i++) revistas.get(i).novaEdicao();
		
		revistas.get(0).setNome("Mundo Normal");
		revistas.get(1).setNome("Olhe");
		revistas.get(2).setNome("DEGE");
		revistas.get(3).setNome("Power Game");
	}
}