import java.awt.*;
import java.awt.image.BufferedImage;

public class ImageContainer extends Container {
	
	private static final long serialVersionUID = 1L;
	private String dataDir;
    private boolean busy = false;
    private boolean imageStained = false;
    private BufferedImage bufImg;
    private Graphics2D g2d;
    private int elemSize = 5;
    
    // Color generator
    /* To generate a unique color for each data value */
    private ColorGenerator arse = new ColorGenerator();
    
    /**
     * @param dataDir Input data directory
     */
    public ImageContainer(String dataDir)
    {
        this.dataDir = dataDir;
        bufImg = new BufferedImage(550, 550, BufferedImage.TYPE_INT_RGB);
        g2d = bufImg.createGraphics();
        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, 
            RenderingHints.VALUE_ANTIALIAS_ON);
    }

    /**
     * Update graphics with a given iteration data
     * @param iter Which iteration data to draw
     * @param g Graphics object to draw on
     * @return true if update completed, false otherwise
     */
    public boolean updateImage(int iter, Graphics g, int xoffset, int yoffset)
    {
        String filename;
        StateFileHandler dataReader;
        AgentList alist;
        
        // Dimensions of input data
        int width, height;
        
        // Coord to start drawing actual grid
        int i_x = 0, i_y = 0;
        
        final int i_max = 500; // max width/height 
        final int padding = 25; // min padding around grid
        
        // Cell size (width and height)
        int csize = 0;
        
        /* Just in case this is called by multiple threads? */
        if (busy) return false;
        busy = true;

        filename = dataDir + "/" + iter + ".xml";
        dataReader = new StateFileHandler(filename);
        alist = dataReader.getAgentList();

        /* ------ Calculate necessary measurements to scale data to image ---- */
        
        /* Calculate coordinate and dimension of grid based on input data */
        width  = alist.width;
        height = alist.height;
        
        
        if (iter == 0)
        {
        	/* crop if input data too large */
	        if (width > i_max)
	        {
	        	System.err.println("ImageContainer can't handle images wider than " + i_max + "(image cropped)");
	        	width = i_max;
	        }
	        if (height > i_max)
	        {
	        	System.err.println("ImageContainer can't handle images taller than " + i_max + "(image cropped)");
	        	height = i_max;
	        }
        }
        
        /* scale output image to data dimensions */
        if (width >= height)
        {
        	/* set cell size (width and height) */
        	csize = i_max / width; 
        	
        	/* set starting coordinate */
        	i_x = padding;
        	i_y = (i_max - height*csize)/2 + padding;
        }
        else if (height > width)
        {
        	/* set cell size (width and height) */
        	csize = i_max / height;
        	
        	/* set starting coordinate */
        	i_x = (i_max - width*csize)/2 + padding;
        	i_y = padding;
        }
        
        /* ---------- Start Drawing ---------------------------------- */
        
        /* Set canvas background colour*/
        g2d.setColor(Color.white);
        g2d.fillRect(0, 0, i_max + (2*padding), i_max + (2*padding));
        
        /* Fill cell for each data point */

        for (int i = 0; i < alist.list.size(); i++)
        {
            Agent a = alist.list.get(i);
            g2d.setColor(arse.pickColour(a.id));
            g2d.fillRect((int)a.x, (int)a.y, elemSize, elemSize);
        }
        
        /* Draw image border */
        g2d.setColor(Color.lightGray);
        g2d.drawLine(0,0,width,0);
        g2d.drawLine(0,0,0,height);
        g2d.drawLine(width,0,width,height);
        g2d.drawLine(0,height,width,height);

        //g2d.drawLine(i_x, i_y, i_x + width*csize, i_y); // Top Line
        //g2d.drawLine(i_x, i_y, i_x, i_y + height*csize); // Left Line
        //g2d.drawLine(i_x + width*csize, i_y, i_x + width*csize, i_y + height*csize); // Right Line
        //g2d.drawLine(i_x, i_y + height*csize, i_x + width*csize, i_y + height*csize); // Bottom Line

        /* Draw our generate image onto GUI */
        if (g != null && bufImg != null)
            g.drawImage(bufImg, xoffset, yoffset, this);

        busy = false;
        return true;
    }
}
