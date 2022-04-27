

public class Movie {

	private String title;
	private String code;
	private int year;
	private int mins;
	private String actors;
	

	public Movie(String code,String title,int year,String
	actors,int mins)
	{
		this.code=code;
		this.title=title;
		this.year=year;
		this.mins=mins; 
		this.actors=actors;
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public String getCode() {
		return code;
	}

	public void setCode(String code) {
		this.code = code;
	}

	public int getYear() {
		return year;
	}

	public void setYear(int year) {
		this.year = year;
	}

	public int getMins() {
		return mins;
	}

	public void setMins(int mins) {
		this.mins = mins;
	}

	public String getActors() {
		return actors;
	}

	public void setActors(String actors) {
		this.actors = actors;
	}

	
	
	
	
}
