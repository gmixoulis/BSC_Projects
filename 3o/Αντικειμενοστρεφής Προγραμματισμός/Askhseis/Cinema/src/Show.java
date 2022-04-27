

public class Show {
   private int rows;
   private int col;
	private String[][] sits;	
	private String date;
	private String hour;
	private String RoomCode;
	private int totalSits;
	private int occSits;
    private Movie movie;
	//voitithikos pinas pou voithaei sthn ektypwsh tou case 8 kai leitourgei san endiamesos-temp pinakas
	private String[][] Seats;






	public Show(Movie m,String date,String hour,String code,int rows,int col,String[][] sits,int totalSits,int occsits)
	{
	    this.date=date;
	    this.hour=hour;
	    this.RoomCode=code;
	    this.rows=rows;
	    this.col=col;
	    this.totalSits=totalSits;
	    this.occSits=occsits;
	    this.movie=m;
	    this.sits=sits;
	    this.Seats=sits;
	}

	
	
	public String getRoomCode() {
		return RoomCode;
	}



	public void setRoomCode(String roomCode) {
		RoomCode = roomCode;
	}



	public String[][] getSeats() {
		return Seats;
	}



	public void setSeats(String[][] seats) {
		Seats = seats;
	}



	public void setHour(String hour) {
		this.hour = hour;
	}



	public Movie getMovie() {
		return movie;
	}


  
	
	
	public void setMovie(Movie movie) {
		this.movie = movie;
	}



	/*
	 * kleisimo eishthriou ston pinaka sits opou einai
	 * o pinakas plhrwthtas kai emfanizetai sto case 8
	 * o pinakas dexetai ta eishthria seiriaka
	 */
	public void BookaTicket(String s)
	{   outerloop:
		for(int i=0;i<this.getRows();i++)
		{
			for(int j=0;j<this.getCol();j++)
			{   
				if(this.getSits()[i][j].equals("[ ]") )
					{this.getSits()[i][j]=s; break outerloop;}
				
			}
		}
		
	}//Diagrafh tous eishthriou apo ton pinaka plhrothtas
	//h diagrafh ginetai analoga me ton kwdiko tou eishthriou
	public void DeleteaTicket(String s)
	{   outerloop:
		for(int i=0;i<this.getRows();i++)
		{  
			for(int j=0;j<this.getCol();j++)
			{   
				if(this.getSits()[i][j].equals(s))
					{this.getSits()[i][j]="[ ]"; 
					
					break outerloop; }
				
			}
		}
	}
	
	
	
	//Emfanish tou pinaka plhrothtas ths provolhs se sysxetish me enan endiameso pinaka
	public void PrintTickets()
	{  
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<col;j++)
			{   if(sits[i][j]!="[ ]")
				 this.Seats[i][j]="[X]";
				
				
			}
		}
		
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<col;j++)
			{   System.out.print(this.Seats[i][j]);
				   
			    if(j==col-1)
				System.out.println("\n");
			}
		}
		
		
	}
	public int getRows() {
		return rows;
	}

	public void setRows(int rows) {
		this.rows = rows;
	}

	public int getCol() {
		return col;
	}

	public void setCol(int col) {
		this.col = col;
	}

	public String[][] getSits() {
		return sits;
	}

	public void setSits(String[][] sits) {
		this.sits = sits;
	}

	public String getDate() {
		return date;
	}

	public void setDate(String date) {
		this.date = date;
	}

	public String getHour() {
		return hour;
	}

	
	public String getCode() {
		return RoomCode;
	}

	public void setCode(String code) {
		this.RoomCode = code;
	}

	public int getTotalSits() {
		return totalSits;
	}

	public void setTotalSits(int totalSits) {
		this.totalSits = totalSits;
	}

	public int getOccSits() {
		return occSits;
	}

	public void setOccSits(int occSits) {
		this.occSits = occSits;
	}


  


}
