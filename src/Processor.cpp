#include "../include/Processor.hpp"
#include <iostream>

/*The override specifier should be only in the declaration inside the .hpp file
not in the .cpp file.*/

/*Default arguments should only be in the header file
not in the definition inside the .cpp file.*/

/*You don't need to explicitly write virtual in the destructor definition in the .cpp
file. The virtual keyword is only required in the class declaration (.hpp)
not in the implementation.*/

/*********************** Processor Class ************************/
Processor::Processor(const std::string& type, float threshold, int MaxRetries)
{
    std::cout << "Processor Class is called" << std::endl;
}

std::string Processor::getType() 
{
    return type;
}


float Processor::getThreshold()
{
    return threshold;
}

int Processor::getMaxRetries()
{
    return MaxRetries;
}
Processor::~Processor()
{
    std::cout << "Processor Class destructor is called" << std::endl;
}

/******************** Text Processor Class ************************/

TextProcessor::TextProcessor(const std::string& type, float threshold, int MaxRetries)
{
    std::cout << "TextProcessor Class is called" << std::endl;
    this->type = type;
    this->threshold = threshold;
    this->MaxRetries = MaxRetries;
}


TextProcessor::~TextProcessor() 
{
    std::cout << "TextProcessor destructor is called" << std::endl;
}

/******************** Numeric Processor Class ************************/
NumericProcessor::NumericProcessor(const std::string& type, float threshold, int MaxRetries)
{
    std::cout << "NumericProcessor Class is called" << std::endl;
    this->type = type;
    this->threshold = threshold;
    this->MaxRetries = MaxRetries;
}

NumericProcessor::~NumericProcessor()
{
    std::cout << "NumericProcessor destructor is called" << std::endl;
}

/******************** Image Processor Class ************************/
ImageProcessor::ImageProcessor(const std::string& type, float threshold, int MaxRetries)
{
    std::cout << "Image Processor Class is called" << std::endl;
    this->type = type;
    this->threshold = threshold;
    this->MaxRetries = MaxRetries;
}

ImageProcessor::~ImageProcessor()
{
    std::cout << "ImageProcessor destructor is called" << std::endl;
}

/******************** Audio Processor Class ************************/

AudioProcessor::AudioProcessor(const std::string& type, float threshold, int MaxRetries)
{
    std::cout << "AudioProcessor Class is called" << std::endl;
    this->type = type;
    this->threshold = threshold;
    this->MaxRetries = MaxRetries;
}

AudioProcessor::~AudioProcessor()
{
    std::cout << "AudioProcessor destructor is called" << std::endl;
}

/******************** Video Processor Class ************************/
VideoProcessor::VideoProcessor(const std::string& type, float threshold, int MaxRetries)
{
    std::cout << "VideoProcessor Class is called" << std::endl;
    this->type = type;
    this->threshold = threshold;
    this->MaxRetries = MaxRetries;
}

VideoProcessor::~VideoProcessor()
{
    std::cout << "VideoProcessor destructor is called" << std::endl;
}