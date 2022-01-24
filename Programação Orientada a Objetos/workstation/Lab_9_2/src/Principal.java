import java.text.DecimalFormat;
import java.util.InputMismatchException;

import javax.swing.JOptionPane;

public class Principal {

	public static void main(String[] args) {
	
		try {
			DecimalFormat dc = new DecimalFormat("0,00");
			Calc c = new Calc();
	
			c.n1 = Integer.parseInt(JOptionPane.showInputDialog(null,
					"Entre com o primeiro n�mero:"));
			
			if (c.n1 < 0) throw new NumeroNegativo ("N�mero negativo");
			
			c.n2 = Integer.parseInt(JOptionPane.showInputDialog(null,
					"Entre com o segundo n�mero:"));
			
			if (c.n2 < 0) throw new NumeroNegativo ("N�mero negativo");
			
			JOptionPane.showMessageDialog(null,
					"Soma : " + dc.format(c.somar()));
			JOptionPane.showMessageDialog(null,
					"Subtra��o : " + dc.format(c.diminuir()));
			JOptionPane.showMessageDialog(null,
					"Multiplica��o : " + dc.format(c.multiplicar()));
			JOptionPane.showMessageDialog(null,
					"Divis�o : " + dc.format(c.dividir()));
		}catch(ArithmeticException ae) {
			System.out.println("Erro divis�o por zero");
		}catch (InputMismatchException ime) {
			System.out.println("Entrada de dados inv�lida");
		}catch (NumberFormatException nfe) {
			System.out.println("Valor inv�lido");
		}catch (NumeroNegativo nn) {
			System.out.println("Entrada de n�mero negativo");
		}
	}
}
