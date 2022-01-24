import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int segundo, minuto, hora;
		
		System.out.println("Digite o primeiro horario separando hora, minuto e segundo por espacos:\n");
		hora = sc.nextInt();
		minuto = sc.nextInt();
		segundo = sc.nextInt();
		sc.nextLine();
		Horario a = new Horario(hora, minuto, segundo);
		a.validaHorario();
		
		System.out.println("Digite o segundo horario separando hora, minuto e segundo por espacos:\n");
		hora = sc.nextInt();
		minuto = sc.nextInt();
		segundo = sc.nextInt();
		sc.nextLine();
		Horario b = new Horario(hora, minuto, segundo);
		b.validaHorario();
		
		System.out.println("Horario 1: "+a.getHorario()+"\nHorario 2: "+b.getHorario()+
				"\nDiferenca entre os horarios: "+Horario.diferencaMinutos(a, b)+" minutos\n");
		
	}

}
