#include "InputRecorder.h"

#include <sstream>
#include <string>
#include <thread>

#include <iostream>
namespace utilities
{
    void InputRecorder::designateFile(std::ofstream &recordingFile)
    {
        resetBuffer();
        m_recording = &recordingFile;
        std::cout << "Designated\n";
    }

    void InputRecorder::recordFrom(HandlesChecksAndExecs &probablyARobot)
    {
    }

    void InputRecorder::snapFrom(HandlesChecksAndExecs *probablyARobot)
    {
        m_recordingBuffer << probablyARobot->getInputHandler().getSnapshot() << '\n';
    }

    void InputRecorder::snapFrom(HandlesChecksAndExecs *probablyARobot, std::chrono::duration<double> delta)
    {
        m_recordingBuffer << delta.count() << ' ' << probablyARobot->getInputHandler().getSnapshot() << '\n';
    }

    void InputRecorder::stopRecording(std::chrono::duration<double> delta)
    {
        std::string line{""};

        *m_recording << delta.count() << '\n';

    while (std::getline(m_recordingBuffer, line))
        {
            *m_recording << line << '\n';
        }
        
      std::cout << "DONE RECORDING\n";
    }
    void InputRecorder::stopRecording()
    {
        std::string line{""};

    while (std::getline(m_recordingBuffer, line))
        {
            std::cout << line << '\n';
            *m_recording << line << '\n';
        }
        
      std::cout << "DONE RECORDING\n";
    }


}
