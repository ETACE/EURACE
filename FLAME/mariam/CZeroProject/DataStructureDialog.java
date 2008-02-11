import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class DataStructureDialog extends JDialog implements ActionListener{
	String [] varnames;
	JTextField[] varValues;
	int varct;
	JButton okButton, cancelButton;
	
	public DataStructureDialog(JFrame parent, DataStructureObject dsObj)
	{
	
		super(parent,"Connect",true);
		Container contentPane=getContentPane();
		int i;
		varct=dsObj.getItsVarsCount();
		varnames=new String[varct];
		varValues=new JTextField[varct];
		
		JPanel itsPanel=new JPanel();
		itsPanel.setLayout(new GridLayout(2,2));
		for(i=0;i<varct;i++)
		{
			itsPanel.add(new JLabel(varnames[i]));
			varValues[i]=new JTextField("");
			itsPanel.add(varValues[i]);
		}
		
		contentPane.add("Center",itsPanel);
		
		JPanel butPanel=new JPanel();
		okButton=new JButton("Ok");
		cancelButton=new JButton("Cancel");
		okButton.addActionListener(this);
		cancelButton.addActionListener(this);
		butPanel.add(okButton);
		butPanel.add(cancelButton);
		contentPane.add("South",butPanel);
		setSize(240,120);
	}
	
	public void actionPerformed(ActionEvent evt)
	{
		Object src=evt.getSource();
		if(src==okButton)
		{
			
		}
		else if(src==cancelButton)
		{
			
		}
		
	}

}
