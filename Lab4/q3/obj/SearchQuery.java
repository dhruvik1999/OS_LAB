
import java.rmi.*; 
import java.rmi.server.*; 
interface Search extends Remote 
{ 
	public String query(String search) throws RemoteException; 
} 
public class SearchQuery extends UnicastRemoteObject 
						implements Search 
{  
	SearchQuery() throws RemoteException 
	{ 
		super(); 
	} 

	public String query(String search) 
					throws RemoteException 
	{ 
		String result; 
		if (search.equals("Reflection in Java")) 
			result = "Found"; 
		else
			result = "Not Found"; 

		return result; 
	} 
} 
