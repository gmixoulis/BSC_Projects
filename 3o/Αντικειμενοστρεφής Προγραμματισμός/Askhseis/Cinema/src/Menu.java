import java.util.ArrayList;

public class Menu {

	
	private String code;
	private ArrayList<String> sideDish;

	private ArrayList<String> mainDish;

	private ArrayList<String> dessert;

	private ArrayList<String> drinks;

	
	public Menu(String code,ArrayList<String> sideDish1,ArrayList<String>
	mainDish1,ArrayList<String> dessert1,ArrayList<String> drinks1)
	{
		this.code=code;
		
		sideDish=new ArrayList<String>(sideDish1);
		mainDish=new ArrayList<String>(mainDish1);
		dessert=new ArrayList<String>(dessert1);
		drinks=new ArrayList<String>(drinks1);
		
	    
	
	}

	public String getCode() {
		return code;
	}

	public void setCode(String code) {
		this.code = code;
	}

	public ArrayList<String> getSideDish() {
		return sideDish;
	}

	public void setSideDish(ArrayList<String> sideDish) {
		this.sideDish = sideDish;
	}

	public ArrayList<String> getMainDish() {
		return mainDish;
	}

	public void setMainDish(ArrayList<String> mainDish) {
		this.mainDish = mainDish;
	}

	public ArrayList<String> getDessert() {
		return dessert;
	}

	public void setDessert(ArrayList<String> dessert) {
		this.dessert = dessert;
	}

	public ArrayList<String> getDrinks() {
		return drinks;
	}

	public void setDrinks(ArrayList<String> drinks) {
		this.drinks = drinks;
	}
    // emfanish twn listwn tou menu
	public void printtheMenu(int i)
	{   
		switch(i){
		case 1:
			     for(String s: this.sideDish)
	             System.out.println(s);
		         break;
		case 2:
			     for(String s: this.mainDish)
	             System.out.println(s);
		         break;
		case 3:
			     for(String s: this.dessert)
	             System.out.println(s);
		         break;
		case 4:
			     for(String s: this.drinks)
	             System.out.println(s);
		         break;
	
	   default: System.out.println(" ");
	             }
	
	}
	
	
	
	
}
