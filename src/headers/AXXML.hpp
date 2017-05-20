#ifndef AXXML_hpp
#define AXXML_hpp
#include <string>
#include "AXLog.hpp"
#include "pugixml.hpp"
//type defs
typedef pugi::xml_document AXXMLdoc; // holds a collection of nodes
typedef pugi::xml_node AXXMLnode; // holds a single node 
typedef pugi::xml_attribute AXXMLattribute; // holds an attribute
typedef pugi::xml_node_iterator AXXMLnode_iterator; // used to loop over nodes
typedef pugi::xml_attribute_iterator AXXMLattribute_iterator; // used to loop over attributes

class AXXML{
	bool loaded;
	AXXMLdoc document;
public:
   /*!
   * The AXXML constructor
   *
   * loadFile must be used to load in a file
   */
	AXXML();
   /*!
   * The AXXML constructor
   * @param path the XML file to load in
   */
	AXXML(const std::string path);
   /*!
   * A method to load in a xml file
   * @param path the XML file to load in
   * @return if the file loaded in correctly or not
   * @see isLoaded()
   */
	bool loadFile(const std::string path);
   /*!
   * Returns if an XML file is currently loaded
   * @return if the XML data is loaded in
   */
	bool isLoaded();
   /*!
   * Get a child inside the document with a given name
   * @param the name of the child to get
   * @return an AXXMLnode, you can use this to get other sibilings
   */
	AXXMLnode child(const std::string child);
   /*!
   * Get an iterator to the start of the document
   * @return an AXXMLnode_iterator, you can use this to iterate over the document
   */
	AXXMLnode_iterator begin();
   /*!
   * Get an iterator to the end of the document
   * @return an AXXMLnode_iterator, you can use this to iterate over the document
   */
	AXXMLnode_iterator end();

};
#endif