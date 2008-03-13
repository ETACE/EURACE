import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.table.*;
import java.util.*;
import javax.swing.event.*;

public class ExtraFrame extends JFrame implements ActionListener, TableModelListener{
	
	JTable table;
	TableModel tableMod;
	Vector rows,columns,columnsReceived;
	DefaultTableModel tabModel;
	
	JScrollPane scrollPane;
	
	JButton cmdOK;
	JPanel mainPanel,buttonPanel;
	
	ExtraFrame(int numberOfRows, Vector columnNames)
	{
		addWindowListener(new WindowAdapter()
		{
			public void windowClosing(WindowEvent e)
			{}
		});
		rows=new Vector();
		columns= new Vector();
		int i;
		columnsReceived=columnNames;
		
		addColumns(columnsReceived);
		for(i=0;i<numberOfRows;i++)
		{
			addRows();
		}
		
		tabModel=new DefaultTableModel();
		tabModel.setDataVector(rows,columns);

		table = new JTable(tabModel);
		
		table.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);
		table.setRowSelectionAllowed(false);
		
		scrollPane= new JScrollPane(table);//ScrollPane

		

		table.getModel().addTableModelListener(this);
		
		buttonPanel=new JPanel();
		mainPanel=new JPanel();
		setTitle("Extra Frame for Arrays and DataStructures");
		cmdOK=new JButton("Ok");
		
		cmdOK.addActionListener(this);
		buttonPanel.add(cmdOK);
		mainPanel.setLayout(new BorderLayout());
		
		mainPanel.add("Center",scrollPane);
		mainPanel.add("South",buttonPanel);
		setLocation(new Point(100,100));
		setAlwaysOnTop(true);
		setSize(100,100);
		getContentPane().add(mainPanel);
		setVisible(true);
		
	}//end constructor
	
	
	
	public void addColumns(Vector c)
	{
		String objString;
		columns.addElement("No.");
		for(int i=0;i<c.size();i++)
		{
			objString=(String)c.elementAt(i);
			columns.addElement((String)objString);
		}
		
	}
	
	public void addRows()
	{
		Vector newRow=new Vector();
		for(int i=0;i<columns.size();i++)
		{
			newRow.addElement((String)"");
		}
		rows.addElement(newRow);
					
		//table.addNotify();
		
	}
	

	

	public void tableChanged(javax.swing.event.TableModelEvent source)     
	{
		String msg="";
        TableModel tabMod = (TableModel)source.getSource();
        switch (source.getType())
        {
        	case TableModelEvent.UPDATE://MARY------> returns the value changed!
        		msg="Table Value Updated for  cell "+table.getSelectedRow()+","+table.getSelectedColumn()+"\nWhich is "+table.getValueAt(table.getSelectedRow(),table.getSelectedColumn()).toString();
        		JOptionPane.showMessageDialog(null,msg,"Table Example",JOptionPane.INFORMATION_MESSAGE);
                break;

        }

    }//Table Changed Method

	public void selectCell(int row,int col)
    {
         if(row!=-1 && col !=-1)            
          {
          table.setRowSelectionInterval(row,row);
          table.setColumnSelectionInterval(col,col);
          }
    }

	public void actionPerformed(ActionEvent source)
    {
         if (source.getSource()==(JButton) cmdOK)
         {
            System.out.println("values entered");
            this.setVisible(false);
         }
      
      
    
    }//ActionList
	
}//end:extraframe
