import java.util.ArrayList;

public class Musica {
	private String nome;
	private int ano;
	private String tipo;
	private ArrayList <Compositor> compositores = new ArrayList<Compositor>();
	private int qcompositores;
	
	Musica(String nome){
		this.setNome(nome);
		this.qcompositores=0;
	}
	
	public String toString() {
		String str;
		str = ("Musica: "+this.nome+"\nAno: "+this.ano+"\nTipo: "+this.tipo+"\nCompositores: ");
		str += (this.compositores.get(0).toString());
		for (int i=1; i < this.qcompositores; i++) str += ", "+this.compositores.get(i).toString();
		return str;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public int getAno() {
		return ano;
	}

	public void setAno(int ano) {
		this.ano = ano;
	}

	public String getTipo() {
		return tipo;
	}

	public void setTipo(String tipo) {
		this.tipo = tipo;
	}

	public ArrayList <Compositor> getCompositores() {
		return compositores;
	}

	public void setCompositores(Compositor compositor) {
		this.compositores.add(compositor);
		this.qcompositores++;
	}
}
