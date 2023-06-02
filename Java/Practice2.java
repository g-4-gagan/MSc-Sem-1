import java.util.Scanner;
import java.lang.String;

public class Practice2{
	public static void main(String[] args) {
		int a = 34;
		double b = a;
		System.out.println(a+"\t"+b);
		double d = 34.6;
		a = (int)d;
		System.out.println(d+"\t"+a);
		String s1 = "52";
		a = Integer.parseInt(s1);
		System.out.println(a);
		char c1 = 'a';
		a = c1;
		System.out.println(a+"\t"+c1);
		a = 104;
		c1 = (char)a;
		System.out.println(a+"\t"+c1);
		char c3 = 69;
		System.out.println(c3);
		a = 129;
		byte b1 = (byte)a;
		System.out.println(b1);
		boolean b2 = true;
		System.out.println(b2);
		a = 65535+66;
		char c4 = (char)a;
		System.out.println(c4);
		float f1 = 10.11f;
		a = (int)f1;
		System.out.println(a+"\t"+f1);
		short s2 = 10;
		s2 = (short)(s2+10);
		System.out.println(s2);

	}
}