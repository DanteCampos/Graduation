import java.text.DecimalFormat;
import java.util.InputMismatchException;

import javax.swing.JOptionPane;

public class Principal {

	public static void main(String[] args) {
	
		try {
			DecimalFormat dc = new DecimalFormat("0,00");
			Calc c = new Calc();
	
			c.n1 = Integer.parseInt(JOptionPane.showInputDialog(null,
					"Entre com o primeiro número:"));
			
			if (c.n1 < 0) throw new NumeroNegativo ("Número negativo");
			
			c.n2 = Integer.parseInt(JOptionPane.showInputDialog(null,
					"Entre com o segundo número:"));
			
			if (c.n2 < 0) throw new NumeroNegativo ("Número negativo");
			
			JOptionPane.showMessageDialog(null,
					"Soma : " + dc.format(c.somar()));
			JOptionPane.showMessageDialog(null,
					"Subtração : " + dc.format(c.diminuir()));
			JOptionPane.showMessageDialog(null,
					"Multiplicação : " + dc.format(c.multiplicar()));
			JOptionPane.showMessageDialog(null,
					"Divisão : " + dc.format(c.dividir()));
		}catch(ArithmeticException ae) {
			System.out.println("Erro divisão por zero");
		}catch (InputMismatchException ime) {
			System.out.println("Entrada de dados inválida");
		}catch (NumberFormatException nfe) {
			System.out.println("Valor inválido");
		}catch (NumeroNegativo nn) {
			System.out.println("Entrada de número negativo");
		}
	}
}
