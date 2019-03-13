//program for client application 
import java.rmi.*; 
public class ClientRequest 
{ 
	public static void main(String args[]) 
	{ 
		String answer,value="Reflection irerwanksdn Java"; 
		try
		{ 
			// lookup method to find reference of remote object 
			Search access = 
				(Search)Naming.lookup("rmi://localhost:1910"+ 
									"/nitk"); 
			answer = access.query(value); 
			System.out.println("Article on " + value + 
							" " + answer+" at nitk"); 
		} 
		catch(Exception ae) 
		{ 
			System.out.println(ae); 
		} 
	} 
} 
