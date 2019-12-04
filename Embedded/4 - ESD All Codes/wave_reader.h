#ifndef WAVE_READER_H
#define WAVE_READER_H

#include <string>
#include <vector>
#include "audio_format.h"
#include "pcm_wave_header.h"

using std::vector;
using std::string;

class WaveReader
{
    public:
        WaveReader(string filename, bool &forceStop);
        virtual ~WaveReader();

        AudioFormat* getFormat();
        vector<float>* getFrames(unsigned frameCount, bool &forceStop);
        bool setFrameOffset(unsigned frameOffset);
    private:
        string filename;
        PCMWaveHeader header;
        unsigned dataOffset, currentOffset;
        int fileDescriptor;

        vector<char>* readData(unsigned bytesToRead, bool headerBytes, bool &forceStop);
        string getFilename();
};

#endif // WAVE_READER_H
