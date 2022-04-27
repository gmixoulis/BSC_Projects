
import java.util.ArrayList;
import java.util.Scanner;

public class Client {
	public static void main(String[] args) {
		
		ArrayList<Menu> menus= new ArrayList<Menu>();
		ArrayList<Room> rooms= new ArrayList<Room>();
	    ArrayList<Show> shows=new ArrayList<Show>();
	    ArrayList<Movie> movies= new ArrayList<Movie>();
		ArrayList<Ticket> tickets=new ArrayList<Ticket>();
     
		
		
		Scanner sc = new Scanner(System.in);
		int input;
		
		
		do{
			System.out.println("Choose one of the following [0-8]:");
			System.out.println("1. Insert Menu");
			System.out.println("2. Insert Room (Standard or Gold)");
			System.out.println("3. Insert Movie");
			System.out.println("4. Insert Show");
			System.out.println("5. Book Ticket");
			System.out.println("6. Cancel Ticket");
			System.out.println("7. Order Menu Items (Available only in Gold Rooms)");
			System.out.println("8. Room Capacity for certain Show");
			System.out.println("0. Exit");
			
			input=sc.nextInt();
			switch (input){
				case 1:
					/* Dhmiourgia 4arwn arraylist oi opoies kathe fora pou 
					 * tha plhktrologite h epilogh 1 tha ananeonontai 
					 * me ayton ton tropo dhmiourgountai ta ksexwrista
					 * monadika menu
					 */
					
					ArrayList<String> sideDish2=new ArrayList<String>();
					ArrayList<String> mainDish2=new ArrayList<String>();
					ArrayList<String> desserts2=new ArrayList<String>();
					ArrayList<String> drinks2=new ArrayList<String>();
			    System.out.println("Give a code for the menu");
			    String code88=sc.next();
				String s3="0";
				boolean T=true;
				//elegxos gia to an yparxei paromoio menu
				for(Menu m:menus)
				{
				  if(m.getCode().equals(code88))
				  {
					 System.out.println("Allready Exists");
					 T=false;
					 break; 
				  }
				}
				while(s3.equals("0") && T)
				{
					// eisagwgh listwn menu
					
					System.out.println("Give a side dish");
					String sidedish1 = sc.next();
					sidedish1 += sc.nextLine();
					sideDish2.add(sidedish1);
					
					System.out.println("Give a main dish");
					String maindish1 = sc.next();
					maindish1 += sc.nextLine();
					mainDish2.add(maindish1);
				
					System.out.println("Give a dessert");
					String dessert = sc.next();
					dessert += sc.nextLine();
					desserts2.add(dessert);
					
					System.out.println("Give a drink");
					String drinks1 = sc.next();
					drinks1 += sc.nextLine();
					drinks2.add(drinks1);
					
					System.out.println("to end the lists of the menu please enter 1\n"
							+ "to keep the proccess of entering items please press 0 ");
					s3=sc.next();
				}
				    
				   
				    Menu menu=new Menu(code88,sideDish2,mainDish2,desserts2,drinks2);
					menus.add(menu);
					System.out.println("------------------------\n");
					break;
					
				case 2:// epilogh typou dwmatiou
						System.out.println("[a] Insert a standard room"+ "\n" +
								"[b] Insert a gold room ");
						String room=sc.next();
						//Standard room
						if(room.equals("a"))
						{
							System.out.println("Enter the id of the room");
							String id1=sc.next();
							boolean f=true;
							//elegxos gia to an yparxei allo idio Room me mia flag
							for (Room a:rooms)
								if(id1.equals(a.getCode()))
									f=false;
							if(f)
							{   // eisagwgh stoixeiwn typou Room
								System.out.println("Enter descreption of the room");
								String desc=sc.next();
								desc+=sc.nextLine();
								System.out.println("Enter the rows of the room");
								int rows=sc.nextInt();
								System.out.println("Enter the columns of the room");
								int col=sc.nextInt();
								
							    Room r= new StandardRoom(id1,desc,rows,col);
							    rooms.add(r);
							    
							}
							else
								System.out.println("Allready Exists");
								
									
						}
						else if(room.equals("b"))  //GoldRoom
						{
							System.out.println("Enter the id of the room");
							String id1=sc.next();
							// elegxos gia to an yparxei idio dwmatio me mai flag
							boolean f=true;
							for (Room a:rooms)
								if(id1.equals(a.getCode()))
									f=false;
							if(f)
							{   //eisagwgh stoixeiwn
								System.out.println("Enter descreption of the room");
								String desc=sc.next();
								desc+=sc.nextLine();
								System.out.println("Enter the rows of the room");
								int rows=sc.nextInt();
								System.out.println("Enter the columns of the room");
								int col=sc.nextInt();
								System.out.println("Enter the code of the menu");
								String g=sc.next();
								Menu menud=null;
								// eisagwgh tou menu sto GoldRoom
								for(Menu menu0:menus)
								{
									if(menu0.getCode().equals(g))
										menud=menu0;
								}
								
								
							    Room r= new GoldRoom(id1,desc,rows,col,menud);
							    rooms.add(r);
							   
							}
							else
								System.out.println("Allready Exists");
							    
						}
						else
							System.out.println("You choosed wrong choise please enter a or b next time");
						System.out.println("------------------------\n");
						break;
				case 3://Dhmiourgia Movie
					System.out.println("Enter the year of the movie");
					int year=sc.nextInt();
					boolean f=true;
					System.out.println("Enter the title of the movie");
					String title=sc.next();
					//elegxos gia to an yparxei paromoia tainia me mia flag
					for (Movie m:movies)
						if(title.equals(m.getTitle()) && year==m.getYear())
						          {f=false;  break;}
					if(f)
					{   //eisagwgh kai anagnwsh stoixeiwn sto object Movie
						System.out.println("Enter the code of the movie");
						String code=sc.next();
						System.out.println("Enter the actors");
						String actors=sc.next();
						actors+=sc.nextLine();
						System.out.println("Enter the duration in minutes ");
						int mins=sc.nextInt();
						
					    Movie r= new Movie(code,title, year,actors,mins);
					    movies.add(r);
					}
					else
						System.out.println("Allready Exists");
					System.out.println("------------------------\n");
						break;
				case 4://Dhmiourgia Show
					
					
					System.out.println("Enter the time of the show etc(hh:mm)");
					//eisagwgh ths wras me thn ekshs morfh hh:mm
					String time = sc.next(); //instead of nextLine()
					
					
					
					System.out.println("Enter the date of the show");
					String date=sc.next();
					System.out.println("Enter the code of the room");
					String id1=sc.next();
					Room x = null;
					for ( Room a:rooms)
 						{if(id1.equals(a.getCode()))
							{ x=a; break; }}
					if(x==null)
					{
						System.out.println("You gave wrong code for the room type it again"); break;
					}
					System.out.println("Enter the code of the movie");
					String codeM=sc.next();
				    //elegxos ths movie
					Movie movie=null;
					for(Movie m:movies)
					{
						if(m.getCode().equals(codeM))
							movie=m;
					}
					if(movie== null )
					{
						System.out.println("you gave wrong code for the movie");
						break;
					}
					//elegxos epanalhpsimothtas tou idiou show
					boolean f2=true;
					
					for(Show s:shows)
					{
						if(time.equals(s.getHour()) && date.equals(s.getDate()))
							{f2=false; break;}
					}
					
					if( f2)
					{
						// eisagwgh twn stoixeiwn sto antikeimeno Show
						int i = x.getRows();
						int j = x.getCol();
						int totalsits= i * j;
						//thewroume oti h katilimenes thseis panta sthn arxh einai 0
						int occseats=0;
						
						//arxikopoihsh tou pinaka-aithousas twn X ws adeies theseis wste na gemisei argotera
						 String[][] ray=new String[i][j];
						 for(int i1=0;i1<i;i1++)
							{for(int j1=0;j1<j;j1++)
							{
								ray[i1][j1]="[ ]";
								
								
							}}
						 
						 
						Show show = new Show(movie,date,time,id1,i,j,ray,totalsits,occseats);
					    shows.add(show);
					    
				
					    
					}
					else
						System.out.println("Allready Exists");
					System.out.println("------------------------\n");
					break;
					
					
					
					
				case 5: //Dimiourgia Ticket
					//elegxos gia to show
					System.out.println("Enter the time of the show (hh:mm)");
					String time1 = sc.next(); //instead of nextLine()
				
					
					
					System.out.println("Enter the date of the show");
					String date1=sc.next();
					System.out.println("Enter the code of the room");
					String id11=sc.next();
					Room x1 = null;
					for ( Room a:rooms)
						{if(id11.equals(a.getCode()))
							{ x1=a; break; }}
					if(x1==null)
					{
						System.out.println("You gave wrong code for the room type it again"); break;
					}
			
					Show sh=null;
					//elegxos gia to an yparxei hdh
					boolean f12=true;
					for(Show s:shows)
					{
						if(time1.equals(s.getHour()) && date1.equals(s.getDate())
								&& x1.getCode().equals(s.getCode()))
							{f12=false; sh=s;break;}
						
						
					}
					
					if(f12)
					{
						System.out.println("You gave wrong date or hour or room type them again \n");
						break;
					}
					int q=sh.getOccSits();
					int u=sh.getTotalSits();
					if(q<u)//elegxos gia to an oi katilimenes einai ligoteres tou sunolou
					{
						System.out.println("Give code for the ticket");
						String code=sc.next();
						System.out.println("Is your ticket Student or Regular? ");
						String kind=sc.next();
						System.out.println("Give the price of the ticket");
						double price=sc.nextDouble();
						//oi kleismenes theseis ayksanontai kata 1
						sh.setOccSits(q+1);
						System.out.println("Enter the date today");
						String date2=sc.next();
						
						
						Ticket t=new Ticket(sh,code,date2,kind,price);
						//kataxwrhsh tou antikeimenou Ticket
						tickets.add(t);
						// kleisimo tou eishthriou
						sh.BookaTicket(t.getCode());
					}
					else
						System.out.println("this show is full booked");

					System.out.println("------------------------\n");
					break;
				
				
				case 6:// Diagrafh Eishthriou
					System.out.println("Give the code of the ticket to delete it ");
					String cod=sc.next();
	
					for(Ticket t1:tickets)
					{   
						if(t1.getCode().equals(cod))
						{ for(Show s00:shows)
						   {
						   if(t1.getShow().equals(s00))
								{s00.DeleteaTicket(t1.getCode()); t1.getShow().setOccSits(t1.getShow().getOccSits()-1);}}
						
						  tickets.remove(t1); System.out.println("To eishthrio diagrafhke"); break ;}
						
					}
					
					
					System.out.println("------------------------\n");
					break;
				
				
				case 7: // Enhmerwsh twn 4wn pediwn tou menu
				
				System.out.println("Give the code of the ticket");
				String coded=sc.next();
				Ticket t2=null;
				// elegxos kwdikou eishthriou
				for(Ticket t1:tickets)
				{
					if(t1.getCode().equals(coded))
					{
						t2=t1;break;
					}
				}
				if(t2==null)
				{
					System.out.println("you gave wrong code for the ticket type it again");
					break;
				}
				
				//epilogh dwmatiou wste na eleksoume an anoigei sthn kathgoria GoldRoom
				
				Room r0=null;
				for(Room r:rooms)
					{
					if(r.getCode().equals(t2.getShow().getCode()))
						r0= r;
					}
				 
				
				//elegxos gia to an anoikei sto GoldRoom
				   if(r0 instanceof GoldRoom)
					 {  //epilogh tou menu p einai diathesimo gia to dwmatio
					  GoldRoom r22= (GoldRoom)r0;
					  
					   Menu l=r22.getMenu();

					     // se periptwsh poy DEN epithymei na faei tipota enw exei thn dynatothta ayth
					     
					    	 System.out.println("if you do NOT want to eat or drink anything press 10 else press 88");
					    	 int wq=sc.nextInt();
					    	 if (wq==10)
					    		 break;

					    	 System.out.println("Pick one dish from every list \n");
					    	
					    	
					    	 
					    	 
					    	
					    	 l.printtheMenu(1);
					          System.out.println("Choose one side dish");
					          String sdish=sc.next();
					          sdish+= sc.nextLine();
					          t2.setSideDish(sdish);
					    	 
					    	 
					    	 
					    	 
					    		
					    	    l.printtheMenu(2);
					    		System.out.println("Choose one main dish");
					            String mdish=sc.next();
					            mdish+= sc.nextLine();
					            t2.setMainDish(mdish);
					             
					             
						          
						          
						           
							          l.printtheMenu(3);
							          System.out.println("Choose one dessert");
							          String dess=sc.next();
							          dess+= sc.nextLine();
							          t2.setDessert(dess);
							         
							          
							             
							              l.printtheMenu(4);
								          System.out.println("Choose one drink");
								          String dr=sc.next();
								          dr+= sc.nextLine();
								          t2.setDrink(dr);       
					    	
					     
					       }
				   else
					   System.out.println("Your ticket booked on Standard Room");


				System.out.println("------------------------\n");
				break;
				case 8: //emfanish plhrothtas mias aithousas gia mia sygkekrhmenh provolh
					// elegxos gia thn provolh
					System.out.println("Enter the time of the show (hh:mm)");
					String time11 = sc.next(); 
				
					
					
					System.out.println("Enter the date of the show");
					String date11=sc.next();
					System.out.println("Enter the code of the room");
					String id111=sc.next();
					Room x11 = null;
					for ( Room a:rooms)
						{if(id111.equals(a.getCode()))
							{ x11=a; break; }}
			
					Show sh1=null;
					boolean f121=false;
					for(Show s:shows)
					{
						if(time11.equals(s.getHour()) && date11.equals(s.getDate())
								&& x11.getCode().equals(s.getCode()))
							{f121=true; sh1=s;break;}
						
						
					}// emfanish tou pinaka plhrothtas
					if(f121)
					{
						sh1.PrintTickets();
					}
					else
						System.out.println("You gave wrong code for the show type it again");
					System.out.println("------------------------\n");
					break;		
				
				
				case 0:
					System.out.println("Thank you for your preference");
						continue;
				default:
						System.out.println("Invalid Choice!");
						break;
			}
		}while (input!=0);	
	}
}