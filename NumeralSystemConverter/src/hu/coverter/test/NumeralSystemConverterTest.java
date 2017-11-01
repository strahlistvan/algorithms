package hu.coverter.test;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import hu.converter.source.NumeralSystemConverter;

public class NumeralSystemConverterTest {

	@Before
	public void setUp() throws Exception {
	}

	@Test
	public void isDigitInRadixTest() {
		assertTrue("F symbol must be in base 16", NumeralSystemConverter.isDigitInRadix('F', 16));
		assertFalse("G symbol can not in base 16", NumeralSystemConverter.isDigitInRadix('G', 16));

		assertTrue("0 symbol must be in base 2", NumeralSystemConverter.isDigitInRadix('0', 2));
		assertTrue("1 symbol must be in base 2", NumeralSystemConverter.isDigitInRadix('1', 2));
		assertFalse("2 symbol can not in base 2", NumeralSystemConverter.isDigitInRadix('2', 2));
		
	}


	@Test
	public void getNumericValueTest() {

		assertEquals("A symbol value must be 10", 10, NumeralSystemConverter.getNumericValue('A'));
		assertEquals("F symbol value must be 15", 15, NumeralSystemConverter.getNumericValue('F'));
		assertEquals("0 symbol value must be 0", 0, NumeralSystemConverter.getNumericValue('0'));
		assertEquals("9 symbol value must be 9", 9, NumeralSystemConverter.getNumericValue('9'));				
	}	
	
	
}
