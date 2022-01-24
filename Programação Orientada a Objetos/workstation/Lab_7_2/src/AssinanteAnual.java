import java.util.Observable;

public class AssinanteAnual implements Assinante{
	private int numero;
	
	public AssinanteAnual (int num){
		this.numero=num;
	}
	
	public void update(Observable revista, Object o) {
		if (o instanceof String) System.out.println("Assinante Anual "+this.numero+" observou o novo nome da revista agora chamada "+o+"!");
		else System.out.println("Assinante Anual "+this.numero+" observou a nova edição "+o+" da "+((RevistaVeja)revista).getNome()+"!");
	}
}
