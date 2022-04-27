import java.awt.Component;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import java.util.ArrayList;
import javax.swing.*;
import java.util.Date;

public class PostGUI extends JFrame {

	private JPanel panel = new JPanel();
	private JTextField nameField;
	private JTextField emailField;
	private JTextField postField;
	private JButton BackButton;
	private JButton PostButton;
	private ArrayList<User> UserList = new ArrayList<User>();
	private User user;
	private JList<String> Postlist;

	private JScrollPane scrollPane;
	private JLabel myLabel;
	private JList<String> Postedlist;
	private DefaultListModel<String> model2;
	private JScrollPane scrollPane2;
	private JLabel myLabel2;

	public PostGUI(User u, ArrayList<User> usersList) {
		nameField = new JTextField(u.getName());
		emailField = new JTextField(u.getEmail());
		postField = new JTextField(20);
		BackButton = new JButton("Back to login screen");
		PostButton = new JButton("Post");
		UserList = usersList;
		user = u;

		postField.setVisible(true);

		myLabel = new JLabel("Recent posts by friends");

		Postedlist = new JList<String>();
		model2 = new DefaultListModel<String>();
		Postedlist.setModel(model2);
		myLabel2 = new JLabel("Suggested Friend " + u.SuggestedFriends());
		for (User t : usersList) {
			model2.addElement(t.AllPosts(usersList).toString());
		}

		scrollPane = new JScrollPane(postField);

		scrollPane2 = new JScrollPane(Postedlist);

		panel.setLayout(new GridLayout(3, 2));
		panel.add(nameField);
		panel.add(emailField);
		panel.add(BackButton);

		panel.add(scrollPane);
		panel.add(PostButton);

		panel.add(myLabel);
		panel.add(scrollPane2);
		panel.add(myLabel2);

		this.setContentPane(panel);

		ButtonListener listener = new ButtonListener();
		BackButton.addActionListener(listener);
		PostButton.addActionListener(listener);

		this.setExtendedState(JFrame.MAXIMIZED_BOTH);
		this.setTitle("Σελίδα Χρήστη");
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	}

	class ButtonListener implements ActionListener {

		public void actionPerformed(ActionEvent e) {
			if (e.getSource().equals(BackButton)) {
				setVisible(false);
				new GUI(UserList);
			} else {

				Post p = user.CreatePost(postField.getText());
				user.AddPost(p);
				if (user.getAddedPosts().size() >= 2) {
					user.getAddedPosts().remove(0);
					model2.addElement(user.getAddedPosts().toString());
				} else
					model2.addElement(user.getAddedPosts().toString());
			}

		}

	}

}
