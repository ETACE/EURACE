
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
import javax.swing.table.*;
import javax.swing.border.*;
import java.util.*;

/*
 * Panel display list of variables of the agent
 * repaint method needs to refresh the list
 */
public class DataPanel extends JPanel implements TableModelListener{
	
	private JTable itsAgentTable;
	private AgentData itsDefaultAgent=null;
	private int itsDefaultColumn=0;
	private String[] columnNames;
	private String[] varTypes;
	private Object[][] rows;
	private TableModel tableMod;
	int i;
	Vector tableRows,tableColumns;
	DefaultTableModel tableModel;
	TableColumn itsCol;
	String auto="AUTO";
	Map itsDatatypeMap;
	int itsDatatTypeListSize;
	int checkedFlag=0;
	int dataArrayCounter=0;
	DataStructureObject[] itsDataType;
	JFrame parent;
	String[] arrayCollection;
	private JTextArea itsTextArea;
	
	public DataPanel(AgentData object,Map dtmap,JFrame parent)
	{
		int i;
		itsDefaultAgent=new AgentData();
		itsDefaultAgent=object;
		itsDatatypeMap=new HashMap();
		itsDatatypeMap=dtmap;
		itsDatatTypeListSize=itsDatatypeMap.size();
		parent=parent;
		//put datastructs into class
		itsDataType=new DataStructureObject[itsDatatTypeListSize];
		for(i=0;i<itsDatatTypeListSize;i++)
		{
			itsDataType[i]=new DataStructureObject();
			itsDataType[i]=(DataStructureObject)itsDatatypeMap.get(i);
		}
		
		columnNames=new String[itsDefaultAgent.getItsAgentTypeData(0).getVarCounter()];
		varTypes=new String[itsDefaultAgent.getItsAgentTypeData(0).getVarCounter()];
		rows=new Object[itsDefaultAgent.getItsAgentTypeData(0).getVarCounter()][itsDefaultAgent.getItsAgentTypeData(0).getVarCounter()];
	
		for (i=0;i<itsDefaultAgent.getItsAgentTypeData(0).getVarCounter();i++)
		{
			columnNames[i]=new String();
			columnNames[i]=itsDefaultAgent.getItsAgentTypeData(0).getIndVariable(i).getItsAgentVarName();
		}
		
		for (i=0;i<itsDefaultAgent.getItsAgentTypeData(0).getVarCounter();i++)
		{
			varTypes[i]=new String();
			varTypes[i]=itsDefaultAgent.getItsAgentTypeData(0).getIndVariable(i).getItsAgentVarType();
		}
		
		tableRows=new Vector();
		tableColumns=new Vector();
		this.setFont(new Font("Serif", Font.BOLD, 14));
		addColumns(columnNames);
	
		tableModel=new DefaultTableModel();
		tableModel.setDataVector(tableRows,tableColumns);
		
		itsAgentTable=new JTable(tableModel);
		
		
		itsAgentTable.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);
		itsAgentTable.setRowSelectionAllowed(false);
		setLayout(new BorderLayout());
		add(new JScrollPane(itsAgentTable),BorderLayout.CENTER);
	    itsAgentTable.getModel().addTableModelListener(this);
	    //textarea
	    Border etched = BorderFactory.createEtchedBorder();
	    Border titled = BorderFactory.createTitledBorder(etched,"Notes");
	    
	    itsTextArea=new JTextArea(2,5);
	  
	    itsTextArea.setBorder(titled);
		itsTextArea.setEditable(false);
		add(new JScrollPane(itsTextArea),BorderLayout.SOUTH);
		itsTextArea.setText("");
		
	}//close:constructor
	
	
	
	public void addColumns(String[] columnNames)
	{
		
		tableColumns.addElement("Number of Agents");
		for(int i=0;i<columnNames.length;i++)
		{
			tableColumns.addElement((String)columnNames[i]);
		}
	}//close:addColumns()
	
	public void addRow()
	{
		int i;
		int j;
		Vector newRow=new Vector();
	//	System.out.println("columnnames " + columnNames.length);
	//	System.out.println("tablecolumnnames " + tableColumns.size());
		for(i=0;i<tableColumns.size();i++)
		{
	
			newRow.addElement((String) "");// creates new row
		}
	
		tableRows.addElement(newRow);
	
		for(i=0; i<tableColumns.size();i++)
		{
			itsCol=itsAgentTable.getColumnModel().getColumn(i);
			
			//anything else data structs
			itsCol.setCellEditor(new MyTableCellEditor(checking_DS(i)));// action should be added only to columns for datatypes
			
				
		}
	
		itsAgentTable.addNotify();
		
	}//close:addRow()
	
	public void tableChanged(javax.swing.event.TableModelEvent source)     
	{
		int rowIndex=0;
		int colIndex=0;
		int i;
		int arraybracket=0;
		String tempString= null;
		String tempValue=null; 
		int a;
		String arrayValues=null;
		String compileAnswer="{";
		String twoBrackets=null;
		
		tableMod=(TableModel)source.getSource();
		
		if (tableMod.isCellEditable(itsAgentTable.getSelectedColumn(), itsAgentTable.getSelectedRow()))
		{
			//System.out.println("column "+tableMod.getColumnName(itsAgentTable.getSelectedColumn()));
		    tempString=(String)tableMod.getColumnName(itsAgentTable.getSelectedColumn());
			
			rowIndex=itsAgentTable.getSelectedRow();
			colIndex=itsAgentTable.getSelectedColumn();
			arraybracket=checking_array(tempString);//tempstring name of column
			dataArrayCounter=arraybracket;
			
		}
			
		
		switch(source.getType())
		{
			case TableModelEvent.UPDATE:
				
			
				//System.out.println("column: "+ itsAgentTable.getSelectedColumn()+"row: "+itsAgentTable.getSelectedRow()+" value" + itsAgentTable.getValueAt(itsAgentTable.getSelectedRow(),itsAgentTable.getSelectedColumn()).toString());//<----MARY: value of cell
				tempValue=itsAgentTable.getModel().getValueAt(itsAgentTable.getSelectedRow(),itsAgentTable.getSelectedColumn()).toString();
				
				//checking numeric value for number of agents
				if(tempString.equals("Number of Agents"))
				{
					//check value in bounds
					if(isInteger(tempValue)==false)
					{
						JOptionPane.showMessageDialog(null,"Number of Agents should be numeric!");
					}
				}
				
				//checking ids
				if(((tempString.equals("id"))|| (tempString.equals("ID")))&& (tempValue!="Auto"))//id
				{
				itsAgentTable.getModel().setValueAt("Auto",rowIndex,colIndex);
				itsTextArea.setText( tempString + " will have auto generated values.");
				}
				//checking values
				//checking dynamic arrays
				if ((checking_dynamicarrays(colIndex)==true)&&(tempValue!="Auto"))//dynamic arrays
				{
					itsAgentTable.getModel().setValueAt("Auto",rowIndex,colIndex);
				}
				//checking arrays
				if((arraybracket>0)&&(checking_DS(colIndex)==false))
				{
					itsTextArea.setText( tempString + " is an array of size ["+ arraybracket +"]");
					JFrame arrayFrame=new ExtraFrame(arraybracket,whatisMyDataType(colIndex), tableMod,rowIndex,colIndex,itsDatatypeMap,0);
																	
				}
				
				if(checking_DS(colIndex)==true)//datastructure exists
				{
					for(i=0;i<itsDatatTypeListSize;i++)
					{
						if(varTypes[colIndex-1].equals(itsDataType[i].getItsName()))
						{	//need to pass the datastructure map cause to handle nested ds					
							//JFrame ds=new DataStructFrame(itsDataType[i], tableMod,rowIndex,colIndex,itsDatatypeMap,this,0);
							//ds.show(true);
							itsTextArea.setText( tempString + " is a data structure of size ["+ arraybracket +"]");
							JFrame arrayFrame=new ExtraFrame(arraybracket,whatisMyDataType(colIndex), tableMod,rowIndex,colIndex,itsDatatypeMap,1);
						
						}
					}
				}
				
				//random number input
				if(tempValue.indexOf("random")>-1)
				{
					itsAgentTable.getModel().setValueAt(checking_random(tempValue),rowIndex,colIndex);
				}
			
				itsTextArea.setText("Table value updated: " + itsAgentTable.getValueAt(rowIndex,colIndex));
		
	
			
				break;
			
			
		}
	}//close:tableChanged()
	
	
	
	
	
	
	public void updateValueAgentData()
	{
		
		//check value is correct
	}//close:updateValueAgentData()
	
	public int getRowNumbers()
	{
		
		return tableRows.size();
	}//close:getRowNumbers()
	
	public String getTableValue(int rowIndex,int colIndex)
	{
		
		String tempStr=(String)itsAgentTable.getValueAt(rowIndex,colIndex);
		//System.out.println("column: "+ colIndex +"row: "+ rowIndex +" value" + itsAgentTable.getValueAt(rowIndex,colIndex));//<----MARY: value of cell
		// setting values of variables in the agentdata class
		return tempStr;
	}//close:getTableValue()
	
	public void writeAgentData()
	{
		int i;
		int j;
		//add rowvectors for type
		if(tableRows.size()>0)
		{
			for(i=0;i<tableRows.size();i++)
			{
				AgentTypeData temp=new AgentTypeData();
				itsDefaultAgent.addType(temp);
			
			}
		}
	
		
		for (i=0;i<tableRows.size();i++)
		{
			String firstnos=(String)itsAgentTable.getValueAt(i,0);
			
			itsDefaultAgent.getItsAgentTypeData(i).setAgentTypeNumber(Integer.parseInt(firstnos));
			for(j=1;j<tableColumns.size();j++)
			{
				if(checking_dynamicarrays(j)==false)
				{
					itsDefaultAgent.getItsAgentTypeData(i).getIndVariable(j-1).setItsAgentVarValue((String)(itsAgentTable.getValueAt(i,j)));
				}
				else 
					itsDefaultAgent.getItsAgentTypeData(i).getIndVariable(j-1).setItsAgentVarValue("{}");
				//System.out.println(itsDefaultAgent.getItsAgentTypeData(i).getIndVariable(j-1).getItsAgentVarName());
				//System.out.println((String)(itsAgentTable.getValueAt(i,j)));
						
			}
		}
	
	}//close:writeAgentData()
	
	public AgentData getUpdateAgentData()
	{
		int itsTypes=itsDefaultAgent.getTypeCounter()-1;
		int varnos=itsDefaultAgent.getItsAgentTypeData(0).getVarCounter();
		int i,j;
	
		for(i=0;i<itsTypes;i++)
		{
			for(j=0;j<varnos;j++)
			{
		//	System.out.println("variable "+ itsDefaultAgent.getItsAgentTypeData(i).getIndVariable(j).getItsAgentVarName()+ " value "+ itsDefaultAgent.getItsAgentTypeData(i).getIndVariable(j).getItsAgentVarValue());
			}
		}
		
		return itsDefaultAgent;
		
	}//close:getUpdateAgentData()
	
	public Boolean checking_dynamicarrays(int colindex)
	{
		if(colindex!=0)
		{	
			String temparray=varTypes[colindex-1];
			int dy_array= temparray.indexOf("_array");
		//	System.out.println(dy_array);
			if(dy_array>-1)
			{
			itsTextArea.setText(columnNames[colindex-1] + " is a dynamic array.");
			return true;
			}
			else 
				return false;
		}
		else 
			return false;
	}//close:checking_dynamicarrays()
	
	public Boolean checking_DS(int colindex)
	{
		if(colindex!=0)
		{
			int var_index=colindex-1;
		//	System.out.println("var: " + varTypes[var_index]);
			if(varTypes[var_index].equals("int") ||(varTypes[var_index].equals("double"))||(varTypes[var_index].equals("char"))||(checking_dynamicarrays(colindex)==true))
			{
			//	System.out.println("return false");
				return false;
			}
			else 
				return true;
		}
		else 
			return false;
	}//close: checking_DS()
	
	public Vector whatisMyDataType(int colIndex)
	{
		Vector typeVector=new Vector();
		System.out.println("Datatype "+ varTypes[colIndex-1]);
		typeVector.addElement((String)varTypes[colIndex-1]);
		//add the name of the variable to the second element in vector
		typeVector.addElement((String)columnNames[colIndex-1]);
		return typeVector;
	}//close:whatismydatatype
	
	
	public int checking_array(String temparray)
	{
		int is_arrayFirst= temparray.indexOf('[');
		int is_arrayLast=temparray.indexOf(']');
		Integer numInt;
		String number=null;
		if(is_arrayFirst>-1)
		{
			number=temparray.substring(is_arrayFirst+1,is_arrayLast);
			numInt=Integer.parseInt(number);
			System.out.println("Array number="+numInt);
			
			return numInt.intValue();
		}
		else return 0; 
			
		
	}//close:checkin_array()
	
	public void getvalue(String temp, int a)
	{
		System.out.println("temp "+ temp);
		arrayCollection[a]=temp;
		
		
	}//close:getValue()
	
	
	public boolean isInteger(String val)
	{
		try
		{
			Integer.parseInt(val);
			return true;
		}
		catch(Exception e)
		{
			return false;
		}
	}//close:isInteger

	public String checking_random(String val)
	{
		//if random extract the limits
		String temp_randomInt="randomInt";
		String temp_randomDouble="randomDouble";
		int limitOne, limitTwo;
		String temp_first;
		int numberOne, numberTwo;
		Integer newvalue;
		String returnString;
		Long newOne;
		Double newTwo;
		
		if(val.indexOf(temp_randomInt)>-1)//if true
		{
			//first number
			limitOne=val.lastIndexOf("(")+1;
			limitTwo=val.lastIndexOf(",");
			temp_first=val.substring(limitOne, limitTwo);
			System.out.println(limitOne + " " +  temp_first);
			numberOne=Integer.parseInt(temp_first);
			System.out.println("number="+temp_first);
			//second number
			limitOne=val.lastIndexOf(",")+1;
			limitTwo=val.lastIndexOf(")");
			temp_first=val.substring(limitOne, limitTwo);
			System.out.println(limitOne + " " +  temp_first);
			numberTwo=Integer.parseInt(temp_first);
			System.out.println("number="+temp_first);
			
			if(numberTwo>=numberOne)
			{
				newOne=Math.round(numberOne + (Math.random()* (numberTwo-numberOne)));
			//	System.out.println("random Integer= " + newOne);
				newvalue=newOne.intValue();
			//	System.out.println("random Integer= " + newvalue);
			//	System.out.println("rounded = " + Math.round(newvalue));
				returnString=newvalue.toString();
				return returnString;
			}
			else
			{
				JOptionPane.showMessageDialog(null,"The second number should be bigger than the first!");
			}
		}//close int
		
		//double
		if(val.indexOf(temp_randomDouble)>-1)//if true
		{
			//first number
			limitOne=val.lastIndexOf("(")+1;
			limitTwo=val.lastIndexOf(",");
			temp_first=val.substring(limitOne, limitTwo);
			numberOne=Integer.parseInt(temp_first);
			System.out.println("number="+temp_first);
			//second number
			limitOne=val.lastIndexOf(",")+1;
			limitTwo=val.lastIndexOf(")");
			temp_first=val.substring(limitOne, limitTwo);
			numberTwo=Integer.parseInt(temp_first);
			System.out.println("number="+temp_first);
			
			if(numberTwo>=numberOne)
			{
				//System.out.println("random number");
				newTwo=numberOne + (Math.random()* (numberTwo-numberOne));
				System.out.println("random Double= " + newTwo);
				//System.out.println("here");
			//	System.out.println("rounded = " + Math.round(newvalue));
				//System.out.println("here2");
				returnString=newTwo.toString();
				return returnString;
			}
			else
			{
				JOptionPane.showMessageDialog(null,"The second number should be bigger than the first!");
			}
		}//close double
		
		System.out.println("null printing");
		return null;
		
				
	}//close:checking_Random
	
	
}//close:DataPanel
