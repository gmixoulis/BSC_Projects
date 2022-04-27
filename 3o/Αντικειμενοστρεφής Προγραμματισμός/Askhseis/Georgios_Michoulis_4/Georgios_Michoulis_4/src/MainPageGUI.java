
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;


import javax.swing.JButton;
import javax.swing.JFrame;

import javax.swing.JPanel;
import javax.swing.JTextField;


public class MainPageGUI extends JFrame {
	private JPanel panel = new JPanel();
	private JTextField nameField;
	private JTextField emailField;
	private JButton CreateUserButton;
	private JButton EnterButton;
	private JButton FileButton;
	private ArrayList<User> users= new ArrayList<User>();

	
	private Group group;
	private ClosedGroup privategroup;
	
	
	
	public MainPageGUI(ArrayList<User> list,Group g1,ClosedGroup g2) {
		nameField = new JTextField("ονομα χρηστη");
		emailField = new JTextField("email χρηστη");
		CreateUserButton = new JButton("Δημιουργια Χρηστη");
		EnterButton = new JButton("Εισοδος χρηστη");
		FileButton = new JButton("Αποθηκευση PamakBook");
		users=list;
		
		
		
		group=g1;
		privategroup=g2;
		
		// kataxwrhsh twn pediwn kai twn koumpiwn sto parathyro
		
		panel.add(CreateUserButton);
		panel.add(nameField);
		panel.add(emailField);
		
		
		panel.add(EnterButton);
		panel.add(FileButton);
	
		
		// epifaneia periexomenou
		this.setContentPane(panel);
		//xeirismos symvantwn gia to EnterButton
		ButtonListener listener = new ButtonListener();
		EnterButton.addActionListener(listener);
		CreateUserButton.addActionListener(listener);
		FileButton.addActionListener(listener);
		
		
		
		this.setSize(400,170);
		this.setTitle("Είσοδος Χρήστη");
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		
		
	}
	
	class ButtonListener implements ActionListener{
        /* xeirismos symvantwn gia to koumpi Enter 
         * to opoio ama einai swsto to onoma p tha dextei
         * tote tha emfanisei to deytero parathyro aliws 
         * tha emfanistei ena error mynhma
         */
		boolean w= true;
		public void actionPerformed(ActionEvent e) {
			if(e.getSource().equals(CreateUserButton))
			{ 
				for(User s : users){
					if(nameField.getText().equals(s.getName()))
					       w=false; break;
					      
						}
				    
			     if(w)
			     {
			    	User u1= new User(nameField.getText(),emailField.getText());
			    	u1.addUser();
			    	users.add(u1);
			     }
			     else
			    	 System.out.println("This user is allready exist");
			}
			     
		  else if(e.getSource().equals(EnterButton))
		  {
			  new GUI(users,group,privategroup);
			  setVisible(false);
		  }
		  else
		  {
			  SerializationDemo demo = new SerializationDemo(users,group,privategroup);
			  System.out.println("your file has been saved");
		  }
			    	
			
		}
		
	}}
