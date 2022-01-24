
public class CD extends Item{
	private String artista;
	private int qfaixas;
	
	public String toString() {
		return "CD: "+super.toString()+"\n"+this.artista+"\n"+this.qfaixas+" faixas";
	}
	
 	public int getQfaixas() {
		return qfaixas;
	}
	public void setQfaixas(int qfaixas) {
		this.qfaixas = qfaixas;
	}
	public String getArtista() {
		return artista;
	}
	public void setArtista(String artista) {
		this.artista = artista;
	}
}
