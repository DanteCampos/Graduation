import java.util.ArrayList;
import javax.swing.JOptionPane;

public class Principal {

	public static void main(String[] args) {
		ArrayList <Livro> livros = new ArrayList<Livro>();
		
		int codigo;
		String titulo;
		String nome;
		String nomeintermed;
		String sobrenome;
		String genero;
		
		while (true) {
			codigo = Integer.parseInt(JOptionPane.showInputDialog("Digite o codigo do livro (0 termina o programa)"));
			if (codigo == 0) break;
			
			titulo = JOptionPane.showInputDialog("Digite o titulo do livro");
			nome = JOptionPane.showInputDialog("Digite o primeiro nome do autor");
			nomeintermed = JOptionPane.showInputDialog("Digite o nome do meio do autor");
			sobrenome = JOptionPane.showInputDialog("Digite o ultimo nome do autor");
			
			Pessoa autor = new Pessoa (nome, nomeintermed, sobrenome);
			Livro livro = new Livro(titulo, codigo, autor);
			
			livro.setAno(Integer.parseInt(JOptionPane.showInputDialog("Digite o ano de lancamento do livro")));
			livro.setEdicao(Integer.parseInt(JOptionPane.showInputDialog("Digite a edicao do livro")));
			livro.setEditora(JOptionPane.showInputDialog("Digite a editora do livro"));
			genero=(JOptionPane.showInputDialog("Digite o genero do livro"));
			livro.setGenero(genero);
			livro.setLocal(JOptionPane.showInputDialog("Digite o local do livro"));
			livros.add(livro);
			Genero.verifica(genero);
		}
		
		JOptionPane.showMessageDialog(null, "Total de livros cadastrados: "+Livro.getQlivros());
		for (int i=0; i < Livro.getQlivros(); i++) JOptionPane.showMessageDialog(null, livros.get(i).toString());
		
		for (int i=0; i < Genero.totaldegeneros; i++) JOptionPane.showMessageDialog(null, "Genero: "+
		Genero.listadegeneros.get(i).getNome()+"\n"+Genero.listadegeneros.get(i).getQuantidade()+
		" livros");
	}

}
