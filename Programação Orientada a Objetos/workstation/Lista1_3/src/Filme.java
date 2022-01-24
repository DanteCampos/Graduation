
public class Filme extends Item{
	private String diretor;
	
	public String toString() {
		return "Filme: "+super.toString()+"\n"+this.diretor;
	}

	public String getDiretor() {
		return diretor;
	}
	public void setDiretor(String diretor) {
		this.diretor = diretor;
	}
}
