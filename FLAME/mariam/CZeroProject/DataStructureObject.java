import java.util.*;
import java.awt.*;

public class DataStructureObject {

	private String itsName;
	private Vector itsVars;
	private int itsVarsCount;
	
	public DataStructureObject()
	{
		itsVarsCount=0;
		itsVars=new Vector();
	}//close:constructor
	
	public void additsVars(String varType, String varName)
	{
		VariableData varsTemp=new VariableData();
		varsTemp.setItsAgentVarType(varType);
		varsTemp.setItsAgentVarName(varName);
		varsTemp.setItsAgentVarValue("");
		itsVars.addElement(varsTemp);
		itsVarsCount++;
	}//close:additsVars()

	public String getItsName() {
		return itsName;
	}//close:getItsName()

	public void setItsName(String itsName) {
		
		this.itsName = itsName;
	}//close:setItsName()

	public int getItsVarsCount() {
		return itsVarsCount;
	}//close:getItsVarsCount()

	public void setItsVarsCount(int itsVarsCount) {
		this.itsVarsCount = itsVarsCount;
	}//close:setItsVarsCount()
	
	public VariableData getIndVariableDS(int pos)
	{
		VariableData varValue;
		varValue= (VariableData)itsVars.elementAt(pos);
		return varValue;
	}//close: getIndVariableDS()
	
}//DataStructureObject 
