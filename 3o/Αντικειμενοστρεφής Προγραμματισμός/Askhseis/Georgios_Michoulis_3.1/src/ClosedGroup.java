import java.util.ArrayList;

public class ClosedGroup {

	private String name;
	private String desc;
	private ArrayList<User> users = new ArrayList<User>();

	// κατασκευαστης
	public ClosedGroup(String name, String desc) {
		this.name = name;
		this.desc = desc;
	}

	// getters
	public String getName() {
		return name;
	}

	public String getDesc() {
		return desc;
	}

	public ArrayList<User> getUsers() {
		return users;
	}

	/*
	 * αυτη η μεθοδος παιρνει σαν παραμετρο εναν user (u) και τον προσθετει στο
	 * γκρουπ αφου ,πρωτα ελεγξει αμα ειναι φιλος με καποιον απο τα υπαρχοντα
	 * μελη του γκρουπ ( η προηγουμενη συνθηκη δεν ισχυει για το πρωτο μελος του
	 * γκρουπ) και εκτυπωνει την επιτυχη ή μη εισαγωγη του στο γκρουπ.
	 * 
	 */
	public void addaMember(User us) {
		boolean g = false;
		if (users.size() == 0) {

			users.add(us);
			us.AddClosedGroup(this);
			System.out.println(us.getName() + " successfully joined group: " + name);

		}

		else {
			for (int i = 0; i < users.size(); i++) {

				User a = users.get(i);

				for (int j = 0; j < a.getHasFriends().size(); j++) {
					User us2 = a.getHasFriends().get(j);
					if ((us.getName() == us2.getName()) && (us.getEmail() == us2.getEmail()))
						g = true;
				}

			}

			if (g) {
				users.add(us);
				us.AddClosedGroup(this);

				System.out.println(us.getName() + " has been successfully enrolled in group " + name);

			} else {
				System.out.println("FAILED " + us.getName() + " Cannot be enrolled in group ExamSolutions");

			}
		}

	}

	// αυτη η μεθοδος εκτυπωνει τα μελη του γκρουπ χωρις να παιρνει καμια
	// παραμετρο
	public void PrintGroupMembers() {
		int count = 1;
		System.out.println("********************");
		System.out.println("Members of group " + name);
		System.out.println("*********************");
		int s = users.size();
		for (int i = 0; i < s; i++) {
			System.out.println(count + ":   " + users.get(i).getName());
			count++;
		}
		System.out.println("----------------------");
	}

}
