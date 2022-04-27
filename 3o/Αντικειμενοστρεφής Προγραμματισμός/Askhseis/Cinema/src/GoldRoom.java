
public class GoldRoom extends Room{
	private String code;
	private String desc;
	private int rows;
	private int col;
	private Menu menu;
	public GoldRoom(String code, String desc,int rows,int col,Menu menu)
	{
		super(code,desc,rows,col);
		this.menu=menu;
	}
	public Menu getMenu() {
		return menu;
	}
	public void setMenu(Menu menu) {
		this.menu = menu;
	}
	
}
