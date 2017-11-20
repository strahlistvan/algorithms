package hu.converter.webservice;

import javax.xml.ws.Endpoint;

public class NumeralSystemConverterEndpoint {

	private static String url = "http://localhost:9876/my/little/converter";
	
	public static void main(String[] args) {
		System.out.println("Publishing webservice to URL: " + url);
		System.out.println("WSDL URL:" + url + "?wsdl");
		Endpoint.publish(url, new NumeralSystemConverterImpl());
		System.out.println("Done...");
	}

}
