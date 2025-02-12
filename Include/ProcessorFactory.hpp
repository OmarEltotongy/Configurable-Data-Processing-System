#ifndef __PROCESSORFACTORY_H__
#define __PROCESSORFACTORY_H__

#include <string>
#include <memory>
#include <map>
#include "../include/Processor.hpp"

enum EnumProcessorType 
{
    TEXT , NUMERIC , IMAGE , AUDIO , VIDEO
};

EnumProcessorType getProcessorTypeFromString(const std::string& typeStr);

class ProcessorFactory
{
    public:
    std::unique_ptr<Processor> createProcessor(EnumProcessorType type,float Processor_Options_Threshold, int Processor_Options_MaxRetries);

};

#endif // __PROCESSORFACTORY_H__