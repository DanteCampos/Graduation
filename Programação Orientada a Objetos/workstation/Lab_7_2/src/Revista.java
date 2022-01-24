import java.util.Observable;

public abstract class Revista extends Observable{
	public abstract void novaEdicao ();
	public abstract void setNome(String nome);
}
