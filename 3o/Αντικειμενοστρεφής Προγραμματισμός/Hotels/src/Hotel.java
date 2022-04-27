import java.io.Serializable;
import java.util.ArrayList;


public class Hotel implements Serializable, Comparable {
	
	private ArrayList<Reservation> reservations = new ArrayList<Reservation>();
	
	private String name;

	public Hotel(String name) {
		this.name = name;
	}
	
	public String getName() {
		return name;
	}

	@Override
	public int compareTo(Object other) {
		Hotel otherHotel = (Hotel)other;
		return this.name.compareTo(otherHotel.name);
	}
	
	public void addReservation (Reservation r) {
		reservations.add(r);
	}
	
	public double calculateTotalCost() {
		
		double cost = 0;
		for(Reservation r : reservations) {
			cost += r.CalculateCharge();
			
		}
		return cost;
		
	}
	
}
