

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;
import javax.swing.event.*;
import javax.swing.table.*;
import java.util.*;


public class MyTableCellEditor extends AbstractCellEditor implements TableCellEditor{
	
	JComponent itsComponent;
	int itsColumnNumber, itsRowNumber;
	public MyTableCellEditor(Boolean itsDs)
	{
		itsComponent=new JTextField();
		if(itsDs==true)
		{
			itsComponent.addKeyListener(new KeyAdapter(){
		
			public void keyPressed(java.awt.event.KeyEvent evt)
			{
                System.out.println("keyPressed**************************");
                
            }
		});
		}
		
	}//constructor
	
	public Component getTableCellEditorComponent(JTable table, Object value,boolean isSelected, int rowIndex, int vColIndex)
	{
		itsColumnNumber=vColIndex;
		itsRowNumber=rowIndex;
		if(isSelected)
		{
			//System.out.println("HERE");
		}
		((JTextField)itsComponent).setText((String) value);
		
		return itsComponent;
	}//close:getTableCellEditorComponent()
	
	public Object getCellEditorValue()
	{
		return ((JTextField)itsComponent).getText();
	}//close:getCellEditorValue()
	
	public boolean shouldSelectCell(EventObject anEvent)
	{
		//System.out.println("Column NUMBER: "+ itsColumnNumber);
		return true;
	}//close:shouldSelectCell(
	
	public int getitsColumnNumber()
	{
		return itsColumnNumber;
	}//close getitsColumnNumber()
	
	public int getitsRowNumber()
	{
		return itsRowNumber;
	}//close:getitsRowNumber()

}//MyTableCellEditor 
