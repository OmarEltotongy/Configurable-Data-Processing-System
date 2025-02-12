# Configurable Data Processing System

This project implements a configurable data processing system in C++ that reads configuration files and dynamically selects the appropriate processor to handle different types of data. The system supports multiple data types, including text, numeric, image, audio, and video processing.

---

## Project Overview

The main objective of this project is to build a flexible and extensible system that:

- Reads a configuration file to determine the settings.
- Parses the configuration using a custom file manager.
- Uses polymorphism and a factory design pattern to select the appropriate processor.
- Processes different data types based on user-provided configuration settings.

The system is structured using OOP concepts, including inheritance and polymorphism. The core classes are designed to handle different types of data with factory method.

---

## Key Features

### 1. **Dynamic Configuration Parsing**
- The system reads a configuration file, parses its content, and organizes options using dot notation for nested structures.
- Based on the configuration file, the system selects a processor type dynamically.

**Example Configuration File (`settings.txt`):**

```
Processor.Options.Type=Text
Processor.Options.MaxRetries=5
Processor.Options.Threshold=0.75
```

- The file contains configuration values for processor options (type, maximum retries, and threshold).
  
### 2. **Processor Abstraction**
- The `Processor` class is an abstract base class, and several derived classes (e.g., `TextProcessor`, `NumericProcessor`, `AudioProcessor`) implement specific processing logic.

Each processor has the following attributes:
- **Type**: A string describing the type of data the processor handles.
- **Threshold**: A float value that could be used to define thresholds in processing.
- **MaxRetries**: An integer value representing the maximum number of retries for processing operations.

### 3. **Factory Design Pattern**
- The `ProcessorFactory` class creates the appropriate processor type based on the configuration options passed at runtime.

**Example of Factory Usage:**

The `ProcessorFactory` class instantiates a specific processor type based on the configuration file:

```cpp
ProcessorFactory factory;
std::unique_ptr<Processor> processor = factory.createProcessor(processorType, threshold, maxRetries);
```

The factory decides which processor to create (`TextProcessor`, `NumericProcessor`, etc.) based on the input configuration.

### 4. **Template-Based Processing**
- The system can be extended to use templates to process different kinds of data more flexibly, reducing redundant code for various data types.

---

## File Breakdown

### 1. **main.cpp**
This is the entry point of the application. It manages the entire flow of reading the configuration file, extracting processor options, and creating the correct processor instance based on those options.

#### Key Tasks:
- Opens the configuration file and reads the content.
- Parses the content to extract key configuration values.
- Selects the processor type based on the configuration.
- Instantiates the processor using a factory class.
- Outputs the processor settings.

#### Example:

```cpp
FileManager fileManager("../config/settings.txt");
std::string fileContent;
fileManager >> fileContent;

std::istringstream iss(fileContent);
std::string line;
while (std::getline(iss, line)) {
    // Parse each line for key-value pairs
}

auto Processor_Options_Type = configMap.find("Processor.Options.Type");
auto Processor_Options_MaxRetries = configMap.find("Processor.Options.MaxRetries");
auto Processor_Options_Threshold = configMap.find("Processor.Options.Threshold");

// Create processor using factory
ProcessorFactory factory;
std::unique_ptr<Processor> processor = factory.createProcessor(processorType, threshold, maxRetries);
```

### 2. **FileManager.hpp / FileManager.cpp**
These files handle reading from and writing to files. The `FileManager` class encapsulates the file operations, allowing for easy file manipulation and error handling.

#### Key Methods:
- `readFromFile`: Reads the content of a file into a string.
- `writeToFile`: Writes data to a file.
- Operator overloading for `<<` and `>>` to handle file reading and writing directly.

#### Example:

```cpp
FileManager fileManager("../config/settings.txt");
fileManager >> fileContent; // Read file content
fileManager << "Some data"; // Write to file
```

### 3. **Processor.hpp / Processor.cpp**
The `Processor` class is the base class for all processor types, with common attributes like `type`, `threshold`, and `maxRetries`. Derived classes like `TextProcessor`, `NumericProcessor`, `ImageProcessor`, etc., implement specific processing logic for each data type.

#### Key Classes:
- **Processor**: Abstract base class for processors.
- **TextProcessor, NumericProcessor, ImageProcessor, AudioProcessor, VideoProcessor**: Derived classes implementing data-specific processing.

#### Example:

```cpp
TextProcessor::TextProcessor(const std::string& type, float threshold, int maxRetries)
    : Processor(type, threshold, maxRetries) {
    // Initialization for text processor
}

std::string Processor::getType() {
    return type;
}
```

### 4. **ProcessorFactory.hpp / ProcessorFactory.cpp**
The `ProcessorFactory` class creates processor instances based on the configuration file's type option. It uses the Factory Design Pattern to instantiate the appropriate processor dynamically.

#### Key Method:
- `createProcessor`: Instantiates and returns a specific processor type.

#### Example:

```cpp
std::unique_ptr<Processor> ProcessorFactory::createProcessor(EnumProcessorType type, float threshold, int maxRetries) {
    switch (type) {
        case TEXT:
            return std::make_unique<TextProcessor>("Text", threshold, maxRetries);
        case NUMERIC:
            return std::make_unique<NumericProcessor>("Numeric", threshold, maxRetries);
        // Handle other types...
    }
}
```

### 5. **Enums and Utility Functions**
- **EnumProcessorType**: Enum representing the different processor types (`TEXT`, `NUMERIC`, `IMAGE`, `AUDIO`, `VIDEO`).
- **getProcessorTypeFromString**: A utility function that converts a string (from the config file) into the corresponding enum value.

#### Example:

```cpp
EnumProcessorType getProcessorTypeFromString(const std::string& typeStr) {
    if (typeStr == "Text") return EnumProcessorType::TEXT;
    if (typeStr == "Numeric") return EnumProcessorType::NUMERIC;
    // Handle other types...
}
```

---

## Compilation and Execution

1. **Dependencies**:
    - C++ Standard Library
    - C++11 or later for smart pointers and other modern features.

2. **To Compile**:
    ```bash
    g++ -std=c++11 -o DataProcessor main.cpp FileManager.cpp Processor.cpp ProcessorFactory.cpp
    ```

3. **To Run**:
    ```bash
    ./DataProcessor
    ```

This will execute the program, read the configuration from `settings.txt`, and create and display the processor settings.

---

## Extending the System

We can extend the system by adding new processor types. For example, if we want to add a new processor for handling "XML" data, you would:
1. Add a new `XMLProcessor` class derived from `Processor`.
2. Update the `ProcessorFactory` to support creating an `XMLProcessor` instance.
3. Update the configuration file to include an option for the XML processor type.

---

## Conclusion

This project demonstrates how to build a modular and extensible system in C++ using object-oriented principles like inheritance, polymorphism, and the factory design pattern. The system can easily be extended to support additional data types, making it a flexible solution for processing different kinds of data based on user configuration.

