/**
 * 
 */
package hu.converter.webservice;

import hu.converter.source.InvalidNumberFormatException;

/**
 * @author strahl
 *
 */
public interface NumeralSystemConverter {
	
	public String convertNum(String numberString, 
						     Integer sourceRadix, 
						     Integer destRadix)
	throws InvalidNumberFormatException;

}
