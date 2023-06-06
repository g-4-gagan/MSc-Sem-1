package p2;
import p1.ConstructorExample;

public class Demo1 extends ConstructorExample{

	public int sum(int a, int b){
		System.out.println("The sum of two numbers will be: "+(a+b));
	}

	public static void main(String[] args) {

		ConstructorExample obj1 = new ConstructorExample();
		obj1.somefunction();
		
		System.out.println("Demo1 class main function");
	}
}