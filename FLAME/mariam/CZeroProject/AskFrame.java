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


public class AskFrame extends JFrame implements ActionListener, ItemListener{
	private Container itsContainer;
	private JButton itsNextBut, itsExitBut;
	private JPanel itsAskPanel;
	private JRadioButton itsoldButton, itsnewButton;
	private ButtonGroup itsRadioGroup;
	private int itsChosen=0;
	
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
		
		itsoldButton=new JRadioButton("Old Version of XMML (For versions older than 0.15)",false);
		itsnewButton=new JRadioButton("New Version of XMML (For versions after than 0.15)",false);
		itsNextBut=new JButton("Next");
		itsNextBut.addActionListener(this);
		itsExitBut=new JButton("Exit");
		itsExitBut.addActionListener(this);
		itsAskPanel=new JPanel();
		
		itsAskPanel.add(itsoldButton);
		itsAskPanel.add(itsnewButton);
		itsAskPanel.add(itsNextBut);
		itsAskPanel.add(itsExitBut);
		
		//creating radiobutton
		//RadioButtonHandler handler=new RadioButtonHandler();
		itsoldButton.addItemListener(this);
		itsnewButton.addItemListener(this);
		itsRadioGroup=new ButtonGroup();
		itsRadioGroup.add(itsoldButton);
		itsRadioGroup.add(itsnewButton);
		
		itsAskPanel.setLayout(new FlowLayout());
		itsContainer.add(itsAskPanel,"Center");
//		 set the size and the position of the frame
		Toolkit toolKit = Toolkit.getDefaultToolkit();
		Dimension dimension = toolKit.getScreenSize();
		setSize(100, 100);
		pack();
		setVisible(true);
		setLocation(new Point(40,40));
		
		
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
			if(itsChosen==0)
			{
				JOptionPane.showMessageDialog(null,"No version was selected!","Comment", JOptionPane.INFORMATION_MESSAGE);
			}
			
			//adding code for first initialisation of window:
			if(itsChosen==1)
			{
				CZeroSplitFrame frame = new CZeroSplitFrame(1);
				frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				frame.setVisible(true);
				this.setVisible(false);
			}
			if(itsChosen==2)
			{
				CZeroSplitFrame frame = new CZeroSplitFrame(2);
				frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				frame.setVisible(true);
				this.setVisible(false);
			}
			
		}
		else if(source==itsExitBut)
		{
			System.exit(0);
		}
	}//close:actionPerformed()
	
	public void itemStateChanged(ItemEvent event)
	{
		if(event.getSource()==itsoldButton)
			itsChosen=1 ;
		if(event.getSource()==itsnewButton)
			itsChosen = 2;
		
	}
}
