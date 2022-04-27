import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.io.*;
import java.util.*;






public class Main{
   public static void main( String[] args)
   {
	    
	   	User u1 = new User("Makis", "it1698@uom.edu.gr");
		User u2 = new User("Petros","it1624@uom.edu.gr");
		User u3 = new User("Maria", "it16112@uom.edu.gr");
		User u4 = new User("Gianna","it16133@uom.edu.gr");
		User u5 = new User("Nikos", "it1658@uom.edu.gr");
		User u6 = new User("Babis", "it16104@uom.edu.gr");
	
	   
		ArrayList<User> users = new ArrayList<User>();
		users.add(u1);
		users.add(u2);
		users.add(u3);
		users.add(u4);
		users.add(u5);
		users.add(u6);
	  
		
		Group g1 = new Group ("WebGurus","A group for web passionates");
		ClosedGroup g2 = new ClosedGroup("ExamSolutions","Solutions to common exam questions");
   
   
		u1.addFriend(u2); 
		u1.addFriend(u2);
		u1.addFriend(u5);
		u5.addFriend(u6);
		u3.addFriend(u4);
		u3.addFriend(u2);
		u4.addFriend(u6);
		u5.addFriend(u3);
		u1.addFriend(u6);
		u5.addFriend(u2);
        
		u1.PrintCommonFriends(u5);
		u5.PrintCommonFriends(u4);
        u1.PrintFriendsOfUser(u1);
       u3.PrintFriendsOfUser(u3);
        
        
		g1.addaMember(u4);
		g1.addaMember(u3);
		g1.addaMember(u2);
		g2.addaMember(u4);
		g2.addaMember(u5);
		g2.addaMember(u6);
		g2.addaMember(u5);
		
		
		
		u4.PrintJoinedGroups();
		
		g1.PrintGroupMembers();
		g2.PrintGroupMembers();
		  
		Post p1 = u3.CreatePost("Ξερουμε αμα λειτουργησει το Πανεπιστημιο με τετοιο κρυο?\n");
		Post p2 = u5.CreatePost("Επιτελους ειδαμε μια ασπρη μερα");
		
		
		
		
		
		Post p3 = u2.CreatePost("Πολυ χιονισε σημερα!");
		
		u3.AddPost(p1);
		
		
		
		u5.AddPost(p2);
		
		
		
		u2.AddPost(p3);
		
		
		
			u1.PrintJoinedGroups();
			
			
			u4.PrintJoinedGroups();
			u5.PrintJoinedGroups();
			u6.PrintJoinedGroups();
		
		
		
		
		
		try {
			FileOutputStream fileOut = new FileOutputStream("user.ser");
			ObjectOutputStream out = new ObjectOutputStream(fileOut);
			
			out.close();
			fileOut.close();		
		}
		catch(IOException i) {
			i.printStackTrace();
		}
		
		
		
		
		
		
		new MainPageGUI(users,g1,g2);
	    
		
		
		
   
   
   
   
   }
   
  
	}
   
   
   
   
   
   
   
   
   
   

