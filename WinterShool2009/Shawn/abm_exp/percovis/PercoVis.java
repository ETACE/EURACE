import java.io.*;

/**
 * Main class. Used to launch PercoVis.
 */
public class PercoVis {

	/* Config data */
    private static final String DATA_DIR = "its";
    private static boolean DO_FILE_CHECK = true;

    /**
	 * @param args Array of command-line input arguments
	 */
    public static void main(String args[]) {
        
        int iters = 0;
        MyFrame gui = null;
        String FS = System.getProperty("file.separator");

        /* We expect 1 input argument */
        if (args.length == 1 && Integer.parseInt(args[0]) >= 0)
        {
            iters = Integer.parseInt(args[0]);
        }
        else
        {
            System.err.println("Usage: java PercoVis <iterations>");
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

        /* Launch window */
        System.out.println("Launching GUI ...");
        try {
            gui = new MyFrame(550, 590, iters, DATA_DIR);
            gui.setVisible(true);
        } catch (Throwable t) {
            System.out.println("FAILED! Unable to launch GUI.");
            System.exit(0);
        }

        System.out.println("\n" +
        "Controls:\n" +
        "=========\n" +
        "A, a  : start animation\n" +
        "P, p  : pause animation\n" +
        "Right : Next iteration\n" +
        "Left  : Previous iteration\n" +
        "Down  : Next 10th iteration\n" +
        "Up    : Previous 10th iteration\n" +
        "0, o  : Go to iteration 0\n" +
        "9, e  : Go to last iteration\n" +
        "\nP, Esc : Quit"
        );
    }

}
