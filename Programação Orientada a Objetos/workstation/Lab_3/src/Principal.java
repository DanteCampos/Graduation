import java.util.ArrayList;
import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		
		ArrayList<Funcionario> listaFuncionarios = new ArrayList<Funcionario>() ;
		Scanner sc = new Scanner(System.in);
		
		int matricula;
		int cpf;
		String nome;
		String rua;
		int numero;
		int i=0;
		
		System.out.println("Digite a matricula:");
		while ( (matricula = Integer.parseInt(sc.nextLine())) != 0){
			
			System.out.println("Digite o CPF:");
			cpf = Integer.parseInt(sc.nextLine());
			System.out.println("Digite o nome:");
			nome = sc.nextLine();
			
			Funcionario funcionario1 = new Funcionario(nome, cpf, matricula);
			
			System.out.println("Digite o cargo:");
			funcionario1.setCargo(sc.nextLine());
			
			System.out.println("Digite o salario:");
			funcionario1.setSalario(Double.parseDouble(sc.nextLine()));
			
			System.out.println("Digite o departamento:");
			funcionario1.setDepartamento(sc.nextLine());
			
			System.out.println("Digite a rua:");
			rua = sc.nextLine();
			
			System.out.println("Digite o numero:");
			numero = Integer.parseInt(sc.nextLine());
			
			Endereco end = new Endereco(rua, numero);
			
			System.out.println("Digite o quadra:");
			end.setQuadra(Integer.parseInt(sc.nextLine()));
			
			System.out.println("Digite o lote:");
			end.setLote(Integer.parseInt(sc.nextLine()));
			
			System.out.println("Digite a complemento:");
			end.setComplemento(sc.nextLine());
			
			System.out.println("Digite a bairro:");
			end.setBairro(sc.nextLine());
			
			System.out.println("Digite a cidade:");
			end.setCidade(sc.nextLine());
			
			System.out.println("Digite a estado:");
			end.setEstado(sc.nextLine());
			
			funcionario1.setEndereco(end);
			
			listaFuncionarios.add (funcionario1);
			i++;
			System.out.println("Digite a matricula:");
		}
		
		for (int a = 0; a<i; a++){
			System.out.println("Funcionario "+(a+1));
			System.out.println(listaFuncionarios.get(a).mostraDados() );
		}
		
		for (int a = 0; a<i; a++){
			listaFuncionarios.get(a).aumentaSalario(30.00);
		}
		
		for (int a = 0; a<i; a++){
			System.out.println("Funcionario "+(a+1));
			System.out.println(listaFuncionarios.get(a).mostraDados() );
		}
		

	}

}
