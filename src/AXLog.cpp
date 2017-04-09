#include "headers/AXLog.hpp"
#include "headers/AXWindow.hpp"
namespace AXLog{
	int logType = AX_LOG_OUT;
	std::string logFilename = "logfile.txt";
	void log(const std::string& name, const std::string& data, int logLevel){
		//get the time
     	std::time_t t = std::time(nullptr);
     	std::tm tm = *std::localtime(&t);
     	std::ostringstream ss;
     	//get the time and add to the string
     	ss << std::put_time(&tm, "%d/%m/%Y - %H:%M:%S");
		std::string output(ss.str());
     	//set the log level
		switch(logLevel){
			case AX_LOG_ERROR:
		     	output.append(" | Error | ");
			break;
			case AX_LOG_WARNING:
		     	output.append(" | Warning | ");
			break;
			default:
		     	output.append(" | Debug | ");
			break;
		}
		output.append(name);
		output.append(" | ");
     	output.append(data); 
		//if logging out or both, print to cerr
		if(logType == AX_LOG_OUT || logType == AX_LOG_BOTH){
			std::cerr << output << std::endl; 
		}
		//if logging to file or both, write to file
		if(logType == AX_LOG_FILE || logType == AX_LOG_BOTH){
			std::ofstream file;
			std::ostringstream stream;
			stream << AXWindow::startTime;
			stream << " - ";
			stream << logFilename;
			file.open(stream.str(), std::ios::app);
			if(file.is_open()){
				file << output << std::endl;
				file.close();
			}else{
				log("Failed to open log file", "Does the file already exist?", AX_LOG_ERROR);
			}
		}
	}
};