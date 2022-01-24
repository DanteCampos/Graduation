import java.util.ArrayList;

public class Principal {

	public static void main(String[] args) {
		ArrayList <Item> itens = new ArrayList<Item>();
		
		CD cd1 = new CD();
		cd1.setAno(2019);
		cd1.setArtista("Djonga");
		cd1.setComentarios("Um soco na cara dos racistas");
		cd1.setQfaixas(13);
		cd1.setTempo("47:16");
		cd1.setTitulo("Ladrao");
		itens.add(cd1);
		
		CD cd2 = new CD();
		cd2.setAno(2019);
		cd2.setArtista("Terno Rei");
		cd2.setComentarios("Uma viagem pra dentro");
		cd2.setQfaixas(10);
		cd2.setTempo("35:16");
		cd2.setTitulo("Essa Noite Bateu Com Um Sonho");
		itens.add(cd2);
		
		CD cd3 = new CD();
		cd3.setAno(2019);
		cd3.setArtista("Baco Exu do Blues");
		cd3.setComentarios("Mais um baiano fazendo historia");
		cd3.setQfaixas(10);
		cd3.setTempo("32:16");
		cd3.setTitulo("Bluesman");
		itens.add(cd3);
		
		Filme filme1 = new Filme();
		filme1.setAno(2018);
		filme1.setComentarios("Uma exposicao do kkk de antes e dos absurdos de hoje");
		filme1.setDiretor("Spike Lee");
		filme1.setTempo("2:42:00");
		filme1.setTitulo("BlacKkKlansman");
		itens.add(filme1);
		
		Jogo jogo1 = new Jogo();
		jogo1.setAno(1990);
		jogo1.setComentarios("O melhor jogo para estrear o Super Nintendo");
		jogo1.setNjogadores(1);
		jogo1.setPlataforma("Super Nintendo");
		jogo1.setTempo("4:50:11");
		jogo1.setTitulo("Super Mario World");
		itens.add(jogo1);
		
		Jogo jogo2 = new Jogo();
		jogo2.setAno(2019);
		jogo2.setComentarios("A revolucao para a mecanica de combate corpo-a-corpo em terceira pessoa");
		jogo2.setNjogadores(1);
		jogo2.setPlataforma("PC/PS4/XONE");
		jogo2.setTempo("35:24:41");
		jogo2.setTitulo("Sekiro: Shadows Die Twice");
		itens.add(jogo2);
		
		Jogo jogo3 = new Jogo();
		jogo3.setAno(1985);
		jogo3.setComentarios("A inovacao da visao side-scrolling inaugurada pelo maior personagem da Nintendo");
		jogo3.setNjogadores(1);
		jogo3.setPlataforma("NES");
		jogo3.setTempo("3:30:12");
		jogo3.setTitulo("Super Mario Bros.");
		itens.add(jogo3);
		
		Filme filme2 = new Filme();
		filme2.setAno(1999);
		filme2.setComentarios("Uma obra prima da quebra da quarta parede");
		filme2.setDiretor("David Fincher");
		filme2.setTempo("2:20:34");
		filme2.setTitulo("Clube da Luta");
		itens.add(filme2);
		
		Filme filme3 = new Filme();
		filme3.setAno(2002);
		filme3.setComentarios("Um dos melhores filmes ja feitos em terra tupi");
		filme3.setDiretor("Fernando Meirelles");
		filme3.setTempo("2:12:32");
		filme3.setTitulo("Cidade de Deus");
		itens.add(filme3);
		
		CD cd4 = new CD();
		cd4.setAno(2019);
		cd4.setArtista("BaianaSystem");
		cd4.setComentarios("Novas raizes baianas musicais, classicos do novo mundo");
		cd4.setQfaixas(13);
		cd4.setTempo("42:42");
		cd4.setTitulo("O Futuro Nao Demora");
		itens.add(cd4);
		
		for (int i = 0; i < 10; i++) {
			System.out.println(itens.get(i).toString());
			if (itens.get(i) instanceof Jogo) {
				System.out.println(((Jogo)itens.get(i)).getPlataforma());
			}
			System.out.println();
		}
	}
}
