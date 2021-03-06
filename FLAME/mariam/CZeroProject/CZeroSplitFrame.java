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

public class CZeroSplitFrame extends JFrame implements ListSelectionListener, ActionListener{
	private Container itsContainer;
	private Element itsRootElement = null;
	private Element itsModelRootElement = null;
	private Map itsAgentMap = null;
	private Map itsDatatypeMap = null;
	int agentCounter, datatypeCounter;
	List xmachine_model;
	List xmachines;
	List xmachineVars;
	List datatypeVars;
	List datatypes;
	List env_elements;
	List model_elements;
	List modelnames;
	Iterator model_iterator,modelnames_iterator;
	Iterator env_iterator,varIterator, datatype_iterator,iterator_parent, xmachine_iterator;
	Iterator datatypeVar_iterator;
	int itsAgentListSize=0;	
	String memVarType, memVarName;
	AgentData agentObject;
	DataStructureObject datatypeObject;
	private JPanel itsDeckDataPanel;
	private CardLayout itsCardManager;
	private JTextArea itsTextArea;
	private JList itsAgentsList; 
	private AgentData[] itsAgents;
	private JButton itsAddRowButton;
	private JButton itsMakeButton;
	private JButton itsExitButton;
	private JPanel itsButtonPanel;
	private DataPanel[] itsDataPanel;
	private String itsRowAdding;
	private int total_agents[];
	Element xagentElement[];
	Element xagentNameElement[];
	Element xagentIDVarElement[];                      
	String nameofFile=null;
	int version;
	
	public CZeroSplitFrame(int ver)
	{
		setTitle("CZero Application");
		int i;
		version =ver;
		addWindowListener(new WindowAdapter()
		{
			public void windowClosing (WindowEvent e)
			{
				System.exit(0);
			}
		});
		
		itsContainer=this.getContentPane();
	
	//getting input file name for model.xml
		openFile();
	
		if ((nameofFile.equals(""))|| (nameofFile==null))
	{
		JOptionPane.showMessageDialog(this,"File Not Found","File Not Found",JOptionPane.ERROR_MESSAGE);
		return;
	}
	
	getXmlRootElement(nameofFile);
	itsAgentMap = new HashMap();
	itsDatatypeMap=new HashMap();
	if(version==1)
	{	gatherXMLDataVer1();
	}
	if(version==2)
	{
		gatherXMLDataVer2();
	}
	// set up cardlayout
	
	itsAgentListSize=itsAgentMap.size();
	itsDeckDataPanel=new JPanel();
	itsCardManager=new CardLayout();
	itsDeckDataPanel.setLayout(itsCardManager);
	// putting into array for list
	itsAgents=new AgentData[itsAgentListSize];
	itsDataPanel=new DataPanel[itsAgentListSize];
	for (i=0;i<itsAgentListSize;i++)
	{
		itsAgents[i]=new AgentData();
		itsAgents[i]=(AgentData)itsAgentMap.get(i); //copies agentdata from map into agentdata array
		//System.out.println("new "+ itsAgents[i].getItsAgentName());
		itsDataPanel[i]=new DataPanel(itsAgents[i],itsDatatypeMap,this);
		itsDataPanel[i].setFont(new Font("Serif", Font.BOLD, 14));
		itsDeckDataPanel.add(itsDataPanel[i],itsAgents[i].getItsAgentName());
	}
	
	itsAgentsList=new JList(itsAgents);
	itsAgentsList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
	//itsAgentsList.setSelectedIndex(0);
	itsAgentsList.addListSelectionListener(this);
	itsTextArea=new JTextArea(2,5);
	itsTextArea.setEditable(false);
	
	itsButtonPanel=new JPanel();
	
	itsAddRowButton=new JButton("Add Values");
	itsAddRowButton.addActionListener(this);
	itsMakeButton=new JButton("Make Zero");
	itsMakeButton.addActionListener(this);
	itsExitButton=new JButton("Exit");
	itsExitButton.addActionListener(this);
	//itsButtonPanel.add(new JScrollPane(itsTextArea),BorderLayout.NORTH);
	itsButtonPanel.add(itsAddRowButton);
	itsButtonPanel.add(itsMakeButton);
	itsButtonPanel.add(itsExitButton);
	
	
	JSplitPane upperPane=new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,itsAgentsList,itsDeckDataPanel);	
	upperPane.setContinuousLayout(true);
	upperPane.setOneTouchExpandable(true);
	
	JSplitPane lowerPane=new JSplitPane(JSplitPane.VERTICAL_SPLIT,upperPane,itsButtonPanel);
	lowerPane.setContinuousLayout(true);
	lowerPane.setOneTouchExpandable(true);
	
	itsContainer.add(lowerPane,"Center");
	// set the size and the position of the frame
	Toolkit toolKit = Toolkit.getDefaultToolkit();
	Dimension dimension = toolKit.getScreenSize();
	setSize(550, 550);
	pack();
	setVisible(true);
	setLocation(new Point(40,40));
	
	}//end of constructor
	
	public void actionPerformed(ActionEvent evt)
	{
		Object source=evt.getSource();
		int i=0;
		int j=0;
		int rowCount;
		String pop;
		if(source==itsMakeButton)
		{
			//write the 0 file
			try{
				for (i=0;i<itsAgentListSize;i++)
				{
					//fill the agent object
					itsDataPanel[i].writeAgentData();
					//get the updated agent object
					itsAgents[i]=itsDataPanel[i].getUpdateAgentData();
					
					//then loop through agent objects to write data Create file 
				}
				createNewDomXml();
				
			}//close:try
			catch (Exception e)
			{//Catch exception if any
			      System.err.println("Error: " + e.getMessage());
			}//close//catch
		}
		else if(source== itsAddRowButton)
		{
			//get component
			String text;
			String nullString=new String();
			//adding code for first initialisation of window:
			if(itsRowAdding == null)
			{
				JOptionPane.showMessageDialog(null, "Choose agent from the list!");
			}
			
			for (i=0;i<itsAgentListSize;i++)
			{
			//	System.out.println("Value of itsRowAdding: " + itsRowAdding);
				if(itsAgents[i].getItsAgentName().equals(itsRowAdding))
				{
					itsDataPanel[i].addRow();
				}
			}
		}
		else if(source==itsExitButton)
		{
			System.exit(0);
		}
	}//close:actionPerformed()
	
	public void itemStateChanged(ItemEvent evt)
	{
		int counter;
		for (counter=0;counter<itsAgentListSize;counter++)
		{	}	
	}//close:itemStateChanged()
	
	
	public void valueChanged(ListSelectionEvent event)
	{
		JList source= (JList)event.getSource();
		AgentData value=(AgentData)source.getSelectedValue();
		//itsDataPanel.reAgentvar(value);
		itsCardManager.show(itsDeckDataPanel,value.getItsAgentName());
		itsRowAdding=value.getItsAgentName();
		
	}//close:valueChanged()
	
	
	
	/**
	 * get the root element of the given xml file
	 * @param aFileName
	 */
	public void getXmlRootElement(String aFileName) {
		FileInputStream fileInput = null;
		//System.out.println(aFileName);
		//System.out.println("startreadfile");
		try {
			fileInput = new FileInputStream(aFileName);
			SAXBuilder saxBuilder = new SAXBuilder();
			Document document = saxBuilder.build(fileInput);
			itsRootElement = document.getRootElement();
			System.out.println("Version " +itsRootElement.getName());
			//System.out.println("read file");
	    } catch (Exception anExceptionFirst) {
	    	anExceptionFirst.printStackTrace();
	    	//System.out.println("problem1");
	    } finally {
	        try {
				fileInput.close();
				//System.out.println("closefile");
	        } catch (IOException anExceptionSecond) {
	        	anExceptionSecond.printStackTrace();
	        	//System.out.println("problem2");
	        }
	    }
	}//close:getXmlRootElement()
	
	public void getXmlModelRootElement(String aFileName) {
		FileInputStream fileInput = null;
		//System.out.println(aFileName);
		//System.out.println("startreadfile");
		try {
			fileInput = new FileInputStream(aFileName);
			SAXBuilder saxBuilder = new SAXBuilder();
			Document document = saxBuilder.build(fileInput);
			itsModelRootElement = document.getRootElement();
			System.out.println("Version " +itsModelRootElement.getName());
			//System.out.println("read file");
	    } catch (Exception anExceptionFirst) {
	    	anExceptionFirst.printStackTrace();
	    	//System.out.println("problem1");
	    } finally {
	        try {
				fileInput.close();
				//System.out.println("closefile");
	        } catch (IOException anExceptionSecond) {
	        	anExceptionSecond.printStackTrace();
	        	//System.out.println("problem2");
	        }
	    }
	}//close:getXmlRootElement()
	
	
	
	public void gatherXMLDataVer1()
	{
		//datatypes
	env_elements=itsRootElement.getChildren("environment"); //list of datatypes
	env_iterator=env_elements.iterator();

		//agents
	xmachines=itsRootElement.getChildren("xmachine"); //list of xmachines
	xmachine_iterator=xmachines.iterator();
	
	Element xmachine = null;
	Element xmachineVar=null;
	Element datatype=null;
	Element environment=null;
	Element datatypeVar=null;
	
	agentObject = null;
	datatypeObject=null;
	agentCounter=0;
	datatypeCounter=0;
	
	while(env_iterator.hasNext())
	{
		environment=(Element)env_iterator.next();
		
		datatypes=environment.getChildren("datatype");
		
		datatype_iterator=datatypes.iterator();
		while(datatype_iterator.hasNext())
		{
			datatype=(Element)datatype_iterator.next();
			String datatypeName=datatype.getChild("name").getText();
			datatypeObject=new DataStructureObject();
			datatypeObject.setItsName(datatypeName);
		
			//	get vars
			datatypeVars=datatype.getChildren("var");
			datatypeVar_iterator=datatypeVars.iterator();
			while(datatypeVar_iterator.hasNext())
			{
				datatypeVar=(Element)datatypeVar_iterator.next();
				memVarType= datatypeVar.getChild("type").getText();
				memVarName= datatypeVar.getChild("name").getText();
				datatypeObject.additsVars(memVarType, memVarName);
				
			}
						
			itsDatatypeMap.put(datatypeCounter,datatypeObject);
		
			datatypeCounter++;
			
		}
	}// structures

	//gather xml data for xmachines
	while(xmachine_iterator.hasNext())
	{
			xmachine=(Element)xmachine_iterator.next();
			String xAgentName=xmachine.getChild("name").getText();
			agentObject=new AgentData();
			agentObject.setItsAgentName(xAgentName);
			xmachineVars=xmachine.getChild("memory").getChildren();
			varIterator=xmachineVars.iterator();
			while(varIterator.hasNext())
			{		
				xmachineVar=(Element)varIterator.next();
				memVarType= xmachineVar.getChild("type").getText();
				memVarName= xmachineVar.getChild("name").getText();
				agentObject.getItsAgentTypeData(0).addVars(memVarType, memVarName);
			}
			itsAgentMap.put(agentCounter, agentObject);
			agentCounter++;
		}//xmachines
	}//close:gatherXMLDataVer1()
	
	
	public void gatherXMLDataVer2()
	{
		//models
		model_elements=itsRootElement.getChildren("models"); //list of models
		model_iterator=model_elements.iterator();
		
		//datatypes
	/*env_elements=itsRootElement.getChildren("environment"); //list of datatypes
	env_iterator=env_elements.iterator();

		//agents
	xmachines=itsRootElement.getChildren("xmachine"); //list of xmachines
	xmachine_iterator=xmachines.iterator();
	*/
	Element model=null;
	Element modelVar=null;
	Element modelfilename=null;
/*	
	Element xmachine = null;
	Element xmachineVar=null;
	Element datatype=null;
	Element environment=null;
	Element datatypeVar=null;
	
	agentObject = null;
	datatypeObject=null;
	agentCounter=0;
	datatypeCounter=0;
	*/
	while(model_iterator.hasNext())
	{
		model=(Element)model_iterator.next();
		modelnames=model.getChildren("model");
		modelnames_iterator=modelnames.iterator();
		System.out.println("Line 123");
		while(modelnames_iterator.hasNext())
		{
			System.out.println("Line 122");
			modelfilename=(Element)modelnames_iterator.next();
			if(("true".equals(modelfilename.getChild("enabled").getText()))||("True".equals(modelfilename.getChild("enabled").getText())))
			{
				String modelName=modelfilename.getChild("file").getText();
				System.out.println("model name" + modelName);
				getXmlModelRootElement(modelName);
				gatherInternalXmlData();
			}
			
		}
	}
	/*
	while(env_iterator.hasNext())
	{
		environment=(Element)env_iterator.next();
		
		datatypes=environment.getChildren("datatype");
		
		datatype_iterator=datatypes.iterator();
		while(datatype_iterator.hasNext())
		{
			datatype=(Element)datatype_iterator.next();
			String datatypeName=datatype.getChild("name").getText();
			datatypeObject=new DataStructureObject();
			datatypeObject.setItsName(datatypeName);
		
			//	get vars
			datatypeVars=datatype.getChildren("var");
			datatypeVar_iterator=datatypeVars.iterator();
			while(datatypeVar_iterator.hasNext())
			{
				datatypeVar=(Element)datatypeVar_iterator.next();
				memVarType= datatypeVar.getChild("type").getText();
				memVarName= datatypeVar.getChild("name").getText();
				datatypeObject.additsVars(memVarType, memVarName);
				
			}
						
			itsDatatypeMap.put(datatypeCounter,datatypeObject);
		
			datatypeCounter++;
			
		}
	}// structures

	//gather xml data for xmachines
	while(xmachine_iterator.hasNext())
	{
			xmachine=(Element)xmachine_iterator.next();
			String xAgentName=xmachine.getChild("name").getText();
			agentObject=new AgentData();
			agentObject.setItsAgentName(xAgentName);
			xmachineVars=xmachine.getChild("memory").getChildren();
			varIterator=xmachineVars.iterator();
			while(varIterator.hasNext())
			{		
				xmachineVar=(Element)varIterator.next();
				memVarType= xmachineVar.getChild("type").getText();
				memVarName= xmachineVar.getChild("name").getText();
				agentObject.getItsAgentTypeData(0).addVars(memVarType, memVarName);
			}
			itsAgentMap.put(agentCounter, agentObject);
			agentCounter++;
		}//xmachines
		*/
	}//close:gatherXMLDataver2()
	
	

	public void gatherInternalXmlData()
	{
		//models
		//model_elements=itsRootElement.getChildren("models"); //list of models
		//model_iterator=model_elements.iterator();
		
		//datatypes
	env_elements=itsModelRootElement.getChildren("environment"); //list of datatypes
	env_iterator=env_elements.iterator();

		//agents
	xagents=itsModelRootElement.getChildren("xagent"); //list of xmachines
	xagent_iterator=xmachines.iterator();
	
	Element model=null;
	Element modelVar=null;
	Element modelfilename=null;
/*	
	Element xmachine = null;
	Element xmachineVar=null;
	Element datatype=null;
	Element environment=null;
	Element datatypeVar=null;
	
	agentObject = null;
	datatypeObject=null;
	agentCounter=0;
	datatypeCounter=0;
	*/
	while(model_iterator.hasNext())
	{
		model=(Element)model_iterator.next();
		modelnames=model.getChildren("model");
		modelnames_iterator=modelnames.iterator();
		System.out.println("Line 123");
		while(modelnames_iterator.hasNext())
		{
			System.out.println("Line 122");
			modelfilename=(Element)modelnames_iterator.next();
			if(("true".equals(modelfilename.getChild("enabled").getText()))||("True".equals(modelfilename.getChild("enabled").getText())))
			{
				String modelName=modelfilename.getChild("file").getText();
				System.out.println("model name" + modelName);
				getXmlModelRootElement(modelName);
				gatherInternalXmlData();
			}
			
		}
	}
	/*
	while(env_iterator.hasNext())
	{
		environment=(Element)env_iterator.next();
		
		datatypes=environment.getChildren("datatype");
		
		datatype_iterator=datatypes.iterator();
		while(datatype_iterator.hasNext())
		{
			datatype=(Element)datatype_iterator.next();
			String datatypeName=datatype.getChild("name").getText();
			datatypeObject=new DataStructureObject();
			datatypeObject.setItsName(datatypeName);
		
			//	get vars
			datatypeVars=datatype.getChildren("var");
			datatypeVar_iterator=datatypeVars.iterator();
			while(datatypeVar_iterator.hasNext())
			{
				datatypeVar=(Element)datatypeVar_iterator.next();
				memVarType= datatypeVar.getChild("type").getText();
				memVarName= datatypeVar.getChild("name").getText();
				datatypeObject.additsVars(memVarType, memVarName);
				
			}
						
			itsDatatypeMap.put(datatypeCounter,datatypeObject);
		
			datatypeCounter++;
			
		}
	}// structures

	//gather xml data for xmachines
	while(xmachine_iterator.hasNext())
	{
			xmachine=(Element)xmachine_iterator.next();
			String xAgentName=xmachine.getChild("name").getText();
			agentObject=new AgentData();
			agentObject.setItsAgentName(xAgentName);
			xmachineVars=xmachine.getChild("memory").getChildren();
			varIterator=xmachineVars.iterator();
			while(varIterator.hasNext())
			{		
				xmachineVar=(Element)varIterator.next();
				memVarType= xmachineVar.getChild("type").getText();
				memVarName= xmachineVar.getChild("name").getText();
				agentObject.getItsAgentTypeData(0).addVars(memVarType, memVarName);
			}
			itsAgentMap.put(agentCounter, agentObject);
			agentCounter++;
		}//xmachines
		*/
	}//close:gatherXMLDataver2()
	
	

	
	
	public void createNewDomXml()
	{
		System.out.println("h");
		int i,j,a,b,c,agentsinOneType,k;
		int temp_type=0;
		int var_temp=0;
		Integer idvalue;
		int sum_total_agents=0;
		String elementName;
		total_agents=new int[itsAgentListSize];
		// create the xml and document		
		Element itsRootNewElement=new Element("states");//rootelement
		Document itsNewDocument=new Document(itsRootNewElement);
		
		Element itnoElement=new Element("itno");
		itnoElement.addContent("0");
		itsRootNewElement.addContent(itnoElement);
		//loop through agents
		for(i=0;i<itsAgentListSize;i++)
		{ //find total number of xagents
			temp_type =itsAgents[i].getTypeCounter()-1;
			total_agents[i]=0;
			for(j=0;j<temp_type;j++)
			{
				total_agents[i]+=itsAgents[i].getItsAgentTypeData(j).getAgentTypeNumber();
			}
			sum_total_agents+=total_agents[i];			
		}
	
		xagentElement=new Element[sum_total_agents];
		xagentNameElement=new Element[sum_total_agents];
		xagentIDVarElement=new Element[sum_total_agents];
		
		for(a=0;a<sum_total_agents;a++)
		{
			xagentElement[a]=new Element("xagent");
			xagentNameElement[a]=new Element("name");
		}
		a=0;
		for(i=0;i<itsAgentListSize;i++)
		{
			idvalue=0;
			System.out.println("line322");
			//get variables
			temp_type=itsAgents[i].getTypeCounter()-1;
			for(b=0;b<temp_type;b++)
			{
				agentsinOneType=itsAgents[i].getItsAgentTypeData(b).getAgentTypeNumber();
				for(k=0;k<agentsinOneType;k++)
				{
					xagentNameElement[a].addContent(itsAgents[i].getItsAgentName());
				
					idvalue++;
				
					
					xagentElement[a].addContent(xagentNameElement[a]);
				
					var_temp=itsAgents[i].getItsAgentTypeData(b).getVarCounter();
					for(c=0;c<var_temp;c++)
					{
						//check for arrays
						elementName=checking_arrays(itsAgents[i].getItsAgentTypeData(b).getIndVariable(c).getItsAgentVarName());
						Element xagentVarNameElement=new Element(elementName);
						//System.out.println("element NAme is: " +elementName);
						if(checking_IDs(elementName)==true)
						{
							xagentVarNameElement.addContent(idvalue.toString());
						}
						//add check for everyrandomvalue
						else
						{
							if(checkRandomEveryAgent(itsAgents[i].getItsAgentTypeData(b).getIndVariable(c).getItsAgentVarValue())==true) 
							{
								String randomValue;
								System.out.println("Value before assignment =" +itsAgents[i].getItsAgentTypeData(b).getIndVariable(c).getItsAgentVarValue());
								randomValue=calRandomNumber(itsAgents[i].getItsAgentTypeData(b).getIndVariable(c).getItsAgentVarValue());
								System.out.println("Value after assignment =" +itsAgents[i].getItsAgentTypeData(b).getIndVariable(c).getItsAgentVarValue());
								xagentVarNameElement.addContent(randomValue);
								
							}
							else
							{
								xagentVarNameElement.addContent(itsAgents[i].getItsAgentTypeData(b).getIndVariable(c).getItsAgentVarValue());
							}
						}
						xagentElement[a].addContent(xagentVarNameElement);
					}
				a++;	
				}
			}
				//adding values into xagent
			
		}//for diff agents
		
	
		for(i=0;i<sum_total_agents;i++)
		{
			itsRootNewElement.addContent(xagentElement[i]);
		}
		// create the xml tree
		//create root element and add to doc
		//create comment and out in root element- NOT NEEDED
		//create child elements and add to root
		//create add valuye to child
		//output to xml 
		//set up transformer
		//create string from xml tree
		//print xml
		try{
			
			Format itsFormat=Format.getPrettyFormat();
			itsFormat.setOmitDeclaration(true);
			
			//itsFormat.setLineSeparator("     ");
			XMLOutputter itsXmlOutputter=new XMLOutputter(itsFormat);
			//Format itsFormat= itsXmlOutputter.getFormat();
			
			//itsXmlOutputter.setFormat(itsFormat)//;
			//itsXmlOutputter.setNewlines(true);
			//itsXmlOutputter.output(itsNewDocument,System.out);
			itsXmlOutputter.output(itsNewDocument, new FileOutputStream(new File("0.xml")));
		}//close:try
		catch(java.io.IOException e)
		{
			e.printStackTrace();
		}//close:catch
		
	} //close:createNewDomXml()
	
	public String checking_arrays(String temparray)
	{
		int bracket= temparray.indexOf("[");
		if(bracket>-1)
		{
			String arrayName =temparray.substring(0,bracket);
			//System.out.println(arrayName);
			return arrayName;
		}//close:if
		return temparray;
	}//close:checking_arrays()
	
	public boolean checking_IDs(String temparray)
	{
		return temparray.equals("id");
	}//close:checking_IDs()
	
	public boolean checkRandomEveryAgent(String tempValue)
	{
		//return true if random is required
		String temp_randomIntEvery="EveryRandInt";
		String temp_randomDoubleEvery="EveryRandDouble";
		
		
		if(tempValue.indexOf(temp_randomIntEvery)>-1)
		{
			return true;
		}
		else if(tempValue.indexOf(temp_randomDoubleEvery)>-1)
		{
			return true;
		}
		else
			return false;
	}//close:checkRandomnumberevery
	
	//calculate new number
	public String calRandomNumber(String tempValue)
	{
		String temp_randomIntEvery="EveryRandInt";
		String temp_randomDoubleEvery="EveryRandDouble";
		
		int limitOne, limitTwo;
		String temp_first;
		int numberOne, numberTwo;
		Integer newvalue;
		String returnString;
		Long newOne;
		Double newTwo;
		
		if(tempValue.indexOf(temp_randomIntEvery)>-1)//if true
		{
			//first number
			limitOne=tempValue.lastIndexOf("(")+1;
			limitTwo=tempValue.lastIndexOf(",");
			temp_first=tempValue.substring(limitOne, limitTwo);
			System.out.println(limitOne + " " +  temp_first);
			numberOne=Integer.parseInt(temp_first);
			System.out.println("number="+temp_first);
			//second number
			limitOne=tempValue.lastIndexOf(",")+1;
			limitTwo=tempValue.lastIndexOf(")");
			temp_first=tempValue.substring(limitOne, limitTwo);
			System.out.println(limitOne + " " +  temp_first);
			numberTwo=Integer.parseInt(temp_first);
			System.out.println("number="+temp_first);
			
			if(numberTwo>=numberOne)
			{
				newOne=Math.round(numberOne + (Math.random()* (numberTwo-numberOne)));
				System.out.println("newOne = " + newOne);
				newvalue=newOne.intValue();
				returnString=newvalue.toString();
				System.out.println("returnString " + returnString);
				return returnString;
			}
			else
			{
				JOptionPane.showMessageDialog(null,"The second number should be bigger than the first!");
			}
		}//close int
		
		//double
		if(tempValue.indexOf(temp_randomDoubleEvery)>-1)//if true
		{
			//first number
			limitOne=tempValue.lastIndexOf("(")+1;
			limitTwo=tempValue.lastIndexOf(",");
			temp_first=tempValue.substring(limitOne, limitTwo);
			numberOne=Integer.parseInt(temp_first);
			System.out.println("number="+temp_first);
			//second number
			limitOne=tempValue.lastIndexOf(",")+1;
			limitTwo=tempValue.lastIndexOf(")");
			temp_first=tempValue.substring(limitOne, limitTwo);
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
				System.out.println("retrunString Double " + returnString);
				return returnString;
			}
			else
			{
				JOptionPane.showMessageDialog(null,"The second number should be bigger than the first!");
			}
		}//close double
		return null;
	}
	
	public void openFile()
	{
		JFileChooser fc=new JFileChooser();
		fc.setFileSelectionMode(JFileChooser.FILES_ONLY);
		
		int result= fc.showOpenDialog(this);
		//if cancelled
		if(result==JFileChooser.CANCEL_OPTION) 
		return; 
		
		File fn = fc.getSelectedFile();
		
		//if filename wrong
		if(fn==null|| fn.getName().equals(""))
			JOptionPane.showMessageDialog(this,"Invalid file name", "Invalid File Name", JOptionPane.ERROR_MESSAGE);
		else
		{
			//openfile
			nameofFile=fn.getAbsolutePath();
			
			System.out.println("File found " + nameofFile);
			
			
		}//end else
	}
	
}//close:CZeroSplitFrame
