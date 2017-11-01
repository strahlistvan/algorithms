package hu.converter.source;
import java.math.BigInteger;

public class NumeralSystemConverter {
	
	protected static boolean isDigitInRadixBelow10(char digit, int radix) {
		return digit >= '0' && digit < '0'+radix;
	}

	protected static boolean isDigitInRadixAtLeast10(char digit, int radix) {
		if (digit >= '0' && digit <= '9') {
			return true;
		}
		
		if (Character.toUpperCase(digit) >= 'A' 
			&& Character.toUpperCase(digit) <= 'A'+radix-11 ) {
			return true;
		}
		
		return false;
	}	
	
	public static boolean isDigitInRadix(char digit, int radix) {
		if (radix < 2) 
			return false;
		
		return (radix < 10) ? isDigitInRadixBelow10 (digit, radix) 
							: isDigitInRadixAtLeast10(digit, radix);
	}
	
	public static boolean isNumberInRadix(String numberString, int radix) {
		
		for (int i=0; i<numberString.length(); ++i) {
			if (!isDigitInRadix(numberString.charAt(i), radix)) {
				return false;
			}
		}
		return true;
	}
	
	public static int getNumericValue(char digit) {
		if (digit >= '0' && digit <= '9')
			return digit - '0';
		else 
			return Character.toUpperCase(digit) - 'A' + 10;
	}

	public static BigInteger convertStringToDecimalInteger(String numberString, Integer radix) {
		
		BigInteger decimalValue = new BigInteger("0");
		BigInteger multiplier = new BigInteger("1");

				
		for (int i=numberString.length()-1; i>=0; --i) {
			
			BigInteger digit = BigInteger.valueOf(getNumericValue(numberString.charAt(i)));
			// System.out.println("digit " + digit.toString());
			
			digit = digit.multiply(multiplier);
			
			decimalValue = decimalValue.add(digit);
			// System.out.println("decimalValue " + decimalValue.toString());
			
			multiplier = multiplier.multiply(new BigInteger(radix.toString()));
			// System.out.println("multiplier " + multiplier.toString());

		}
		
		return decimalValue;
		
	}
	
	public static char getValueSymbol(Integer value) {
		if (value >= 0 && value <= 9)
			return  (char) (value + '0');
		else 
			return (char) (value-10+'A');
	}

	public static String convertDecimalDigitToString(BigInteger decimalValue, Integer radix) {
		
		final BigInteger radixBigInt = new BigInteger(radix.toString());
		
		String convertedNumberStr = "";
		StringBuilder convertedNumberBuilder = new StringBuilder();
		
		while (!decimalValue.equals(new BigInteger("0"))) {
			Integer remainder = decimalValue.mod(radixBigInt).intValue();
			
			convertedNumberBuilder.append(getValueSymbol(remainder));
			
			decimalValue = decimalValue.divide(radixBigInt);
			// System.out.println(decimalValue);
			
		}
		convertedNumberStr = convertedNumberBuilder.reverse().toString();
		//System.out.println(convertedNumberStr);
		
		return convertedNumberStr;

	}
	
	public static String convertNum(String numberString, Integer sourceRadix, Integer destRadix) 
			throws InvalidNumberFormatException
	{	

		numberString = numberString.toUpperCase().trim();
		
		if (!isNumberInRadix(numberString, sourceRadix)) {
			throw new InvalidNumberFormatException(numberString + " not in base " + sourceRadix + "!");
		}

		BigInteger decimalValue = convertStringToDecimalInteger(numberString, sourceRadix);		
		String convertedNumberStr = convertDecimalDigitToString(decimalValue, destRadix);
		return convertedNumberStr;
	}

}
