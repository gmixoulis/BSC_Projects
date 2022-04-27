
public class SimpleReservation extends Reservation {
	
	
	public SimpleReservation(int days) {
		super(days);
		
	}

	@Override
	public double CalculateCharge() {
		return days*120;
	}

}
