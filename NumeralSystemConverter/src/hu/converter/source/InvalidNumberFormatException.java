package hu.converter.source;

public class InvalidNumberFormatException extends Exception {

	
	private static final long serialVersionUID = 1L;

	public InvalidNumberFormatException() {
		super();
	}
	public InvalidNumberFormatException(String message) {
		super(message);
	}

	public InvalidNumberFormatException(Throwable cause) {
		super(cause);
	}

	public InvalidNumberFormatException(String message, Throwable cause) {
		super(cause);
	}
	
	
}
