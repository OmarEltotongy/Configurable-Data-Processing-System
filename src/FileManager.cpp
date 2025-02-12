#include "../include/FileManager.hpp"

// Constructor
FileManager::FileManager(const std::string& file) : fileName(file) {}

// Destructor to ensure files are closed
FileManager::~FileManager() {
    if (inputFile.is_open()) inputFile.close();
    if (outputFile.is_open()) outputFile.close();
}

// Write data to the file
void FileManager::writeToFile(const std::string& data) {
    outputFile.open(fileName, std::ios::app); // Open in append mode
    if (!outputFile) {
        throw std::ios_base::failure("Failed to open file for writing");
    }
    outputFile << data << std::endl;
    outputFile.close();
}

// Read data from the file
std::string FileManager::readFromFile() {
    inputFile.open(fileName);
    if (!inputFile) {
        throw std::ios_base::failure("Failed to open file for reading");
    }

    std::string content, line;
    while (std::getline(inputFile, line)) {
        content += line + "\n";
    }
    inputFile.close();
    return content;
}

// Overload the << operator to write to the file
FileManager& FileManager::operator<<(const std::string& data) {
    writeToFile(data);
    return *this;
}

// Overload the >> operator to read from the file
FileManager& FileManager::operator>>(std::string& data) {
    data = readFromFile();
    return *this;
}
