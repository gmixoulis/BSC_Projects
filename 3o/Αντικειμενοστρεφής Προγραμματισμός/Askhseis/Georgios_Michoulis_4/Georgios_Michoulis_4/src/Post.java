

import java.util.*;



public class Post implements Comparator<Post> ,Comparable<Post>{	
	private Date timestamp;
	private String post;
	private User user;
	
	
	public Post ( Date timestamp, String post, User user){
		
		this.timestamp=timestamp;
		this.post=post;
		this.user=user;
	
	}


	public Date getTimestamp() {
		return timestamp;
	}

	public void setTimestamp(Date timestamp) {
		this.timestamp = timestamp;
	}

	public User getUser() {
		return user;
	}

	public void setUser(User user) {
		this.user = user;
	}

	public String getPost() {
		return post;
	}

	


	
	

	
	/* ayth h methodos metatrepei to post se morfh string wste na mporei na ektypwthei */
	public String toString(){
		String out = "";
		out = 
				"| " +this.timestamp+ " | " +this.getUser().getName()+ " : " +this.post;
		return out;
	}
	
	


	
	public int compareTo(Post other) {
		if(this.timestamp.compareTo(other.timestamp)>0)
			return 1;
		else if(this.timestamp.compareTo(other.timestamp)<0)
			return -1;
		else
			return 0;
	}


	


	
	public int compare(Post o1, Post o2) {
		return 0;
	}
	
}
