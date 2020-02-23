#ifndef YEET_INPUT_RECORDER_H 
#define YEET_INPUT_RECORDER_H
#include "HandlesChecksAndExecs.h"

#include <chrono>
#include <fstream>
#include <sstream>

namespace utilities
{
    class InputRecorder
    {
    public:
    InputRecorder() {}

    void designateFile(std::ofstream &recordingFile);
    void recordFrom(HandlesChecksAndExecs &probablyARobot);
    void snapFrom(HandlesChecksAndExecs *probablyARobot);
    void snapFrom(HandlesChecksAndExecs *probablyARobot, std::chrono::duration<double> delta);
    //void stopRecording();
    void stopRecording(std::chrono::duration<double> delta);
    void stopRecording();

    private:
    std::ofstream *m_recording{};
    std::stringstream m_recordingBuffer{};

    void snap();
    };
}
#endif