import java.util.ArrayList;





public  class  Group  {

	
	private String desc;
	private  String name;
	private ArrayList<User> users = new ArrayList<User>();
	
	//κατασκευαστης
	public Group (String name,  String desc)

    {
	       this.name = name;
	       this.desc= desc;
    }



	public String getName() {
		return name;
	}



	//μεθοδος που επιστρεφει true or false μετα τον ελεγχο
	// ενος user (u) στην περιπτωση που περιλαμβανεται στο γκρουπ ή οχι
    public boolean MemberOrNot(User u)
    {
		if (users.contains(u) )
		{
			System.out.print("!!!!!!" + u.getName() + "Is allready a member of  this group" + name);
		    return true;
		}
		else
			return false;
    	
    }
    
    
    public ArrayList<User> getUsers() {
		return users;
	}

 
//αυτη η μεθοδος παιρνει εναν User (u) σαν παραμετρο και τον προσθετει στο γκρουπ
    public void addaMember(User u){
		if (users.contains(u)){
			System.out.println("Already a member.");
		}
		else
			System.out.println(u.getName() + " has been successfully enrolled in group " + name);
			users.add(u);
			u.AddGroup(this);
	}
    
    //αυτη η μεθοδος εκτυπωνει τα μελη του γκρουπ
    public void PrintGroupMembers()
    {
    	int count = 1;
		System.out.println("********************");
		System.out.println("Members of group " + name);
		System.out.println("*********************");
		int s=users.size();
		for(int i=0; i<s; i++){
			System.out.println(count+ ":   " + users.get(i).getName());
			count++;
		}
		System.out.println("----------------------");
    	
    }
    
    

   










}