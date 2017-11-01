package hu.converter.source;

public class Main {

	public static void main(String[] args) {
		try {
			String num;
			
			num = NumeralSystemConverter.convertNum("11234", 11, 10);
			System.out.println(num);
			num = NumeralSystemConverter.convertNum("11234", 10, 10);
			System.out.println(num);
			num = NumeralSystemConverter.convertNum("11234", 10, 7);
			System.out.println(num);			
			num = NumeralSystemConverter.convertNum("100000000", 2, 10);
			System.out.println(num);			
			num = NumeralSystemConverter.convertNum("11111111", 2, 16);
			System.out.println(num);			
			num = NumeralSystemConverter.convertNum("11111111", 16, 2);
			System.out.println(num);			
			num = NumeralSystemConverter.convertNum("31", 8, 10);
			System.out.println(num);

		} catch (InvalidNumberFormatException ex) {
			ex.printStackTrace();
		}
	}
	

}
