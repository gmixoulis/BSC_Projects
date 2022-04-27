import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;


public class SerializationDemo {
	
	private ArrayList<User> employees = new ArrayList<User>();
	private Group group;
	private ClosedGroup privategroup;
	
	
	public SerializationDemo(ArrayList<User> users, Group g1,ClosedGroup g2) {
		employees=users;
		group =g1;
		privategroup = g2;
		
		serializing();
		
		ArrayList<User> employeesFromFile = deserializing();
		
		for(User e: employeesFromFile) {
			e.PrintPosts();
			e.PrintSuggestedFriend();
			e.PrintJoinedGroups();
			e.PrintFriendsOfUser(e);
		}
		
	
	}
	
	public void serializing() {
		try {
			FileOutputStream fileOut = new FileOutputStream("user.ser");
			ObjectOutputStream out = new ObjectOutputStream(fileOut);
			out.writeObject(employees);
			out.close();
			fileOut.close();		
		}
		catch(IOException i) {
			i.printStackTrace();
		}
		finally {
			System.out.println("Serialization Attempted...");
		}
		
	}
	
	public ArrayList<User> deserializing() {
		try {
			FileInputStream fileIn = new FileInputStream("user.ser");
			ObjectInputStream in = new ObjectInputStream(fileIn);
			ArrayList<User> employees = (ArrayList<User>) in.readObject();
			in.close();
			fileIn.close();		
		}
		catch(IOException i) {
			i.printStackTrace();
		}
		catch(ClassNotFoundException c) {
			c.printStackTrace();
		}
		finally {
			System.out.println("De-Serialization Attempted...");
			return employees;
		}
		
	}
	


}
