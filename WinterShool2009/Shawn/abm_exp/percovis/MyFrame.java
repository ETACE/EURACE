import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MyFrame extends JFrame implements WindowListener, KeyListener {
	
	private static final long serialVersionUID = 1L;
	private AnimationThread animThread;
    private JLabel statusBar;
    private ImageContainer canvas;
    public int maxIters;
    public int currentIter;
    
    /**
     * GUI Frame constructor
     * @param width Width of GUI
     * @param height Height of GUI
     * @param iters Max iteration data to load
     * @param dataDir Input data directory
     */
    public MyFrame(int width, int height, int iters, String dataDir)
    {

        /* Window configuration */
        setTitle("Percolation Model");
        setSize(width, height);
        setLocation(50,50);
        setBackground(Color.white);

        /* Attach event Listeners */
        addWindowListener(this);
        addKeyListener(this);

        /* Add Status bar to window */
        statusBar = new JLabel("Initializing ...");
        statusBar.setForeground(Color.blue);
        this.getContentPane().add(statusBar, BorderLayout.NORTH);

        this.maxIters = iters;
        this.currentIter = maxIters; /* will be incremented to 0 on first iter */ 
        canvas = new ImageContainer(dataDir);
        animThread = new AnimationThread(this);
        step(1);
        //animThread.start();
        //canvas.repaint();
    }

    /**
     * On Window Close: exit program
     */
    public void windowClosing(WindowEvent ev)
    {
        /* program exits if window is closed */
        System.out.println("BYE.");
        System.exit(0);
    }
    
    /**
     * Define actions on key press
     */
    public void keyPressed(KeyEvent ev)
    {
        /* identify key */
        int key = ev.getKeyCode();

        switch (key)
        {
        	case KeyEvent.VK_RIGHT:
        		step(1);
        		break;
        	case KeyEvent.VK_LEFT:
        		step(-1);
        		break;
        	case KeyEvent.VK_UP:
        		step(10);
        		break;
        	case KeyEvent.VK_DOWN:
        		step(-10);
        		break;
        	case KeyEvent.VK_0:
        	case KeyEvent.VK_O:
        		currentIter = 0;
        		step(0);
        		break;
        	case KeyEvent.VK_E:
        	case KeyEvent.VK_9:
        		currentIter = maxIters;
        		step(0);
        		break;
            case KeyEvent.VK_A:
                if ( !animThread.isRunning())
                {
                    animThread = new AnimationThread(this);
                    animThread.start();
                }
                break;
            case KeyEvent.VK_P:
                animThread.pause();
                updateStatus();
                break;
            case KeyEvent.VK_ESCAPE:
            case KeyEvent.VK_Q:
                System.out.println("BYE.");
                System.exit(0);
                break;
        }
    }

    /**
     * Reset Status text
     * @param status Status text to be set
     */
    public void setStatus(String status)
    {
        this.statusBar.setText(status);
    }
    
    /**
     * Update status text with current iteration information
     */
    public void updateStatus()
    {
    	String text = "Iteration " + currentIter + " of " + maxIters;
    	if (!animThread.isRunning()) text += " [PAUSED]";
    	this.statusBar.setText(text);
    	
    }

    /**
     * Updates the GUI with next iteration data.
     * @param maxIter Maximum iteration count to load
     * @return True if GUI image updated, false otherwise
     */
    public boolean updateImage (int iter)
    {
        return canvas.updateImage(iter, this.getGraphics(), 0, 40);
    }
    
    /**
     * Manually step through iterations
     * @param delta steps to move (may be +ve or -ve)
     */
    public void step (int delta)
    {
    	/* No manual stepping if animation running */
    	//if (animThread.isRunning()) return;
    	
    	currentIter += delta; 
    	if (currentIter > maxIters) currentIter = 0;
    	else if (currentIter < 0) currentIter = maxIters;
    	
    	updateImage(currentIter);
    	updateStatus();
    }

    public void windowActivated(WindowEvent ev) 
    {
    	/* repaint screen when window regains focus */
    	/* This seems to also stop the flickering during animation :) */
    	updateImage(currentIter); 
    }
    
    public void windowIconified(WindowEvent ev) 
    {
    	/* Pause animation when window minimised */
    	animThread.pause();
    }
    
    /* Override abstract methods we don't need */
    public void keyTyped(KeyEvent ev) {}
    public void keyReleased(KeyEvent ev) {}
    public void windowClosed(WindowEvent ev) {}
    public void windowOpened(WindowEvent ev) {}
    public void windowDeactivated(WindowEvent ev) {}
    public void windowDeiconified(WindowEvent ev) {}

}
