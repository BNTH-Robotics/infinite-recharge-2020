#include "InputRecorder.h"

#include <sstream>
#include <string>
#include <thread>

#include <iostream>
namespace utilities
{
    void InputRecorder::designateFile(std::ofstream &recordingFile)
    {
        m_recording = &recordingFile;
    }

    void InputRecorder::recordFrom(HandlesChecksAndExecs &probablyARobot)
    {
    }

    void InputRecorder::snapFrom(HandlesChecksAndExecs *probablyARobot)
    {
        m_recordingBuffer << probablyARobot->getInputHandler().getSnapshot() << '\n';
    }

    void InputRecorder::stopRecording(std::chrono::duration<double> delta)
    {
        std::cout << "Hi" << '\n';
        std::string line{""};

        *m_recording << delta.count() << '\n';

    while (std::getline(m_recordingBuffer, line))
        {
            *m_recording << line << '\n';
        }
    }


}