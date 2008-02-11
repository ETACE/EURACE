import java.util.*;

/**
 * @author Mariam Kiran
 * This class holds the agents variables for the hashmap
 * Need another class to hold the variable values to write to 0xml
 * records variable names, types and starting values here.
 * Data variable can be of varying lengths- need to think of efficient solution!
 * presently making a vector which hold instances of variable class
 *  */

public class AgentTypeData {
	
	private int AgentTypeNumber;
	private int varCounter; //number of variables
	VariableData varList;
	Vector vars;
	
	public AgentTypeData()
	{
		varCounter=0;
		vars=new Vector(0);
	}//constructor
	
	public void addVars(String varType, String varName)
	{
		varList=new VariableData();
		varList.setItsAgentVarType(varType);
		varList.setItsAgentVarName(varName);
		varList.setItsAgentVarValue("");
		vars.addElement(varList);
		varCounter++;
	}//close:addVars()
	
	public int getVarCounter()
	{
		return varCounter;
	}//close:getVarCounter()
	
	public VariableData getIndVariable(int pos)
	{
		VariableData varValue;
		varValue= (VariableData)vars.elementAt(pos);
		return varValue;
	}//close:getIndVariable()

	public int getAgentTypeNumber() {
		return AgentTypeNumber;
	}//close:getAgentTypeNumber()

	public void setAgentTypeNumber(int agentTypeNumber) {
		AgentTypeNumber = agentTypeNumber;
	}//close:setAgentTypeNumber()

}// AgentTypeData
