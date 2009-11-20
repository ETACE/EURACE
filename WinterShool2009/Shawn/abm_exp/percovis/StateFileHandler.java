import java.io.*;
import org.xml.sax.*;
import org.xml.sax.helpers.*;

public class StateFileHandler extends DefaultHandler{
	
	private AgentList alist = null; // Output data object
	private int width, height; // Grid dimensions
	
	// Control flags
	private boolean widthSet  = false;
	private boolean heightSet = false;
	private boolean gridDefined = false;
	private boolean reparseNeeded = false;
	
	// Buffer for storing CHARACTER events from SAX
	private CharArrayWriter charBuffer = new CharArrayWriter();
	
	// Temp storage for xagent data
	private int agentId;
	private int agentValue;
    private float agentX;
    private float agentY;
	private String agentName;

    public StateFileHandler(String filename) 
    {
        /* Parse XML using SAX2 parser */
        try {
        	
        	/* Instantiate input and parser objects */
        	InputSource inputXML = new InputSource(new FileReader(filename));
        	XMLReader xmlreader = XMLReaderFactory.createXMLReader();
        	
        	xmlreader.setContentHandler(this);
        	xmlreader.parse(inputXML);
        	
        	/* 
        	 * output Grid defined after width/height is read in.
        	 * Therefore, if width/height was not found before the 
        	 * agents, we would need to reparse the XML.
        	 */
        	if (reparseNeeded) xmlreader.parse(inputXML);
        	
        } catch (Exception e) {
        	e.printStackTrace();
        }
    }

    /**
     * @return AgentList object containing parsed data
     */
    public AgentList getAgentList () 
    {
        return alist;
    }
    
    public void characters(char[] buf, int start, int length) throws SAXException 
    {
    	charBuffer.write( buf, start, length );
    }
    
    public void startElement ( String nsURI, 
    		                   String localname, 
    		                   String qName, 
    		                   Attributes attr ) throws SAXException 
    {
    	charBuffer.reset();
    }
    
    public void endElement ( String nsURI, 
            				 String localname, 
            				 String qName ) throws SAXException 
    {    	
    	/* Instantiate ouput grid object when possible */
    	if ( !gridDefined && widthSet && heightSet )
    	{
    		alist = new AgentList(width, height);
    		gridDefined = true;
    	}
    	
    	/* First, look for width and height values so we can define output Grid */
    	if (localname.equals("width"))
    	{
    		width = Integer.parseInt(charBuffer.toString());
    		widthSet = true;
    		return;
    	}
    	else if (localname.equals("height"))
    	{
    		height = Integer.parseInt(charBuffer.toString());
    		heightSet = true;
    		return;
    	}
    	    	
    	/* If xagents defined before width/height, request for a 
    	 * second parse. Output grid must be set before we can 
    	 * fill in the data.
    	 */
    	if (localname.equals("xagent") && !gridDefined)
    	{
    		reparseNeeded = true;
    		return;
    	}
    	
    	/* No point continue with reading agent data if grid not yet
    	 * defined, of if reparse is needed
    	 */
    	if (reparseNeeded || !gridDefined) return;
    	
    	/* Store xagent memory */
    	if (localname.equals("name")) agentName = charBuffer.toString();
    	else if (localname.equals("id")) agentId = Integer.parseInt(charBuffer.toString());
    	else if (localname.equals("x")) agentX = Float.valueOf(charBuffer.toString()).floatValue();
    	else if (localname.equals("y")) agentY = Float.valueOf(charBuffer.toString()).floatValue();
    	/* else if (localname.equals("value")) agentValue = Integer.parseInt(charBuffer.toString()); */
    	
    	/* Write Circle memory to Grid */
    	else if (localname.equals("xagent") && agentName.equals("person"))
    	{
    		/* grid.setValue(id2row(agentId), id2col(agentId), agentValue); */
    		alist.addAgent(agentId, agentX, agentY);
    	}
    	
    }
    
    /** 
     * Convert agent ID to associated column in grid
     * Agent ID is expected to start from 1 and traverses the grid column-wise
     * Columns are indexed starting from 0.
     * @param id agent ID
     * @return associated column
     */
    private int id2col(int id)
    {
    	return (id - 1) % width;
    }
    
    /** 
     * Convert agent ID to associated row in grid
     * Agent ID is expected to start from 1 and traverses the grid column-wise
     * Rows are indexed starting from 0.
     * @param id agent ID
     * @return associated row
     */
    private int id2row(int id)
    {
    	return (id - id2col(id) - 1) / width;
    }
}
