
public abstract class Room  {

	
	private String code;
	private String desc;
	private int rows;
	private int col;
    private Menu menu;
	public  Room(String code, String desc,int rows,int col)
	{
		this.code=code;
		this.desc=desc;
		this.rows=rows;
		this.col=col;
		
	}

	public String getCode() {
		return code;
	}
     
	public Menu getMenu()
	{
		return menu;
	}
	public void setCode(String code) {
		this.code = code;
	}

	public String getDesc() {
		return desc;
	}

	public void setDesc(String desc) {
		this.desc = desc;
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











}
