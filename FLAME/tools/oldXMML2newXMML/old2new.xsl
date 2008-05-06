<?xml version="1.0" encoding="ISO-8859-1"?>
<!DOCTYPE xmodel SYSTEM "http://eurace.cs.bilgi.edu.tr/XMML.dtd">

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  
  <xsl:output method="xml"/>
  <xsl:template match="/xmachine_agent_model">
	
	<xmodel version="2">
	  <name><xsl:value-of select="name"/></name>
	  <version/>
	  <description/>
	  
	  <models>
		<xsl:for-each select="include">
		  <model>
			<file><xsl:value-of select="."/></file>
			<enabled>true</enabled>
		  </model>
		</xsl:for-each>		
	  </models>
	  
	  <environment>
		<constants/>
		<functionFiles>
		  <xsl:for-each select="environment/functions/file">
			<file><xsl:value-of select="."/></file>
		  </xsl:for-each>
		</functionFiles>
		<dataTypes>
		  <xsl:for-each select="environment/datatypes/datatype">
			<dataType>
			  <name><xsl:value-of select="name"/></name>
			  <description><xsl:value-of select="desc"/></description>
			  <variables>
				<xsl:for-each select="var">
				  <variable>
					<type><xsl:value-of select="type"/></type>
					<name><xsl:value-of select="name"/></name>
					<description/>
				  </variable>
				</xsl:for-each>		
			  </variables>
			</dataType>
		  </xsl:for-each>
		</dataTypes>
	  </environment>

	  <agents>
		<xsl:for-each select="xmachine">
		  <xagent>
			<name><xsl:value-of select="name"/></name>
			<description/>
			<memory>
			  <xsl:for-each select="memory/var">
				<variable>
				  <type><xsl:value-of select="type"/></type>
				  <name><xsl:value-of select="name"/></name>
				  <description/>
				</variable>
			  </xsl:for-each>		
			</memory>
			<roles/>
			<functions>
			  <xsl:for-each select="functions/function">
				<function>
				  <name><xsl:value-of select="name"/></name>
				  <description/>
				  <currentState><xsl:value-of select="current_state"/></currentState>
				  <nextState><xsl:value-of select="next_state"/></nextState>
				  <inputs>
					<xsl:for-each select="input">
					  <input>
						<messageName><xsl:value-of select="."/></messageName>
						<sort/>
					  </input>
					</xsl:for-each>
				  </inputs>
				  <outputs>
					<xsl:for-each select="output">
					  <output>
						<messageName><xsl:value-of select="."/></messageName>
					  </output>
					</xsl:for-each>
				  </outputs>
				</function>
			  </xsl:for-each>		
			</functions>
		  </xagent>
		</xsl:for-each>
	  </agents>

	  <contexts/>

	  <messages>
		<xsl:for-each select="messages/message">
		  <message>
			<name><xsl:value-of select="name"/></name>
			<description/>
			<variables>
			  <xsl:for-each select="var">
				<variable>
				  <type><xsl:value-of select="type"/></type>
				  <name><xsl:value-of select="name"/></name>
				  <description/>				  
				</variable>
			  </xsl:for-each>
			</variables>
		  </message>
		</xsl:for-each>		
	  </messages>

	</xmodel>
  </xsl:template>
  
</xsl:stylesheet>
