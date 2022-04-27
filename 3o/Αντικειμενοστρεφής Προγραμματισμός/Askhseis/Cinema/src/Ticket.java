

public class Ticket {
    private Show show;
	private String code;
	private String date;
	private String kindTicket;
	private double price;
	private String sideDish=" ";
	private String mainDish=" ";
	private String dessert= " ";
	private String drink= " ";
   
	public Ticket(Show s,String code,String date,String kindTicket,
			double price)
	{   this.show=s;
		this.code=code;
		this.date=date;
		this.kindTicket=kindTicket;
		this.price=price;
		
	}

	public Show getShow() {
		return show;
	}

	public void setShow(Show show) {
		this.show = show;
	}

	public String getCode() {
		return code;
	}

	public void setCode(String code) {
		this.code = code;
	}

	public String getDate() {
		return date;
	}

	public void setDate(String date) {
		this.date = date;
	}

	public String getKindTicket() {
		return kindTicket;
	}

	public void setKindTicket(String kindTicket) {
		this.kindTicket = kindTicket;
	}

	public double getPrice() {
		return price;
	}

	public void setPrice(double price) {
		this.price = price;
	}

	
	

    public String getSideDish() {
		return sideDish;
	}

	public void setSideDish(String sideDish) {
		this.sideDish = sideDish;
	}

	public String getMainDish() {
		return mainDish;
	}

	public void setMainDish(String mainDish) {
		this.mainDish = mainDish;
	}

	public String getDessert() {
		return dessert;
	}

	public void setDessert(String dessert) {
		this.dessert = dessert;
	}

	public String getDrink() {
		return drink;
	}

	public void setDrink(String drink) {
		this.drink = drink;
	}


}
