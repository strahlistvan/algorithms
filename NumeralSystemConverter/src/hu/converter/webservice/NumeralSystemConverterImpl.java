package hu.converter.webservice;

import javax.jws.*;

import hu.converter.source.InvalidNumberFormatException;

@WebService
public class NumeralSystemConverterImpl implements NumeralSystemConverter {

	public NumeralSystemConverterImpl() {
		super();
	}

	@Override
	public String convertNum(@WebParam(name="number") String numberString, 
							 @WebParam(name="source_radix") Integer sourceRadix, 
							 @WebParam(name="dest_radix")  Integer destRadix)
	throws InvalidNumberFormatException 
	{
		return hu.converter.source.NumeralSystemConverter.convertNum(numberString, 
                                                                     sourceRadix, 
                                                                     destRadix);
	}

}
