/**
 * @author Mariam Kiran
 * This class holds the agents data variables for the hashmap
 * Need another class to hold the variable values to write to 0xml
 * records variable names, types and starting values here.
 *  */

public class VariableData {
	private String itsAgentVarName;
	private String itsAgentVarType;
	private String itsAgentVarValue;
	
	public VariableData()
	{
		itsAgentVarName = null;
		itsAgentVarType = null;
		itsAgentVarValue = null;
			
	}//constructor
	public String getItsAgentVarName() {
		return itsAgentVarName;
	}//close:getItsAgentVarName()
	public void setItsAgentVarName(String itsAgentVarName) {
		this.itsAgentVarName = itsAgentVarName;
	}//close:setItsAgentVarName()
	public String getItsAgentVarType() {
		return itsAgentVarType;
	}//close:getItsAgentVarType()
	public void setItsAgentVarType(String itsAgentVarType) {
		this.itsAgentVarType = itsAgentVarType;
	}//close:setItsAgentVarType()
	public String getItsAgentVarValue() {
		return itsAgentVarValue;
	}//close:getItsAgentVarValue()
	public void setItsAgentVarValue(String itsAgentVarValue) {
		this.itsAgentVarValue = itsAgentVarValue;
	}//close:setItsAgentVarValue()
	
}// VariableData 
