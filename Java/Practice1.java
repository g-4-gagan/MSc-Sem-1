import java.lang.String;
import java.util.Scanner;

public class Practice1{
	public static void main(String[] args) {
		String a = "Hello World";
		String b = "Hello World";
		String c = new String("Hello World");
		System.out.println(System.identityHashCode(a));
		System.out.println(System.identityHashCode(b));
		System.out.println(System.identityHashCode(c));
	}
}