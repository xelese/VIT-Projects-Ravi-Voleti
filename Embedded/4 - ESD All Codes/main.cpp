#include <iostream>
#include "wave_reader.h"
#include "transmitter.h"
#include <cstdlib>
#include <csignal>

using namespace std;

bool stop = false;
Transmitter* transmitter = NULL;

AudioFormat* getFormat(string filename) {
    stop = false;
    WaveReader* reader = new WaveReader(filename, stop);
    AudioFormat* format = reader->getFormat();
    delete reader;
    return format;
}

void sigIntHandler(int sigNum)
{
    if (transmitter != NULL) {
        cout << "Stopping..." << endl;
        transmitter->stop();
        stop = true;
    }
}

int main(int argc, char** argv)
{
    double frequency = 100.0;
    bool loop = false;
    string filename;

    bool showUsage = true;
    for (int i = 1; i < argc; i++) {
        if (string("-f") == argv[i]) {
            if (i < argc - 1) {
                frequency = ::atof(argv[i + 1]);
                i++;
            }
        } else if (string("-r") == argv[i]) {
            loop = true;
        } else {
            if (i == argc - 1) {
                showUsage = false;
                filename = argv[i];
            }
        }
    }
    if (showUsage) {
        cout << "Usage: " << argv[0] << " [-f frequency] [-r] FILE" << endl;
        return 0;
    }

    signal(SIGINT, sigIntHandler);

    try {
        transmitter = Transmitter::getInstance();

        if (filename != "-") {
            AudioFormat* format = getFormat(filename);
            cout << "Playing: " << filename << ", "
                 << format->sampleRate << " Hz, "
                 << format->bitsPerSample << " bits, "
                 << ((format->channels > 0x01) ? "stereo" : "mono") << endl;
            delete format;
        } else {
            cout << "Playing: STDIN" << endl;
        }

        transmitter->play(filename, frequency, loop);
    } catch (exception &error) {
        cout << "Error: " << error.what() << endl;
        return 1;
    }

    return 0;
}
