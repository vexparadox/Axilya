/**
 * @file
 * @author William Meaton <will.meaton@gmail.com>
 *
 * @section LICENSE
 *
 * The MIT License
 * 
 * Copyright (c) 2017 WillMeaton http://willmeaton.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @section DESCRIPTION
 *
 * A small CSV loader that will return the values in a std::vector format.
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
