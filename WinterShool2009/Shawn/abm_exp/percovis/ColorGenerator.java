import java.util.HashMap;
import java.util.Random;
import java.awt.Color;

public class ColorGenerator {
	
	private HashMap<Integer,Color> colours;
	private Random rnd;
	private final Color liquidColor = new Color(54, 195, 224);
	private final Color solidColor  = Color.black;
	
	public ColorGenerator()
	{
		/* Initialise hashtable and random number generator */
		colours = new HashMap<Integer,Color>();
		rnd = new Random();
		
		/* 0 should always return black */
		colours.put(new Integer(0), solidColor);
	}
	
	/**
	 * Get a color based on an input value. Returned colour should be
	 * be equal if identical input value is given unless that value
	 * has been 'stained', during which this.liquidColor is returned
	 * Input value of 0 will return this.solidColor
	 * @param value integer value used as index for a generated map of colours
	 * @return Color object
	 */
	public Color pickColour(int value)
	{
		Integer idx = new Integer(value);
		
		/* If cell value does not yet have a color associated to it */
		if (!colours.containsKey(new Integer(value)))
		{
			/* invent a new color and map to given value */
			Color newColour = inventColour();
			colours.put(idx, newColour);
			return newColour;
		}
		
		/* return previously mapped colour */
		else return (Color)colours.get(idx);
	}
	
	/**
	 * Manually stain top level element values
	 * @param value cell value to stain
	 */
	public void stain(int value)
	{
		colours.put(new Integer(value), liquidColor);
	}
	
	/**
	 * Generate a random colour
	 * @return Color object with random value
	 */
	private Color inventColour()
	{
		return new Color(rnd.nextInt());
	}
	
}
