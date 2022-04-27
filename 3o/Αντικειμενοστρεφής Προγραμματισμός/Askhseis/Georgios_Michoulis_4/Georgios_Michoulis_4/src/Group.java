import java.util.ArrayList;





public  class  Group  {

	
	private String desc;
	private  String name;
	private ArrayList<User> users = new ArrayList<User>();
	
	//�������������
	public Group (String name,  String desc)

    {
	       this.name = name;
	       this.desc= desc;
    }



	public String getName() {
		return name;
	}



	//������� ��� ���������� true or false ���� ��� ������
	// ���� user (u) ���� ��������� ��� �������������� ��� ������ � ���
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

 
//���� � ������� ������� ���� User (u) ��� ��������� ��� ��� ��������� ��� ������
    public void addaMember(User u){
		if (users.contains(u)){
			System.out.println("Already a member.");
		}
		else
			System.out.println(u.getName() + " has been successfully enrolled in group " + name);
			users.add(u);
			u.AddGroup(this);
	}
    
    //���� � ������� ��������� �� ���� ��� ������
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