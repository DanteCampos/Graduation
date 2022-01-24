
public class Produto {
	
	int codigo, quantidade;
	float preco;
	String nome, tipo;
	
	void vender (int q){
		if (this.quantidade < q){
			System.out.println ("Estoque insuficiente!");
			return;
		}
		
		if (this.preco == 0) {
			System.out.println("Produto sem preco!");
			return;
		}
		
		this.quantidade -= q;
		System.out.println("Valor da venda: " + (q*this.preco));
		return;
	}
	
	void comprar (int q) {
		this.quantidade += q;
	}
	void comprar (int q, float p) {
		this.preco = p;
		this.quantidade += q;
	}
	
	void consultar () {
		System.out.println("Produto:\n\nNome: " + this.nome + "\nCodigo: " + this.codigo + "\nQuantidade em estoque: " + this.quantidade + "\nPreco: " + this.preco);
	}
	
	void inserir (String n, int q, String t, float p) {
		this.nome = n;
		this.quantidade = q;
		this.tipo = t;
		this.preco = p;
	}
	
	boolean igual (Produto outrop){
		if (!(this.nome.equals(outrop.nome))) return false;
		if (!(this.tipo.equals(outrop.tipo))) return false;
		return true;
	}

	Produto (int c){
		this.codigo = c;
		this.nome = "Sem nome";
		this.quantidade = 0;
		this.tipo = "Sem tipo";
		this.preco = 0;
	}
	Produto (int c, String n){
		this.codigo = c;
		this.nome = n;
		this.quantidade = 0;
		this.tipo = "Sem tipo";
		this.preco = 0;
	}
	Produto (int c, String n, int q){
		this.codigo = c;
		this.nome = n;
		this.quantidade = q;
		this.tipo = "Sem tipo";
		this.preco = 0;
	}
	Produto (int c, String n, int q, String t, float p){
		this.codigo = c;
		this.nome = n;
		this.quantidade = q;
		this.tipo = t;
		this.preco = p;
	}
}