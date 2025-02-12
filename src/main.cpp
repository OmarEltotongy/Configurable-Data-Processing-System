#include <iostream>
#include <memory>
#include <map>
#include "../include/FileManager.hpp"
#include "../include/Processor.hpp"
#include "../include/ProcessorFactory.hpp"


int main() {
    try {
        FileManager fileManager("../config/settings.txt");

        // Read from the file using >> operator or .readFrommFile() 
        std::string fileContent;
        fileManager >> fileContent;
        std::cout << "File Content:\n" << fileContent << std::endl;
        
        // Store settings in a map
        std::map<std::string, std::string> configMap;

        //convert to string stream
        std::istringstream iss(fileContent);
        std::string line;
        
        // Parse the settings to a map
        while (std::getline(iss, line)) {
            size_t pos = line.find('=');
            if (pos != std::string::npos) {
                std::string key = line.substr(0, pos);
                std::string value = line.substr(pos + 1);
                configMap[key] = value;
            }
        }

        //print configuration settings
        std::cout << "Configuration Settings:\n";
        for (const auto& pair : configMap) {
            std::cout << pair.first << " = " << pair.second << std::endl;
        }

        // Extract processor type with (Processor.Options.Type) key
        auto Processor_Options_Type = configMap.find("Processor.Options.Type");
        auto Processor_Options_MaxRetries = configMap.find("Processor.Options.MaxRetries");
        auto Processor_Options_Threshold = configMap.find("Processor.Options.Threshold");

        // check if processor type not found
        if (Processor_Options_Type == configMap.end()) {
            throw std::runtime_error("Processor type not found in configuration file.");
        }
        else if (Processor_Options_MaxRetries == configMap.end()) {
            throw std::runtime_error("Processor max retries not found in configuration file.");
        }
        else if (Processor_Options_Threshold == configMap.end()) {
            throw std::runtime_error("Processor threshold not found in configuration file.");
        }

        //create processor type with (Processor.Options.Type) value
        std::string processorTypeStr = Processor_Options_Type->second;

        // Convert the processor type string to the enum
        EnumProcessorType processorType = getProcessorTypeFromString(processorTypeStr);

        // Use the factory to create the appropriate processor with right configuration
        ProcessorFactory factory;

        //next line will give threshold in int and thats not i need
        //float threshold = std::stoi(Processor_Options_Threshold->second);
        //i will use std::stof insted to convert string into float

        float threshold = std::stof(Processor_Options_Threshold->second);
        int maxRetries = std::stoi(Processor_Options_MaxRetries->second);
        std::unique_ptr<Processor> processor = factory.createProcessor(processorType, threshold, maxRetries);

        // Output the processor options
        std::cout << "Processor Type: " << processor->getType() << std::endl;
        std::cout << "Processor MaxRetries: " << processor->getMaxRetries() << std::endl;
        std::cout << "Processor Threshold: " << processor->getThreshold() << std::endl;

        /* We could use one function insted to print all the information of the processor */
        /* in this code, i used each separate to check every one of them */

        // Cleaning up the dynamically allocated object with delete or new
        // I used smart pointers to avoid these operations

    } catch (const std::ios_base::failure& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    

    return 0;
}