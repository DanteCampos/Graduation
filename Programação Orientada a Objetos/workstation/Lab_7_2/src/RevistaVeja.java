public class RevistaVeja extends Revista{
	String nome;
	int edicao;
	
	public RevistaVeja(String nome, int edicao){
		this.nome=nome;
		this.edicao = edicao;
	}
	
	private void atualiza(Object o) {
		setChanged();
		notifyObservers(o);
		System.out.println("");
	}
	
	public void novaEdicao (){
		this.edicao++;
		System.out.println("Saiu a edição "+this.edicao+" da "+this.nome+"!\n");
		atualiza(this.edicao);
	}
	
	public String getNome() {
		return this.nome;
	}
	
	public void setNome(String nome) {
		System.out.println("A revista "+this.nome+" agora se chama "+nome+"!\n");
		this.nome = nome;
		atualiza (this.nome);
	}
}
