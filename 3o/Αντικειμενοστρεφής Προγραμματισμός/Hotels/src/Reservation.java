
public abstract class Reservation {
	

	protected int days;
	
	
	public Reservation(int days) {
		this.days = days;
		
	}
	
	public abstract double CalculateCharge();
	

}
