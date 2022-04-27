import java.awt.Component;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import java.util.ArrayList;
import javax.swing.*;




public class GUI extends JFrame {
	
	private JPanel panel = new JPanel();
	private JTextField inputField;
	private JButton EnterButton;
	private ArrayList<User> users= new ArrayList<User>();

	
	
	
	private Group group;
	private ClosedGroup privategroup;
	
	public GUI(ArrayList<User> list,Group g1,ClosedGroup g2)
	{
		inputField = new JTextField("Enter your name");
		EnterButton = new JButton("Enter");
		users=list;
		
		
		group=g1;
		privategroup=g2;
		
		
		// kataxwrhsh twn pediwn kai twn koumpiwn sto parathyro
		
		panel.add(inputField);
		panel.add(EnterButton);
	
		
		// epifaneia periexomenou
		this.setContentPane(panel);
		//xeirismos symvantwn gia to EnterButton
		ButtonListener listener = new ButtonListener();
		EnterButton.addActionListener(listener);
		
		
		this.setSize(500,200);
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
		boolean w= false;
		public void actionPerformed(ActionEvent e) {
			if(e.getSource().equals(EnterButton))
			{   User user = null;
				for(User s : users){
					if(inputField.getText().contains(s.getName()))
					        user=s;    
						w= true;}
				
				if(w)
				{   
					new PostGUI(user,users,group,privategroup);
					setVisible(false);
				}
				else
				{
					Component frame = null;
					JOptionPane.showMessageDialog(frame,
						    "User " + inputField.getText() + " not found.");
				}
				
			
			
		}
		
	}}
	

  












}
	

	
	
	
	
	

