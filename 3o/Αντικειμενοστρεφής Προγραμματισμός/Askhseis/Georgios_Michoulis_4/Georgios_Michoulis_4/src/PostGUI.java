
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import java.util.ArrayList;
import javax.swing.*;



public class PostGUI extends JFrame {
	  
	    private JPanel panel = new JPanel();
		private JTextField nameField;
		private JTextField emailField;
		private JTextField postField;
		private JButton BackButton;
		private JButton PostButton;
		private ArrayList<User> UserList= new ArrayList<User>();
		private User user;
		
		private ArrayList<Post> Order_post;
	   
		private JScrollPane scrollPane;
		private JLabel myLabel;
		private JList<String> Postedlist;
		private DefaultListModel<String> model2;
		private JScrollPane scrollPane2;
		private JLabel myLabel2;
		
		
		private JTextField nameofFriendField;
		
		private JButton addFriendButton;
		private JButton addGroupButton;
		private JList<String> GroupList;
		private DefaultListModel<String> modelgroup;
		
		
		private Group group;
		private ClosedGroup privategroup;
		
		public PostGUI(User u,ArrayList<User> usersList,Group g1,ClosedGroup g2)
		{   
			
			nameofFriendField=new JTextField(" Name of Friend ");
			nameField = new JTextField(u.getName());
			emailField=new JTextField(u.getEmail());
			postField=new JTextField(20);
			BackButton = new JButton("Back to login screen");
			PostButton=new JButton("Post");
			addFriendButton=new JButton("Add Friend");
			addGroupButton=new JButton("Add Group");
			UserList=usersList;
			user=u;
			Order_post = new ArrayList<Post>();
			
			
			group=g1;
			privategroup=g2;
			
			
			
			postField.setVisible(true);
			
		
			myLabel=new JLabel("Recent posts by friends");
			
			Postedlist= new JList<String>();
			model2 = new DefaultListModel<String>();
			Postedlist.setModel(model2);
		
			
			
			
			GroupList= new JList<String>();
		    modelgroup = new DefaultListModel<String>();
		    modelgroup.addElement(group.getName());
		    modelgroup.addElement(privategroup.getName());
			GroupList.setModel(modelgroup);
			
			Order_post = u.AllPosts();
			for(int i=0;i<Order_post.size();i++)
				  {
				Post post = Order_post.get(i);
				String Name = post.getUser().getName() + " " + post.getTimestamp().toString();
				model2.addElement(Name);
				String Keimeno = post.getPost();
				model2.addElement(Keimeno);
				  }
			scrollPane= new JScrollPane(postField);
		
			scrollPane2= new JScrollPane(Postedlist);
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			panel.setLayout(new GridLayout(2,3));
			panel.add(nameField);
			panel.add(emailField);
			panel.add(BackButton);
			
			panel.add(scrollPane);
			panel.add(PostButton);
			
			panel.add(myLabel);
			panel.add(scrollPane2);
			panel.add(myLabel2);
			
			panel.add(nameofFriendField);
			panel.add(addFriendButton);
			
			panel.add(GroupList);
			panel.add(addGroupButton);
		   
			
			this.setContentPane(panel);
			
			ButtonListener listener = new ButtonListener();
			BackButton.addActionListener(listener);
			PostButton.addActionListener(listener);
			addFriendButton.addActionListener(listener);
			addGroupButton.addActionListener(listener);
			
			//this.setExtendedState(JFrame.MAXIMIZED_BOTH);
			this.setSize(1200, 500);
			this.setTitle("Σελίδα Χρήστη");
			this.setVisible(true);
			this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	  
	  
}


		

		class ButtonListener implements ActionListener{

			
			public void actionPerformed(ActionEvent e) {
				if(e.getSource().equals(BackButton))
				{
					setVisible(false);
					new MainPageGUI(UserList,group,privategroup);
				}
				else if(e.getSource().equals(PostButton))
				{
					Post p= user.CreatePost(postField.getText());
					
					user.AddPost(p);
					model2.clear();
					Order_post = user.AllPosts();
					for(int i=0;i<Order_post.size();i++)
						  {
						Post post = Order_post.get(i);
						String Name = post.getUser().getName() + " " + post.getTimestamp().toString();
						model2.addElement(Name);
						String Keimeno = post.getPost();
						model2.addElement(Keimeno);
						  }
				}
				else if(e.getSource().equals(addFriendButton))
				{
					
					for(User s: UserList)
					{
						if(s.getName().equals(nameofFriendField.getText()))
						{
							user.addFriend(s);
							break;
						}
					}
					
					
				}
				else
				{
					String selectedGroupName = GroupList.getSelectedValue();
					
					if (group.getName().equals(selectedGroupName))
					{  
					    group.addaMember(user);}
					else
					   {
						privategroup.addaMember(user);
						}
					
					
				}
				
			}
			
		}
		
		
		

}
