
import java.awt.*;

import javax.swing.*;
import javax.swing.event.*;
import javax.swing.table.*;
import java.awt.event.*;
import java.util.Map;

public class DataStructFrame extends JFrame implements ActionListener{
	private JButton okButton;
	String [] varnames;
	JTextField[] varValues;
	int varct;
	String nameDs;
	DataStructureObject dsObjDefault;
	TableModel tab;
	int rowI,colI;
	String varTypeTemp=null;
	int itsDatatTypeListSize=0;
	Map itsDatatypeMap;
	DataStructureObject[] itsDataType;
	String arrayCollection=null;
	boolean flag_array;
	DataPanel itsDataPanel;
	int arrayVar;
	
	DataStructFrame(DataStructureObject dsObj, TableModel tbmod, int rowIndex, int colIndex,Map dtmap,DataPanel itsdatapanel, int a)
	{
		setSize(750,600);
		addWindowListener(new WindowAdapter()
			{
				public void windowClosing(WindowEvent e)
				{	}
			});
		
		
		int i;
		dsObjDefault=dsObj;
		varct=dsObjDefault.getItsVarsCount();
		varnames=new String[varct];
		varValues=new JTextField[varct];
		nameDs=dsObjDefault.getItsName();
		tab=tbmod;
		rowI=rowIndex;
		colI=colIndex;
		itsDatatypeMap=dtmap;
		itsDataPanel=itsdatapanel;
		arrayVar=a;
		itsDatatTypeListSize=itsDatatypeMap.size();
		//put datastructs into class
		itsDataType=new DataStructureObject[itsDatatTypeListSize];
		for(i=0;i<itsDatatTypeListSize;i++)
		{
			itsDataType[i]=new DataStructureObject();
			itsDataType[i]=(DataStructureObject)itsDatatypeMap.get(i);
		}
		
		JPanel itsPanel=new JPanel();
		itsPanel.setLayout(new GridLayout(varct,2));
		setTitle(nameDs);
		for(i=0;i<varct;i++)
		{
			//collect var names in string varnames
			varnames[i]=dsObjDefault.getIndVariableDS(i).getItsAgentVarName();
			varTypeTemp=dsObjDefault.getIndVariableDS(i).getItsAgentVarType();
			itsPanel.add(new JLabel(varnames[i]));
			varValues[i]=new JTextField("");
			varValues[i].addKeyListener(new KeyAdapter(){
				public void keyPressed(java.awt.event.KeyEvent evt)
				{
	                if(checking_DS(varTypeTemp)==true)
	                {
	                //	newWindow();
	                }
	            }
			});
			itsPanel.add(varValues[i]);
					
		}
	
		JPanel butPanel=new JPanel();
		okButton=new JButton("Ok");
		
		okButton.addActionListener(this);
		butPanel.add(okButton);
		
		
		setSize(240,60*varct);
		
		setLocation(new Point(60,60));
		setResizable(false);
		setAlwaysOnTop(true);
	
		itsPanel.setPreferredSize(new Dimension(300,300));
		
		Container cp=getContentPane();
		cp.add(itsPanel,"Center");
		cp.add(butPanel,"South");
	}//constructor
	
	public void actionPerformed(ActionEvent evt)
	{
		int i;
		String tempForm=null;
		Object src=evt.getSource();
		if (src==okButton)
		{
			//get values into the dtataobject 
			for(i=0;i<varct;i++)
			{
				dsObjDefault.getIndVariableDS(i).setItsAgentVarValue(varValues[i].getText());
			}
			
			//form the string
			tempForm="{".concat(varValues[0].getText());
			for(i=1;i<varct;i++)
			{	
				tempForm=tempForm.concat(",");
				tempForm=tempForm.concat(varValues[i].getText());
				
			}
			tempForm=tempForm.concat("}");
			tab.setValueAt(tempForm, rowI, colI);
			itsDataPanel.getvalue(tempForm,arrayVar);
			
			this.setVisible(false);
		}
	}//close:actionPerformed()
	
	
	public Boolean checking_DS(String varType)
	{
	//	System.out.println("var: " + varType);
		if(varType.equals("int") ||(varType.equals("double"))||(varType.equals("char"))||(checking_dynamicarrays(varType)==true))
		{
		//	System.out.println("return false");
			return false;
		}
		else 
			return true;
	}//close: checking_DS()
	
	public Boolean checking_dynamicarrays(String varType)
	{
		String temparray=varType;
		int dy_array= temparray.indexOf("_array");
		if(dy_array>-1)
		{
			return true;
		}
		else 
			return false;
	}//close:checking_dynamicarrays()
	
	public void newWindow()
	{
		int i;
		for(i=0;i<itsDatatTypeListSize;i++)
		{
			if(varTypeTemp.equals(itsDataType[i].getItsName()))
			{
			//	JFrame ds=new DataStructFrame(itsDataType[i], tab,rowI,colI,itsDatatypeMap);
			//	ds.show(true);
			}
		}
	}//close:newWindow()
	
	
}//DataStructFrame
