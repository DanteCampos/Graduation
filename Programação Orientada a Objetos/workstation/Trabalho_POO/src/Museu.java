import java.util.ArrayList;
public class Museu {
	//Atributos
	
	private String nome;
	private String categoria;
	private Localizacao localizacao;
	private ArrayList <Obra> obras = new ArrayList <Obra>();
	private int codigo;
	private static int SEQUENCIA = 0;
	
	//Métodos
	
	Museu (String nome, String categoria, Localizacao localizacao){
		this.nome = nome.toUpperCase();
		this.categoria = categoria.toUpperCase();
		this.localizacao = localizacao;
		this.codigo = Museu.SEQUENCIA;
		Museu.SEQUENCIA++;
	}
	
	//Insere Obra
	public void insereObra(Obra obra){
		this.obras.add(obra);
	}
	
	//Edita Obra
	public boolean editaObra (Obra velha, Obra nova) {
		int size = this.obras.size();
		for (int i=0; i<size; i++) {
			if (this.obras.get(i).equals(velha)) {
				this.obras.remove(i);
				this.obras.add(i, nova);
				return true;
			}
		}
		return false;
	}
	
	//Busca Obras por categorias
	public ArrayList<Obra> buscaObrasPorCategorias (ArrayList<String> categorias){
		ArrayList <Obra> obrasComCategorias = new ArrayList<Obra>();
		int sizeObras = this.obras.size();
		
		for (int i = 0; i < sizeObras ; i++) {
			int sizeCategorias = categorias.size();
			boolean temCategorias = true;
			
			for (int j = 0; j < sizeCategorias; j++) {
				if (!(this.obras.get(i).temCategoria(categorias.get(j)))) {
					temCategorias = false;
					break;
				}
			}
			if (temCategorias) obrasComCategorias.add(this.obras.get(i));
		}
		
		if (obrasComCategorias.size() == 0) return null;
		else return obrasComCategorias;
	}
	
	//Busca Obras por autores
	public ArrayList<Obra> buscaObrasPorAutores (ArrayList<Autor> autores){
		ArrayList <Obra> obrasComAutores = new ArrayList<Obra>();
		int sizeObras = this.obras.size();
		for (int i = 0; i < sizeObras ; i++) {
			int sizeAutores = autores.size();
			boolean temAutores = true;
			
			for (int j = 0; j < sizeAutores; j++) {
				if (!(this.obras.get(i).temAutor(autores.get(j)))) {
					temAutores = false;
					break;
				}
			}
			if (temAutores) obrasComAutores.add(this.obras.get(i));
		}
		
		if (obrasComAutores.size() == 0) return null;
		else return obrasComAutores;
	}
	
	//Busca Obras por autores e categorias
	public ArrayList<Obra> buscaObras (ArrayList<Autor> autores, ArrayList<String> categorias){
		ArrayList <Obra> obrasValidas = new ArrayList<Obra>();
		int sizeObras = this.obras.size();
		
		for (int i = 0; i < sizeObras ; i++) {
			int sizeAutores = autores.size();
			int sizeCategorias = categorias.size();
			boolean valida = true;
			
			for (int j = 0; j < sizeAutores; j++) {
				if (!(this.obras.get(i).temAutor(autores.get(j)))) {
					valida = false;
					break;
				}
			}
			for (int j = 0; j < sizeCategorias; j++) {
				if (!(this.obras.get(i).temCategoria(categorias.get(j)))) {
					valida = false;
					break;
				}
			}
			if (valida) obrasValidas.add(this.obras.get(i));
		}
		
		if (obrasValidas.size() == 0) return null;
		else return obrasValidas;
	}
	
	//Busca Obra por nome
	public Obra buscaObraNome (String nome) {
		int size = this.obras.size();
		nome = nome.toUpperCase();
		Obra obra = null;

		for (int i=0; i<size; i++) {
			obra = this.obras.get(i);
			if (obra.getNome().equals(nome)) return obra;
		}
		return null;
	}
	
	//Busca Obra por localização
	public Obra buscaObraLocalizacao (String localizacao) {
		int size = this.obras.size();
		localizacao = localizacao.toUpperCase();
		Obra obra = null;

		for (int i=0; i<size; i++) {
			obra = this.obras.get(i);
			if (obra.getLocalizacao().equals(localizacao)) return obra;
		}
		return null;
	}
	
	//Exclui Obra por nome
	public boolean excluiObraNome (String nome) {
		int size = this.obras.size();
		nome = nome.toUpperCase();
		
		for (int i=0; i<size; i++) {
			if (this.obras.get(i).getNome().equals(nome)) {
				this.obras.remove(i);
				return true;
			}
		}
		return false;
	}
	
	//Exclui Obra por localização
	public boolean excluiObraLocalizacao (String localizacao) {
		int size = this.obras.size();
		localizacao = localizacao.toUpperCase();
		
		for (int i=0; i<size; i++) {
			if (this.obras.get(i).getLocalizacao().equals(localizacao)) {
				this.obras.remove(i);
				return true;
			}
		}
		return false;
	}
	
}
