
public class Livro {
	private String titulo;
	private int codigo;
	private Pessoa autor;
	private String editora;
	private int edicao;
	private int ano;
	private String local;
	private String genero;
	private static int qlivros=0;
	
	Livro(String titulo, int codigo, Pessoa autor){
		this.titulo = titulo;
		this.codigo = codigo;
		this.autor = autor;
		Livro.qlivros++;
	}
	public String toString() {
		return "Codigo: "+this.codigo+"\nTitulo: "+this.titulo+"\nGenero: "+this.genero+
				"\nReferencia: "+this.autor.nomeFormatado()+" "+this.titulo+". "+this.edicao+
				"a. edicao. "+this.local+", "+this.ano+".";
	}
	
	public String getTitulo() {
		return titulo;
	}
	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}
	public int getCodigo() {
		return codigo;
	}
	public void setCodigo(int codigo) {
		this.codigo = codigo;
	}
	public Pessoa getAutor() {
		return autor;
	}
	public void setAutor(Pessoa autor) {
		this.autor = autor;
	}
	public String getEditora() {
		return editora;
	}
	public void setEditora(String editora) {
		this.editora = editora;
	}
	public int getEdicao() {
		return edicao;
	}
	public void setEdicao(int edicao) {
		this.edicao = edicao;
	}
	public int getAno() {
		return ano;
	}
	public void setAno(int ano) {
		this.ano = ano;
	}
	public String getLocal() {
		return local;
	}
	public void setLocal(String local) {
		this.local = local;
	}
	public String getGenero() {
		return genero;
	}
	public void setGenero(String genero) {
		this.genero = genero;
	}
	public static int getQlivros() {
		return qlivros;
	}
	
}
