
import java.util.*;

/**
 * @author Mariam Kiran
 * This class holds the agents variables for the hashmap
 * Need another class to hold the variable values to write to 0xml
 * records variable names, types and starting values here.
 * Data variable can be of varying lengths- need to think of efficient solution!
 * presently making a vector which hold instances of variable class
 *  */

public class AgentData {
	
	private String itsAgentName = null;
	private int typeCounter;// number of types
	private Vector itsAgentTypeData;
	AgentTypeData itsAgentTypeObject;
	
	public AgentData()
	{
		typeCounter=0;
		itsAgentTypeData=new Vector(0);// first type by default
		itsAgentTypeObject=new AgentTypeData();
		itsAgentTypeData.addElement(itsAgentTypeObject);
		typeCounter++;
	}//close:constructor
	
	
	
	
	public int getTypeCounter() {
		return typeCounter;
	}//close:getTypeCounter()
	
	public void setTypeCounter() {
		this.typeCounter = itsAgentTypeData.size();
	}//close:setTypeCounter()
	
	public String getItsAgentName() {
		return itsAgentName;
	}//close:getItsAgentName()
	
	public void setItsAgentName(String itsAgentName) {
		this.itsAgentName = itsAgentName;
	}//close:setItsAgentName()
	
	
	
	public String toString()
	{
		return itsAgentName;
	}//close:toString()




	public AgentTypeData getItsAgentTypeData(int i) {
		//System.out.println("iont"+i);
		AgentTypeData tempType=(AgentTypeData)this.itsAgentTypeData.get(i);
		return tempType;
	}//close:getItsAgentTypeData()
	
	public AgentTypeData getFirstElementTypeData()
	{
		AgentTypeData tempType=(AgentTypeData)this.itsAgentTypeData.firstElement();
		return tempType;
	}//close:getFirstElementTypeData()



	// add new type in agent type
	public void addType(AgentTypeData object)
	{
		//get variables from first element
		AgentTypeData itsFirst=getItsAgentTypeData(0);
		int i;
		for(i=0;i<itsFirst.getVarCounter();i++)
		{
			object.addVars(itsFirst.getIndVariable(i).getItsAgentVarType(), itsFirst.getIndVariable(i).getItsAgentVarName());
		}
		itsAgentTypeData.addElement(object);
		typeCounter++;
	}//close:addType()
	
	public void setItsAgentTypeData(Vector itsAgentTypeData) {
		this.itsAgentTypeData = itsAgentTypeData;
	}//close:setItsAgentTypeData()
	
	public Vector getVector()
	{
		return itsAgentTypeData;
	}//close:getVector()
	
}//AgentData 
