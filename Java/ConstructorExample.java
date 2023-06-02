package p1;

//access modifier types: private, default, protected, public 

class Parentclass{

	void randomfunction(){
		System.out.println("Random Output");
	}

	public static void main(String[] args) {
		System.out.println("Hello");
	}
}

public class ConstructorExample extends Parentclass{

	public ConstructorExample(){
		System.out.println("This is normal constructor for the class");
	}

	ConstructorExample(int someNumber){
		System.out.println("Parameter for the constructor: "+someNumber);
	}

	public void somefunction(){
		System.out.println("We are inside some function");
	}

	public static void main(String[] args) {

		ConstructorExample obj1 = new ConstructorExample();
		ConstructorExample obj2 = new ConstructorExample(23);
		obj1.somefunction();

		System.out.println("Hello World");
	}
}
