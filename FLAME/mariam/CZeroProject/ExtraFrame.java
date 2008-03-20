import javax.swing.*;

import java.awt.*;
import java.awt.event.*;
import javax.swing.table.*;
import javax.swing.border.*;

import java.util.*;

import javax.swing.event.*;

public class ExtraFrame extends JFrame implements ActionListener, TableModelListener{
	
	JTable table;
	TableModel tableMod;
	Vector rows,columns,columnsReceived;
	DefaultTableModel tabModel;
	TableModel tabParent;
	JScrollPane scrollPane;
	int rowParent, colParent;
	JButton cmdOK;
	JPanel mainPanel,buttonPanel;
	Map itsDatatypeMap;
	DataStructureObject[] itsDataType;
	DataStructureObject dsObjDefault;
	int itsDatatTypeListSize=0;
	int itsWhatWindow;
	String[] varTypes;
	String[] varNames;
	private JTextArea itsExtraTextArea;
	
	ExtraFrame(int numberOfRows, Vector columnNames, TableModel tb, int rP, int cP,Map dtmap,int whatWindow)
	{
		addWindowListener(new WindowAdapter()
		{
			public void windowClosing(WindowEvent e)
			{}
		});
		
		int i;
		int cs;
		//parent values
		tabParent=tb;
		rowParent=rP;
		colParent=cP;
		itsDatatypeMap=dtmap;
		itsWhatWindow=whatWindow;
		System.out.println("its whatwindow" + itsWhatWindow);
//		for the data structure map
		itsDatatTypeListSize=itsDatatypeMap.size();
		itsDataType=new DataStructureObject[itsDatatTypeListSize];
		for(i=0;i<itsDatatTypeListSize;i++)
		{
			itsDataType[i]=new DataStructureObject();
			itsDataType[i]=(DataStructureObject)itsDatatypeMap.get(i);
		}
		

		
		rows=new Vector();
		columns= new Vector();

		columnsReceived=columnNames;
		//System.out.println("Values of parents "+ rP + " " +cP );
	
		addColumns(columnsReceived);
		
		
		for(i=0;i<numberOfRows;i++)
		{
			addRows(i);
		}
		
		if(numberOfRows==0)
		{
			addRows(0);
		}

				tabModel=new DefaultTableModel();
		tabModel.setDataVector(rows,columns);

		table = new JTable(tabModel);
		
		table.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);
		//table.setRowSelectionAllowed(false);
		
		scrollPane= new JScrollPane(table);//ScrollPane

		

		table.getModel().addTableModelListener(this);
		
		buttonPanel=new JPanel();
		mainPanel=new JPanel();
		setTitle(columnNames.elementAt(1) + ": Extra Frame for Arrays and DataStructures");
		cmdOK=new JButton("Ok");
		
		cmdOK.addActionListener(this);
		buttonPanel.add(cmdOK);
		mainPanel.setLayout(new BorderLayout());
		
		mainPanel.add("Center",scrollPane);
		mainPanel.add("South",buttonPanel);
		setLocation(new Point(100,100));
		setAlwaysOnTop(true);
		setSize(300,200);
		getContentPane().add(mainPanel);
		 //textarea
	    Border etched = BorderFactory.createEtchedBorder();
	    Border titled = BorderFactory.createTitledBorder(etched,columnNames.elementAt(1) + ": Extra Frame Notes");
	    
	    itsExtraTextArea=new JTextArea(1,1);
	  
	    itsExtraTextArea.setBorder(titled);
		itsExtraTextArea.setEditable(false);
		getContentPane().add(new JScrollPane(itsExtraTextArea),BorderLayout.SOUTH);
		itsExtraTextArea.setText("New Window Created!");
		
		setVisible(true);
		
	}//end constructor
	
	
	
	
	
	public void addColumns(Vector c)
	{
		String objString;
		int i,j;
		int varct;
		columns.addElement("No.");
		System.out.println("carried what window" + itsWhatWindow);
		if(itsWhatWindow==0)//0if array, 1 if ds
		{
			//if single array add one column name
			objString=(String)c.elementAt(1); //name of the variable
			columns.addElement((String)objString);
			varTypes=new String[1];
			varNames=new String[1];
			varTypes[0]=new String();
			varNames[0]=new String();
			varTypes[0]=(String)c.elementAt(0);
			varNames[0]=(String)c.elementAt(1);
			//add check for array
			if(checking_array(varNames[0])>0)
			{
				int is_arrayFirst= varNames[0].indexOf('[');
				varNames[0]=varNames[0].substring(0, is_arrayFirst);
			}
		}
		else	
		{	
			//if data structure add various column names
			//which ds?
			System.out.println("IS DATA STRUCT");
			for(i=0;i<itsDatatTypeListSize;i++)
			{
				objString=(String)c.elementAt(0); //type of datastruct
				System.out.println("Datatype 1 : " +objString);
				if(objString.equals(itsDataType[i].getItsName())) //found the ds
				{//get var ct
					
					varct=itsDataType[i].getItsVarsCount();
					varTypes=new String[varct];
					varNames=new String[varct];
					System.out.println("Datatype 1 var ct: " + varct);
					for(j=0;j<varct;j++)
					{
						columns.addElement((String)itsDataType[i].getIndVariableDS(j).getItsAgentVarName());
						varTypes[j]=new String();
						varTypes[j]=itsDataType[i].getIndVariableDS(j).getItsAgentVarType();
						
						varNames[j]=new String();
						varNames[j]=itsDataType[i].getIndVariableDS(j).getItsAgentVarName();
						//add check for nested ds here
					
					}
				}
			}
			
		}
		
	}
	
	public void addRows(int num)
	{
		Vector newRow=new Vector();
		for(int i=0;i<columns.size();i++)
		{
			if(i==0)
			{
				//System.out.println("Num carried over" + num);
				newRow.addElement(num+1);//adding number of element for first element
			}
			else
			{
				newRow.addElement((String)"");
			}
		}
		rows.addElement(newRow);
					
		//table.addNotify();
		
	}
	

	

	public void tableChanged(javax.swing.event.TableModelEvent source)     
	{
		String msg="";
		int rowIndex=0,colIndex=0;
        TableModel tabMod = (TableModel)source.getSource();
        String tempStringName;
        String tempValue;
        int arrayNum=0;
        
        if (tabMod.isCellEditable(table.getSelectedColumn(), table.getSelectedRow()))
		{
			//System.out.println("column "+tableMod.getColumnName(itsAgentTable.getSelectedColumn()));
		 //   tempStringName=(String)tableMod.getColumnName(table.getSelectedColumn());
			
			rowIndex=table.getSelectedRow();
			colIndex=table.getSelectedColumn();
			arrayNum=checking_array(varNames[colIndex-1]);
			
		}
        
        	
        switch (source.getType())
        {
        	case TableModelEvent.UPDATE://MARY------> returns the value changed!
        	//	msg="Table Value Updated for  cell "+table.getSelectedRow()+","+table.getSelectedColumn()+"\nWhich is "+table.getValueAt(table.getSelectedRow(),table.getSelectedColumn()).toString();
        	//	JOptionPane.showMessageDialog(null,msg,"Table Example",JOptionPane.INFORMATION_MESSAGE);
		
	
        		tempValue=table.getValueAt(rowIndex,colIndex).toString();
        		//add nested check here
        		System.out.println("Dataype of this column was " + varTypes[colIndex-1]);
        		//datastructure
               	if(isVariableaDS(varTypes[colIndex-1])==true)
				{
               		itsExtraTextArea.setText(varNames[colIndex-1] + " is a data Structure of size [" +arrayNum+ "]");
					JFrame arrayextraFrame=new ExtraFrame(arrayNum,myDataType(varTypes[colIndex-1],varNames[colIndex-1]), tabMod,rowIndex,colIndex,itsDatatypeMap,1);		
				}
               	//arrays
               	if((arrayNum>0) && (isVariableaDS(varTypes[colIndex-1])==false))
               	{
               		itsExtraTextArea.setText(varNames[colIndex-1] + " is an array of size [" +arrayNum+ "]");
               		JFrame arrayextraFrame=new ExtraFrame(arrayNum,myDataType(varTypes[colIndex-1],varNames[colIndex-1]), tabMod,rowIndex,colIndex,itsDatatypeMap,0);
               	}
               	//dynamic arrays
               	if ((checking_dynamicarrays(varTypes[colIndex-1], varNames[colIndex-1])==true)&&(tempValue!="Auto"))//dynamic arrays
				{
					table.getModel().setValueAt("Auto",rowIndex,colIndex);
				}
//              random number input
				if(tempValue.indexOf("random")>-1)
				{
					table.getModel().setValueAt(checking_random(tempValue),rowIndex,colIndex);
				}
			
               	//displaying updated
               	itsExtraTextArea.setText("Table value updated: " + table.getValueAt(rowIndex, colIndex));
                
               	break;


        }

    }//Table Changed Method

	public void selectCell(int row,int col)
    {
       /*  if(row!=-1 && col !=-1)            
          {
          table.setRowSelectionInterval(row,row);
          table.setColumnSelectionInterval(col,col);
          }
          */
    }

	public void actionPerformed(ActionEvent source)
    {
         if (source.getSource()==(JButton) cmdOK)
         {
        	 int i,j;
        	 String tempValue, strValue;
        	 tempValue="{";
        	 if(itsWhatWindow==0)//if single element array 
        	 {
        		 for(i=0;i<rows.size();i++)
        		 {
        			 //System.out.println("Entered loop");
        			 if(i>0)
        			 {
        				 tempValue=tempValue.concat(","); 
        			 }
        			 strValue=(String) table.getValueAt(i,1);
        			 tempValue=tempValue.concat(strValue);
        			 //System.out.println("value "+ i + table.getValueAt(i,1));
        		 	 //System.out.println("loop one ended");
        		 }
        		 tempValue=tempValue.concat("}");
        		 tabParent.setValueAt(tempValue, rowParent,colParent);
        	 }//if array only
        	 
        	 if(itsWhatWindow==1)//if data structure
        	 {
        		 //couple values in row then column wise
        		 for(j=0;j<rows.size();j++)
        		 {
        			 tempValue=tempValue.concat("{");
        			 for(i=1;i<columns.size();i++)
        			 {
        				 //System.out.println("Entered loop");
        				 if(i>1)
        				 {
        					 tempValue=tempValue.concat(","); 
        				 }
        				 strValue=(String) table.getValueAt(j,i);
        				 tempValue=tempValue.concat(strValue);
        			 }
        			 tempValue=tempValue.concat("}");
        		 }
        		 tempValue=tempValue.concat("}");
        		 tabParent.setValueAt(tempValue, rowParent,colParent);
        	 }//ifwhatwindow1
       	 
        	 this.setVisible(false);
         }//if buttoncmdok
      
      
    
    }//ActionList
	
	public void writingData()
	{
		
	}//close:writingData
	
	public boolean isVariableaDS(String dataType)
	{
		System.out.println("Checking datatype 1" + dataType);
			if(dataType.equals("int") ||(dataType.equals("double"))||(dataType.equals("char"))||(checking_dynamicarrays(dataType)==true))
			{			
				System.out.println("Answer is false");
				return false;
			}
			else 
			{
				System.out.println("Answer is true");
				return true;
			}
	}
	
	//public boolean checkDynamicArrays()
	public Boolean checking_dynamicarrays(String arrayQuery)
	{
		//String temparray=varTypes[colindex-1];
		int dy_array= arrayQuery.indexOf("_array");
		
		if(dy_array>-1)
		{
			System.out.println("Dynamic array found!");
		//itsTextArea.setText(columnNames[colindex-1] + " is a dynamic array.");
			return true;
		}
		else 
			return false;
		
	}//close:checking_dynamicarrays()
	
	
	public Vector myDataType(String vType, String vName)
	{
		Vector typeVector=new Vector();
		System.out.println("Datatype "+ vType);
		typeVector.addElement((String)vType);
		//add the name of the variable to the second element in vector
		typeVector.addElement((String)vName);
		return typeVector;
	}//endmydatatype
	
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
	
	public Boolean checking_dynamicarrays(String vType, String vName)
	{
		int dy_array= vType.indexOf("_array");
		if(dy_array>-1)
		{
			itsExtraTextArea.setText( vName + " is a dynamic array.");
			return true;
		}
		else 
			return false;
		
	}//close:checking_dynamicarrays()
	
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
		return null;
				
	}//close:checking_Random
	
}//end:class extraframe
