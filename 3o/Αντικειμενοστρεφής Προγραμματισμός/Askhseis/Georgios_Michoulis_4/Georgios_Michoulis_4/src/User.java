import java.util.ArrayList;
import java.util.Calendar;
import java.util.Collections;
import java.util.Date;



import java.sql.Timestamp;


public class User  {
	/* oi Users exoune ta ekshs xarakthristika
	 * 1) email, 2) name, 3) Lista me tousfilous tous 4) listes me
	 * ta group p exoun kanei eggrafh ( closed kai  kanoniko)
	 */
	private String name;
	private String email;
	
	private ArrayList<User> users= new ArrayList<User>();
	private ArrayList<User> HasFriends = new ArrayList<User>();
	ArrayList<User> suggestedFriends = new ArrayList<User>();
	private ArrayList<Group> joinedGroups= new ArrayList<Group>();
	private ArrayList<ClosedGroup> joinedGroups2= new ArrayList<ClosedGroup>();
    private ArrayList<Post> addedPosts = new ArrayList<Post>();
	boolean IsFriend;
   
	
    //kataskeyasths
    public  User (String name, String email)
    {
    	
        if( email.startsWith("it") && email.endsWith("@uom.edu.gr") )
         {this.name=name;
        this.email=email;
       
        }
		else
    		System.out.println("User " + name + " has not been created.Email format is not acceptable");	
    	
    	
    }
    
   
	/*Μέθοδο η οποία δέχεται ως παράμετρο έναν άλλο χρήστη 
	 * και επιστρέφει true ή false ανάλογα με το αν είναι φίλοι ή όχι.
	 */
	
    
	public boolean IsUserFriendWith(User us)
	{    
		for(User s: HasFriends)
		{   
			if(s.getName().equals(us.getName()))
				{IsFriend =true; break;}
			else
				IsFriend= false;
		}
		return IsFriend;
	}


	/*
     * Μέθοδο η οποία προσθέτει στην λίστα των φίλων έναν άλλο χρήστη. 
     * Αυτό γίνεται αφού προηγηθεί έλεγχος για το αν πρόκειται για το ίδιο 
     * πρόσωπο ή για χρήστη που είναι ήδη φίλος παρανετρος ειναι ο user
     */
    public void addFriend(User us)
    {
    	if (IsUserFriendWith(us)== false)
    	{
    		HasFriends.add(us);
    		us.getHasFriends().add(this);
			System.out.println(this.getName() + "  and  " + us.getName() + " are now friends!");
		} else {
			System.out.println("Cannot add user " +this.getName() + " as a friend because "+ this.getName() + " and " + us.getName() + " are already friends!");
			
		}
    	
    }
    
    
   
    
    /*
     * ειναι μια μεθοδος που  εκτυπωνει τους φιλους ενος χρηστη
     * δεχεται σαν παραμετρο εναν  χρηστη us.
     */
    
    public void PrintFriendsOfUser(User us){int count=1;
    System.out.println("*******************************");
	System.out.println("Friends of "+us.getName());
	System.out.println("*******************************");
    for (User friend : us.HasFriends)
    {
    	System.out.println(count +": " + friend.getName());
		count++;
	
    }
    System.out.println("--------------------------------");
    System.out.println("*******************************");
    }
    
    
    //getters 



	public ArrayList<User> getHasFriends() {
		return HasFriends;
	}

	public ArrayList<Post> getAddedPosts() {
		return addedPosts;
	}


	public String getName() {
		return name;
	}

	public String getEmail() {
		return email;
	}
	
	
	
	
	
	
	
	
	/*
	 * αυτη η μεθοδος δεχεται σαν παραμετρο(g) ενα γκροπ ( το ανοιχτο) και προσθετει
	 * τον χρηστη σε αυτο το γκρουπ
	 */
	
	
	
	public void AddGroup(Group g){
		joinedGroups.add(g);
	} 
	/*
	 * αυτη η μεθοδος δεχεται σαν παραμετρο(g) ενα γκροπ ( το κλειστο) και προσθετει
	 * τον χρηστη σε αυτο το γκρουπ
	 */
	public void AddClosedGroup (ClosedGroup g){
		joinedGroups2.add(g);}
	
	/* 
	 * αυτη η μεθοδος παιρνει εναν αλλον user σαν παραμετρο και δινει πισω
     * μια λιστα με τους κοινους φιλους αυτων των 2
	 */
	
	public ArrayList<User> CommonFriends(User us) {
		ArrayList<User> CommonFriends = new ArrayList<User>();
    	for (User friend : HasFriends)
    	{
    		for (User OtherFriend : us.HasFriends)
    		{
    			if(friend.getEmail().equals(OtherFriend.getEmail()))
    				CommonFriends.add(friend);
    		}
    	}
    	
		return CommonFriends;
		
	}
	/* 
     * αυτη η μεθοδος παιρνει εναν αλλον user σαν παραμετρο και εκτυπωνει πισω
     * μια λιστα με τους κοινους φιλους αυτων των 2 (με την βοηθεια της HasFriends)
     * , παραμετρος το us
     */
    public void PrintCommonFriends(User us)
    {
    	int count=1;
    	System.out.println("*******************************");
    	System.out.println("Common friends of " +this.getName()+ " and " +us.getName());
    	System.out.println("*******************************");
        for (User comfriend : CommonFriends(us))
        {
        	System.out.println(count +": " + comfriend.getName());
			count++;
		
        }
        System.out.println("--------------------------------");
        System.out.println("*******************************");
    }
	
	/*
	 * αυτη η μεθοδος εκτυπωνει τα γκρουπς που ειναι γραμενος ο χρηστης
	 */

	public void PrintJoinedGroups(){
		int i=0;
		int j=1;
		 System.out.println("*******************************");
		System.out.println("Groups that " + name + " has been enrolled in:");
		while(i<joinedGroups.size()){
			System.out.println(j + ": " + joinedGroups.get(i).getName() + joinedGroups2.get(i).getName());
			i++;
		
	}}

	/* methodos poy vrhskei olous tou protinomenous filous mesa apo thn triadikh sxesh
	 * epistrefei mia lista me tous protinomenous filous
	 */
	public ArrayList<User> FindSuggestedFriends(){
		
		
		for (User friend: HasFriends){
			for (User f: friend.HasFriends){
				if ((!this.HasFriends.contains(f))&&(!f.getName().equals(this.getName()))){
					suggestedFriends.add(f);
				}
			}
		}
		return suggestedFriends;
		
	}
	
  
	
	public void PrintSuggestedFriend(){
		
		
		System.out.println("Suggested Friends for " + this.getName() + " :");
			
		for (User user: FindSuggestedFriends()){
			System.out.println(user.getName());
			
		}
		
	}
	
	 /* methodos poy dhmiourgei ena post kataxwrontas se ayto thn twrinh hmeromhnia
	  * dexetai to alfarithmitiko kai epistrefei thn hmeromhnia poy kataxwrithike , to alfarithmitiko
	  * kai ton user pou to dhmiourghse.
	  */
	public Post CreatePost(String str) {
		Calendar cal = Calendar.getInstance();
		cal.add(Calendar.DAY_OF_YEAR, -1);
		Timestamp stamp = new Timestamp(cal.getTimeInMillis());
		Date date = new Date(stamp.getTime());		
		return new Post (date,str, this);
	}
	
	
   // prosthetei ta post se mia lista 
	public void  AddPost(Post p)
	{
		addedPosts.add(p);	
	}
	
	
	
	/*μέθοδο επιστροφής όλων των post που πραγματοποίησαν οι φίλοι του, 
	 * συμπεριλαμβανομένων και των δικών του posts, ταξινομημένα με χρονολογική σειρά
	 * 
	 */
	
	
	public ArrayList<Post> AllPosts()
	{
		ArrayList<Post> Order_post = new ArrayList<Post>();
		
		
		//ta dika tou post
		for (int i=0; i<addedPosts.size();i++)
		{
			Post post2 = addedPosts.get(i); 
		Order_post.add(post2);
		
		}
		
		//twn filwn tou ta post
		for (int i=0; i<HasFriends.size();i++)
		{
		User b = this.HasFriends.get(i);
		for (int j=0; j<b.addedPosts.size();j++)
		{
		Post post2 = b.addedPosts.get(j); 
		Order_post.add(post2);
		}
		}
		
		Collections.sort(Order_post);
		
		return Order_post;
	}


	public void addUser() {
		users.add(this);
	}

	
	
	public void PrintPosts()
	{
		for(Post s : this.getAddedPosts())
		{   System.out.println(this.getName()+ " Posts");
			System.out.println(s.toString());
		}
		System.out.println(" ");
	}
	
	
	
	
	
	
	
}
