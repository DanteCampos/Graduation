
public class Filme {
	private int codigo;
	private String nome;
	private String genero;
	private int ano;
	private String ator;
	private static int total=0; 
	
	Filme(int codigo, String nome){
		this.nome = nome;
		this.codigo = codigo;
		Filme.setTotal(Filme.getTotal() + 1);
	}
	
	public String toString () {
		return this.codigo+"\n"+this.nome+"\n"+this.genero+"\n"+this.ano+"\n"+this.ator;
	}
	
	public int getCodigo() {
		return codigo;
	}
	public void setCodigo(int codigo) {
		this.codigo = codigo;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public String getGenero() {
		return genero;
	}
	public void setGenero(String genero) {
		this.genero = genero;
	}
	public int getAno() {
		return ano;
	}
	public void setAno(int ano) {
		this.ano = ano;
	}
	public String getAtor() {
		return ator;
	}
	public void setAtor(String ator) {
		this.ator = ator;
	}

	public static int getTotal() {
		return total;
	}
	private static void setTotal(int total) {
		Filme.total = total;
	}
	
}
