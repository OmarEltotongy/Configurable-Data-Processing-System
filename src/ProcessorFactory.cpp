#include "../include/ProcessorFactory.hpp"
#include <iostream> 

EnumProcessorType getProcessorTypeFromString(const std::string& typeStr) {
    if (typeStr == "Text") return EnumProcessorType::TEXT;
    if (typeStr == "Numeric") return EnumProcessorType::NUMERIC;
    if (typeStr == "Image") return EnumProcessorType::IMAGE;
    if (typeStr == "Audio") return EnumProcessorType::AUDIO;
    if (typeStr == "Video") return EnumProcessorType::VIDEO;
    throw std::invalid_argument("Invalid processor type: " + typeStr);
}


std::unique_ptr<Processor> ProcessorFactory::createProcessor(EnumProcessorType type,float Processor_Options_Threshold, int Processor_Options_MaxRetries)
{
    switch (type)
    {
        case TEXT:
            return std::make_unique<TextProcessor>("Text",  Processor_Options_Threshold, Processor_Options_MaxRetries);
        case NUMERIC:
            return std::make_unique<NumericProcessor>("Numeric" , Processor_Options_Threshold, Processor_Options_MaxRetries);
        case IMAGE:
            return std::make_unique<ImageProcessor>("Image", Processor_Options_Threshold, Processor_Options_MaxRetries);
        case AUDIO:
            return std::make_unique<AudioProcessor>("Audio", Processor_Options_Threshold, Processor_Options_MaxRetries);
        case VIDEO:
            return std::make_unique<VideoProcessor>("Video", Processor_Options_Threshold, Processor_Options_MaxRetries);
        default:
            return nullptr;
    }

}
