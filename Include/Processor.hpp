#ifndef __PROCESSOR_HPP__
#define __PROCESSOR_HPP__

#include <string>

class Processor
{
    protected:
    std::string type;
    float threshold;
    int MaxRetries;

    public:
    Processor(const std::string& type = "", float threshold = 0, int MaxRetries =0);
    std::string getType();
    float getThreshold();
    int getMaxRetries() ;
    virtual ~Processor();

};

class TextProcessor : public Processor
{
    public:
    TextProcessor(const std::string& type= "" ,float threshold = 0, int MaxRetries =0);

    ~TextProcessor() ;

};

class NumericProcessor : public Processor
{
    public:
    NumericProcessor(const std::string& type = "", float threshold = 0, int MaxRetries =0);

    ~NumericProcessor();

};

class ImageProcessor : public Processor
{
    public:
    ImageProcessor(const std::string& type = "", float threshold = 0, int MaxRetries =0);

    ~ImageProcessor();
};

class AudioProcessor : public Processor
{
    public:
    AudioProcessor(const std::string& type = "", float threshold = 0, int MaxRetries =0);

    ~AudioProcessor();
};

class VideoProcessor : public Processor
{
    public:
    VideoProcessor(const std::string& type = "", float threshold = 0, int MaxRetries =0);

    ~VideoProcessor();
};

#endif // __PROCESSOR_HPP__