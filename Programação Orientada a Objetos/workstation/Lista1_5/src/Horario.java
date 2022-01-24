
public class Horario {
	private int hora;
	private int minuto;
	private int segundo;
	
	Horario(int hora){
		this.hora = hora;
		this.segundo = this.minuto = 0;
	}
	Horario (int hora, int minuto, int segundo){
		this.segundo=segundo;
		this.minuto=minuto;
		this.hora=hora;
	}
	public void validaSegundo () {
		if (this.segundo < 60) return;
		else {
			int q = (int) (this.segundo/60);
			this.segundo %=60;
			this.minuto +=q;
			validaMinuto();
		}
	}
	public void validaMinuto () {
		if (this.segundo < 60) return;
		else {
			int q = (int) (this.minuto/60);
			this.minuto %=60;
			this.hora +=q;
			validaHora();
		}
	}
	public void validaHora () {
		this.hora %=24;
	}
	public void validaHorario() {
		this.validaSegundo();
		this.validaMinuto();
		this.validaHora();
	}
	public static int diferencaMinutos (Horario a, Horario b) {
		int minutosA=a.getMinuto()+(a.getHora()*60);
		int minutosB=b.getMinuto()+(b.getHora()*60);
		if (minutosA > minutosB) return minutosA-minutosB;
		else return minutosB-minutosA;
	}
	
	public String getHorario () {
		return this.hora+":"+this.minuto+":"+this.segundo;
	}
	public void setHorario(int segundo, int minuto, int hora) {
		this.segundo=segundo;
		this.minuto=minuto;
		this.hora=hora;
	}
	public int getHora() {
		return hora;
	}
	public void setHora(int hora) {
		this.hora = hora;
	}
	public int getSegundo() {
		return segundo;
	}
	public void setSegundo(int segundo) {
		this.segundo = segundo;
	}
	public int getMinuto() {
		return minuto;
	}
	public void setMinuto(int minuto) {
		this.minuto = minuto;
	}
	
	
}
