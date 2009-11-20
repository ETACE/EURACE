
public class Grid {

	private int[][] grid;
	private int width, height;

    public Grid (int width, int height) 
    {
        grid = new int[height][width];
        this.width  = width;
        this.height = height;
    }

    public void setValue(int row, int col, int value)
    {
    	if (row < 0 || row >= height || col < 0 || col >= width)
    		return;
    	
    	grid[row][col] = value;
    }
    
    public int getValue(int row, int col)
    {
    	if (row < 0 || row >= height || col < 0 || col >= width)
    		return -1;
    	
    	return grid[row][col];
    }
    
    public int getWidth() { return width; }
    public int getHeight() { return height; }
    
}
