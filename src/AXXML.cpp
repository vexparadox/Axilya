#include "headers/AXXML.hpp"
AXXML::AXXML(){
	loaded = false;
}


AXXML::AXXML(const std::string path){
	loaded = loadFile(path);
}


bool AXXML::loadFile(const std::string path){
	pugi::xml_parse_result result = document.load_file(path.c_str());
	if(result){
		return true;
	}else{
		AXLog::log("AXXML failed to load", result.description(), AX_LOG_ERROR);
		return false;
	}
	return false;
}

bool AXXML::isLoaded(){
	return loaded;
}

AXXMLnode AXXML::child(const std::string child){
	if(loaded){
		return document.child(child.c_str());
	}else{
		AXLog::log("AXXML Child", "No file has been loaded.", AX_LOG_ERROR);
		AXXMLnode temp;
		return temp;
	}
}

AXXMLnode_iterator AXXML::begin(){
	if(loaded){
		return document.end();
	}else{
		AXLog::log("AXXML Child", "No file has been loaded.", AX_LOG_ERROR);
		AXXMLnode_iterator temp;
		return temp;
	}
}
AXXMLnode_iterator AXXML::end(){
	if(loaded){
		return document.begin();
	}else{
		AXLog::log("AXXML Child", "No file has been loaded.", AX_LOG_ERROR);
		AXXMLnode_iterator temp;
		return temp;
	}
}
