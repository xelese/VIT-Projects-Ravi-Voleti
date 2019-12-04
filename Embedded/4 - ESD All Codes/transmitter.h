#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include "error_reporter.h"
#include "audio_format.h"
#include <vector>

using std::vector;

#define BUFFER_TIME 1000000

using std::string;

class Transmitter
{
    public:
        virtual ~Transmitter();

        void play(string filename, double frequency, bool loop);
        void stop();

        static Transmitter* getInstance();
    private:
        Transmitter();

        bool forceStop, eof;

        static void* peripherals;
        static vector<float>* buffer;
        static bool transmitting, restart;
        static unsigned frameOffset, clockDivisor;
        static void* transmit(void* params);
};

#endif // TRANSMITTER_H
