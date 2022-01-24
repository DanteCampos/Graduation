
public class Jogo extends Item{
	private int njogadores;
	private String plataforma;
	
	public String toString() {
		return "Jogo: "+super.toString()+"\n"+this.njogadores+" jogadores";
	}
	
	public int getNjogadores() {
		return njogadores;
	}
	public void setNjogadores(int njogadores) {
		this.njogadores = njogadores;
	}
	public String getPlataforma() {
		return plataforma;
	}
	public void setPlataforma(String plataforma) {
		this.plataforma = plataforma;
	}
}
