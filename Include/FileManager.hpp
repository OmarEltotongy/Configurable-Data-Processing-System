#ifndef __FILEMANAGER_HPP__
#define __FILEMANAGER_HPP__


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class FileManager 
{
    private:
        std::string fileName;
        std::ifstream inputFile;
        std::ofstream outputFile;
    
    public:
        // Constructor
        FileManager(const std::string& file);
    
        // Destructor to ensure files are closed
        ~FileManager();
    
        // Write data to the file
        void writeToFile(const std::string& data);
    
        // Read data from the file
        std::string readFromFile();
    
        // Overload the << operator to write to the file
        FileManager& operator<<(const std::string& data);
    
        // Overload the >> operator to read from the file
        FileManager& operator>>(std::string& data);
    };

#endif // __FILEMANAGER_HPP__