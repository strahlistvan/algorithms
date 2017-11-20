# Numeral System Converter

A Numeral System Converter static class, written in Java programming language.
It converts given numeric Strings from a given base to any natural base numeral system. 

## Usage

Simply compile NumeralSystemConverter.java , and don't forget to add NumeralSystemConverter to your classpath!

```
String number = "11111111";
Integer sourceRadix = 2, destRadix = 16;
String result = NumeralSystemConverter.convertNum(number, sourceRadix, destRadix);
```

## Webservice Usage

1. Compile and run hu.converter.webservice.NumeralSystemConverterEndpoint class as a web server
2. Open http://localhost:9876/my/little/converter?wsdl for the WSDL XML document.
3. Use the service from your client. For example:  use wsimport to get Service Java classes, or the SoapClient class to use it from PHP scripts.
