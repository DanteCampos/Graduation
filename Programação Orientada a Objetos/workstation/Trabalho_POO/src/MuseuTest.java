import static org.junit.jupiter.api.Assertions.*;

import java.util.ArrayList;

import org.junit.jupiter.api.Test;

class MuseuTest {

	@Test
	void test1() {
		Localizacao localizacao = new Localizacao ("Avenida Planalto, N� 15", "Bueno", "Goi�nia", "Goi�s");
		Museu museu = new 	Museu ("Museu Pindamonhangaba", "Artes Pl�sticas", localizacao);
		Obra obra = new Obra("O Pensador", "Piso B, final do corredor");
		Autor autor = new Autor ("Auguste", "Rodin");
		obra.addAutor(autor);
		obra.addCategoria("Escultura");
		obra.addCategoria("Humano");
		museu.insereObra(obra);
		
		Obra obra2 = new Obra("Monalisa", "Piso A, in�cio do corredor");
		Autor autor2 = new Autor ("Leonardo", "Da Vinci");
		obra2.addAutor(autor);
		obra2.addAutor(autor2);
		obra2.addCategoria("Pintura");
		obra2.addCategoria("Retrato");
		museu.insereObra(obra2);
		
		Obra busca =  museu.buscaObraNome("O Pensador");
		assertEquals (obra, busca);
		
		busca =  museu.buscaObraLocalizacao("Piso B, final do corredor");
		assertEquals ( obra, busca);
		
		busca =  museu.buscaObraNome("Monalisa");
		assertEquals (obra2, busca);
		
		busca =  museu.buscaObraLocalizacao("piso a, in�cio do corredor");
		assertEquals ( obra2, busca);
		
		museu.excluiObraNome("Monalisa");
		museu.editaObra(obra, obra2);
		
		busca =  museu.buscaObraNome("Monalisa");
		assertEquals (obra2, busca);
		
		busca =  museu.buscaObraLocalizacao("piso a, in�cio do corredor");
		assertEquals ( obra2, busca);
		
		museu.excluiObraLocalizacao("piso a, in�cio do corredor");
		busca =  museu.buscaObraLocalizacao("piso a, in�cio do corredor");
		assertEquals ( null, busca);
		
	}
	
	@Test
	void test2() {
		Localizacao localizacao = new Localizacao ("Avenida Planalto, N� 15", "Bueno", "Goi�nia", "Goi�s");
		Museu museu = new 	Museu ("Museu Pindamonhangaba", "Artes Pl�sticas", localizacao);
		Obra obra = new Obra("O Pensador", "Piso B, final do corredor");
		Autor autor = new Autor ("Auguste", "Rodin");
		obra.addAutor(autor);
		obra.addCategoria("Escultura");
		obra.addCategoria("Humano");
		museu.insereObra(obra);
		
		Obra obra2 = new Obra("Monalisa", "Piso A, in�cio do corredor");
		Autor autor2 = new Autor ("Leonardo", "Da Vinci");
		obra2.addAutor(autor);
		obra2.addAutor(autor2);
		obra2.addCategoria("Pintura");
		obra2.addCategoria("Retrato");
		museu.insereObra(obra2);
		
		ArrayList<Autor> autores = new ArrayList <Autor>();
		autores.add(autor);
		Obra busca = museu.buscaObrasPorAutores(autores).get(0);
		assertEquals (obra, busca);
		
		ArrayList<String> categorias = new ArrayList <String>();
		categorias.add("Escultura");
		busca = museu.buscaObrasPorCategorias(categorias).get(0);
		assertEquals (obra, busca);
		
		categorias.add("Humano");
		busca = museu.buscaObras(autores, categorias).get(0);
		assertEquals (obra, busca);
		
		
		
		ArrayList<Autor> autores2 = new ArrayList <Autor>();
		autores2.add(autor2);
		busca = museu.buscaObrasPorAutores(autores2).get(0);
		assertEquals (obra2, busca);
		
		categorias = new ArrayList <String>();
		categorias.add("Pintura");
		busca = museu.buscaObrasPorCategorias(categorias).get(0);
		assertEquals (obra2, busca);
		
		categorias.add("Retrato");
		busca = museu.buscaObras(autores2, categorias).get(0);
		assertEquals (obra2, busca);		
		
	}

}
