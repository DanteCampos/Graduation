import java.util.ArrayList;

public class Principal {

	public static void main(String[] args) {
		ArrayList<Musica> musicas = new ArrayList<Musica>();
		
		Compositor compo1 = new Compositor("Imagine Dragons");
		compo1.setNacionalidade("Estadunidense");
		
		Compositor compo2 = new Compositor("Baco Exu do Blues");
		compo2.setNacionalidade("Brasileiro");
		
		Compositor compo3 = new Compositor("Tim Bernardes");
		compo3.setNacionalidade("Brasileiro");
		
		Musica music1 = new Musica("Chill Out");
		music1.setAno(2019);
		music1.setTipo("Pop");
		music1.setCompositores(compo1);
		musicas.add(music1);
		
		Musica music2 = new Musica("Queima a minha pele");
		music2.setAno(2019);
		music2.setTipo("Rap");
		music2.setCompositores(compo2);
		music2.setCompositores(compo3);
		musicas.add(music2);
		
		Musica music3 = new Musica("Girassois de Van Gogh");
		music3.setAno(2019);
		music3.setTipo("Rap");
		music3.setCompositores(compo2);
		musicas.add(music3);
		
		for(int i = 0; i<3; i++) System.out.println(musicas.get(i).toString()+"\n");
	}

}
