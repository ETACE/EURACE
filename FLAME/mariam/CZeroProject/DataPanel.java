
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
import javax.swing.table.*;
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
		add(new JScrollPane(itsAgentTable),BorderLayout.CENTER);
	    itsAgentTable.getModel().addTableModelListener(this);
	    
	
		
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
			//System.out.println("Table cell selected:");// check value
			//System.out.println("column "+tableMod.getColumnName(itsAgentTable.getSelectedColumn()));
		    tempString=(String)tableMod.getColumnName(itsAgentTable.getSelectedColumn());
			
			rowIndex=itsAgentTable.getSelectedRow();
			colIndex=itsAgentTable.getSelectedColumn();
			arraybracket=checking_array(tempString);
			dataArrayCounter=arraybracket;
			
		}
			
		
		switch(source.getType())
		{
			case TableModelEvent.UPDATE:
				
			
				//System.out.println("column: "+ itsAgentTable.getSelectedColumn()+"row: "+itsAgentTable.getSelectedRow()+" value" + itsAgentTable.getValueAt(itsAgentTable.getSelectedRow(),itsAgentTable.getSelectedColumn()).toString());//<----MARY: value of cell
				tempValue=itsAgentTable.getValueAt(itsAgentTable.getSelectedRow(),itsAgentTable.getSelectedColumn()).toString();
				
				if((tempString.equals("id"))&& (tempValue!="Auto"))//id
				{
				itsAgentTable.getModel().setValueAt("Auto",rowIndex,colIndex);
				}
				//checking values
				
				if ((checking_dynamicarrays(colIndex)==true)&&(tempValue!="Auto"))//dynamic arrays
				{
					itsAgentTable.getModel().setValueAt("Auto",rowIndex,colIndex);
				}
				
				if((checking_DS(colIndex)==true)&&((arraybracket==0)))//single ds and no array
				{
					for(i=0;i<itsDatatTypeListSize;i++)
					{
						if(varTypes[colIndex-1].equals(itsDataType[i].getItsName()))
						{						
							JFrame ds=new DataStructFrame(itsDataType[i], tableMod,rowIndex,colIndex,itsDatatypeMap,this,0);
							ds.show(true);
						
						}
					}
				}
			
				
				if((arraybracket>0)&&(tempValue.charAt(0)!='{')&&((checking_DS(colIndex)==false)))//arrays single data
				{
					
				
					for(a=0;a<arraybracket;a++)//for default datatype
					{
						String question="Enter element " + a + " for " +tempString;
						arrayValues=JOptionPane.showInputDialog(question);
						compileAnswer= compileAnswer.concat(arrayValues);
						if(a!=arraybracket-1)
						{
							compileAnswer=compileAnswer.concat(",");
						}
					}
					compileAnswer=compileAnswer.concat("}");
					itsAgentTable.getModel().setValueAt(compileAnswer,rowIndex,colIndex);
					//input for ints,doubles
					
				}
				if(tempValue.length()>2)
				{
					twoBrackets=tempValue.substring(0, 2);
				}
				//System.out.println("2 brackets " + twoBrackets);
				if((checking_DS(colIndex)==true)&&(dataArrayCounter>0)&&(tempValue.equals(twoBrackets)==false))//ds array
				{
					for(i=0;i<itsDatatTypeListSize;i++)
					{
						if(varTypes[colIndex-1].equals(itsDataType[i].getItsName()))
						{						
							System.out.println("structure array");
							arrayCollection=new String[arraybracket];
							
							for(a=0;a<arraybracket;a++)
							{
								a=0;
								dataArrayCounter--;
								arrayCollection[a]=new String("");
								System.out.println("value of a " + a );
								JFrame ds=new DataStructFrame(itsDataType[i], tableMod,rowIndex,colIndex,itsDatatypeMap,this,a);
								ds.show(true);
								//tempValue=itsAgentTable.getValueAt(itsAgentTable.getSelectedRow(),itsAgentTable.getSelectedColumn()).toString();
								//compileAnswer= compileAnswer.concat(tempValue);
							//	System.out.println("compileanswer " + compileAnswer);
								if(a!=arraybracket-1)
								{
								//	compileAnswer=compileAnswer.concat(",");
									
								}
							}
						//	compileAnswer=compileAnswer.concat("}");
							itsAgentTable.getModel().setValueAt(compileAnswer,rowIndex,colIndex);
							
						
						}
					}
				}
			
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
	
	public int checking_array(String temparray)
	{
		int is_arrayFirst= temparray.indexOf('[');
		int is_arrayLast=temparray.indexOf(']');
		Integer numInt;
		String number=null;
	//	System.out.println("isarray : "+ is_array);
		if(is_arrayFirst>-1)
		{
			number=temparray.substring(is_arrayFirst+1,is_arrayLast);
			numInt=Integer.parseInt(number);
			System.out.println("number="+numInt);
			return numInt.intValue();
		}
		else return 0; 
			
		
	}//close:checkin_array()
	
	public void getvalue(String temp, int a)
	{
		System.out.println("temp "+ temp);
		arrayCollection[a]=temp;
		
		
	}//close:getValue()
	
	
	
	
}//close:DataPanel
