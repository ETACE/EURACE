
public class AnimationThread extends Thread {
	private MyFrame frame;

    private boolean brakes = true;

    public AnimationThread (MyFrame f)
    {
        this.frame = f;
    }
    
    /* put on the brakes */
    public void pause() { brakes = true; }

    public boolean isRunning() { return !brakes; }

    /* start the animation loop */
    public void run()
    {
        brakes = false;

        try
        {
            /* loop continuously until brakes applied */
            while(!brakes)
            {
                frame.step(1);

                if (frame.currentIter == frame.maxIters) brakes = true;
                    
                sleep(100);
            }

        }
        catch (InterruptedException e) {}
    }
}
