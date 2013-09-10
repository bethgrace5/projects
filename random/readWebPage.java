package random;

import java.util.Scanner;
import java.net.*;
import java.io.IOException;

public class readWebPage{

public static void main(String[] args) throws IOException{
String address = "http://api.wunderground.com/api/c6c6d53295b46eb6/conditions/q/CA/San_Francisco.json";

URL pageLocation = new URL(address);
//TODO: look into JSON, and how to interpret it via GSON (https://code.google.com/p/google-gson/)
Scanner in = new Scanner(pageLocation.openStream());
	while(in.hasNextLine()){
	System.out.println(in.nextLine());
		}
	in.close();
	}

}
