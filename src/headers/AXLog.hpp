#ifndef AXLOG_hpp
#define AXLOG_hpp
#define AX_LOG_DEBUG 0
#define AX_LOG_WARNING 1
#define AX_LOG_ERROR 2
#define AX_LOG_NONE -1
#define AX_LOG_FILE 0
#define AX_LOG_OUT 1
#define AX_LOG_BOTH 2
#include <iostream>
#include <sstream>
#include <ctime>
#include <fstream>
#include <iomanip>
namespace AXLog{
    /*!    
    * Defines where to save the logged data, AX_LOG_FILE for a file defined by @p logFilename, AX_LOG_OUT to print to cerr or AX_LOG_BOTH for both.
    */
	extern int logType;
    /*!    
    * Defines the minimum log level to handle, defaults to AX_LOG_DEBUG
    */
    extern int minLogLevel;
	/*!
	* The name of the log file to use.
	*/
	extern std::string logFilename;
    /*!    
    * Log data
    *
    * Where the data is stored is based on the logType variable
    * @param name the name of the log, you can give specific details here
    * @param data the data that's being logged, usually the raw error data  
    * @param logLevel the level at which to log AX_LOG_DEBUG, AX_LOG_WARNING or AX_LOG_ERROR
    */
	void log(const std::string& name, const std::string& data, int logLevel);
    /*!    
    * Log data at a debug level
    *
    * Where the data is stored is based on the logType variable
    *
    * The name variable is assumed
    * @param data the data that's being logged, usually the raw error data  
    */
    void debug(const std::string& data);
    /*!    
    * Log data at a warning level
    *
    * Where the data is stored is based on the logType variable
    *
    * The name variable is assumed
    * @param data the data that's being logged, usually the raw error data  
    */
    void warning(const std::string& data);
    /*!    
    * Log data at a error level
    *
    * Where the data is stored is based on the logType variable
    *
    * The name variable is assumed
    * @param data the data that's being logged, usually the raw error data  
    */
    void error(const std::string& data);
};
#endif