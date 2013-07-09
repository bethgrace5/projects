import java.util.Scanner;
import java.net.*;
import java.io.IOException;

public class readWebPage{

public static void main(String[] args)throws IOException{

String address = "http://www.google.com";

URL pageLocation = new URL(address);

Scanner in = new Scanner(pageLocation.openStream());
	String word = in.next();
	boolean found  = false;
	while(in.hasNextLine() && !found){
	//if(word.substring(0,2)=="<a"){
	System.out.print(in.nextLine());
	//found=true;
	//}
}
}

}
