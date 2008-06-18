import java.awt.*;
import java.awt.Component.*;

import javax.swing.*;

import java.awt.event.*;

import javax.swing.JOptionPane;
import javax.swing.border.Border;
import javax.swing.event.*;

import java.io.*;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

import org.jdom.*;
import org.jdom.input.SAXBuilder;
import org.jdom.output.*;


public class AskFrame extends JFrame implements ActionListener{
	private Container itsContainer;
	private JButton itsNextBut, itsExitBut;
	private JPanel itsAskPanel;
	
	public AskFrame()
	{
		setTitle("CZero Application");
		int i;
		itsContainer=this.getContentPane();
		
		addWindowListener(new WindowAdapter()
		{
			public void windowClosing (WindowEvent e)
			{
				System.exit(0);
			}
		});
		itsNextBut=new JButton("Next");
		itsNextBut.addActionListener(this);
		itsExitBut=new JButton("Exit");
		itsExitBut.addActionListener(this);
		itsAskPanel=new JPanel();
		
		
		itsAskPanel.add(itsNextBut);
		itsAskPanel.add(itsExitBut);
		
		itsContainer.add(itsAskPanel,"Center");
		
	}
	
	public void actionPerformed(ActionEvent evt)
	{
		Object source=evt.getSource();
		int i=0;
		int j=0;
		int rowCount;
		String pop;
		if(source== itsNextBut)
		{
			//get component
			String text;
			String nullString=new String();
			//adding code for first initialisation of window:
		}
		else if(source==itsExitBut)
		{
			System.exit(0);
		}
	}//close:actionPerformed()
}
