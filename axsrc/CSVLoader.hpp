//
//  CSVLoader.hpp
//  Project2
//
//  Created by William Meaton on 04/02/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

/*
 create object
 call loadfile()
 it returns a vector of vector<int>
 */

#ifndef CSVLoader_hpp
#define CSVLoader_hpp

#include <stdio.h>
#include <vector>

class CSVLoader{
    std::string name;
    char seperator = ',', ignore = '/';
    //where the last load will be saved
    std::vector<vector<int> > fileVector;
public:
    //create the object
    CSVLoader(const std::string &name, const char &seperator, const char &ignore){
        this->name = name;
        this->seperator = seperator;
        this->ignore = ignore;
    }
    CSVLoader(const std::string &name){
        this->name = name;
    }

    //load the CSV and return a 2D vector of ints
    std::vector<vector<int> >& loadfile(){
        std::ifstream file(name, std::ios::in); //declare a file stream
        if (worldFile.is_open()) //checks if the file is open??
        {
            std::string str;
            while (getline(file, str)){
                //if it's the ignore blank the line
                if(str[0] == ignore){
                    continue;
                }
                //loop through and push all the tiles into a vector
                std::vector<int> readLine; // this will hold the data
                std::string read;
                for(int i = 0; i <= str.length(); i++){
                    //find seperators and split the integers
                    //this allows for >1 digit ints
                    // i >= str.length finds the end of the line
                    if(str[i] == seperator || i >= str.length()){
                        int tempInt = atoi(read.c_str());
                        read.clear();
                        readLine.push_back(tempInt);
                    }else{
                        read += str[i];
                    }
                }
                //now push the integers in
                fileVector.push_back(readLine);
            }
        }else{
            std::cout << "File failed to load" << std::endl;
        }
        return fileVector;
    }
    
    //returns the fileVector
    std::vector<vector<int> >& getFileVector(){
        return fileVector;
    }

};

#endif /* CSVLoader_hpp */
