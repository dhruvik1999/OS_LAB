//program for server application 
import java.rmi.*; 
import java.rmi.registry.*; 
public class SearchServer 
{ 
	public static void main(String args[]) 
	{ 
		try
		{ 
			Search obj = new SearchQuery(); 
			LocateRegistry.createRegistry(1910); 
			Naming.rebind("rmi://localhost:1910"+ 
						"/nitk",obj); 
		} 
		catch(Exception ae) 
		{ 
			System.out.println(ae); 
		} 
	} 
} 
