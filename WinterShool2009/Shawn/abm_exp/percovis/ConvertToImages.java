/* =====================================================
 * Desc: Write iteration data as a set of JPEG images
 * 
 * Auth: LS Chin (STFC)
 * Date: Sept (2007)
 */
import java.io.*;
import java.awt.*;
import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;

public class ConvertToImages {
	
	/* Config data */
    private static final String DATA_DIR = "its";
    private static final String OUT_DIR  = "images";
    private static boolean DO_FILE_CHECK = true;
    
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		int iters = 0;
		String FS = System.getProperty("file.separator");
		
		/* We expect 1 input argument */
        if (args.length == 1 && Integer.parseInt(args[0]) >= 0)
        {
            iters = Integer.parseInt(args[0]);
        }
        else
        {
            System.err.println("Usage: java ConvertToImages <iterations>");
            System.exit(1);
        }
        
        /* Check if all data files exists */
        String filename;
        if (DO_FILE_CHECK)
        {
            for (int i = 0; i <= iters; i++)
            {
                filename = DATA_DIR + FS + i + ".xml";
                if (! (new File(filename)).exists())
                {
                    System.err.println("Error: file not found ("+filename+")");
                    System.exit(1);
                }
            }
        }
        
        dumpImages(iters);
	}
	
	public static void dumpImages(int iters) {
		
		Graphics2D g2d;
		String outfilename;
		BufferedImage outImage;
        Integer[] args = new Integer[1];
        String FS = System.getProperty("file.separator");
        ImageContainer handleimage = new ImageContainer(DATA_DIR);
        
        /* Create Image Directory if necessary */
        System.out.println(" * Creating output folder (" + OUT_DIR + ").. ");
        File imagedir = new File(OUT_DIR + FS);
        if(!imagedir.exists()) imagedir.mkdir();
            
        /* for each iteration */
        for(int itno=0; itno <= iters; itno++)
        {
         	args[0] = new Integer(itno);
           	outfilename = String.format("%1$04d.gif", (Object[])args);
           	System.out.println("   - Writing " + OUT_DIR + FS + outfilename);
           	
            /* create a buffer for the image */
            outImage = new BufferedImage(550,550, BufferedImage.TYPE_INT_RGB);
               
            /* create a graphics object to draw to */
            g2d = outImage.createGraphics();
                
            /* draw the current iteration */
            handleimage.updateImage(itno, g2d, 0, 0);
                
            /* Write image as JPEG file */
            try {
            	ImageIO.write(outImage, "gif", new File(OUT_DIR + FS + outfilename));
            } catch (IOException e) {
                System.err.println("Error writing JPEG: " + e.getMessage());
            }
        }

	}

}
