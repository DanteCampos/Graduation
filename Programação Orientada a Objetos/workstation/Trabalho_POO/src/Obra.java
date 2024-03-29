import java.util.ArrayList;
public class Obra {
	//Atributos
	
	private String nome;
	private ArrayList <String> categorias = new ArrayList <String>();
	private ArrayList<Autor> autores = new ArrayList <Autor>();
	private String localizacao;
	private int codigo;
	private static int SEQUENCIA = 0;
	
	//M�todos
	
	Obra (String nome, String localizacao){
		this.nome = nome.toUpperCase();
		this.localizacao = localizacao.toUpperCase();
		this.codigo = Obra.SEQUENCIA;
		Obra.SEQUENCIA++;
	}
	
	//Edita Autor
	public boolean editaAutor (Autor autor) {
		int size = this.autores.size();
		for (int i=0; i<size; i++) {
			if (this.autores.get(i).equals(autor)) {
				this.autores.add(i, autor);
				return true;
			}
		}
		return false;
	}
	
	//Adiciona Categoria
	public boolean addCategoria(String categoria) {
		categoria = categoria.toUpperCase();
		if (this.categorias.contains(categoria)) return true;
		else return this.categorias.add(categoria);
	}
	
	//Remove Categoria
	public boolean removeCategoria(String categoria) {
		categoria = categoria.toUpperCase();
		return this.categorias.remove(categoria);
	}
	
	//Verifica se a obra tem a categoria
	public boolean temCategoria (String categoria) {
		categoria = categoria.toUpperCase();
		return this.categorias.contains(categoria);
	}
	
	//Adiciona autor
	public boolean addAutor(Autor autor) {
		if (this.autores.contains(autor)) return true;
		else return this.autores.add(autor);
	}
	
	//Remove autor
	public boolean removeAutor(Autor autor) {
		return this.autores.remove(autor);
	}
	
	//Verifica se a obra tem o autor
	public boolean temAutor (Autor autor) {
		return this.autores.contains(autor);
	}
	
	
	//Getters e Setters
	
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public String getLocalizacao() {
		return localizacao;
	}
	public void setLocalizacao(String localizacao) {
		this.localizacao = localizacao.toUpperCase();
	}
	public int getCodigo () {
		return this.codigo;
	}
}
