#include "InputPlayer.h"

#include <iostream>
#include <fstream>
#include <string>
#include <thread>

namespace utilities
{
    void InputPlayer::load(std::ifstream &recordingFile)
    {
        m_recordingFile = &recordingFile;

    }

    void InputPlayer::playToAndExec(HandlesChecksAndExecs *probablyARobot)
    {

        //std::string delta{""};
        //std::getline(*m_recordingFile, delta);

        //duration_t deltaTime{std::stod(delta)};
        


        m_recordingThread = std::thread{&InputPlayer::playRecordingExec, this, probablyARobot};
        m_recordingThread.detach();

    }
    
    //void InputPlayer::playRecordingExec(HandlesChecksAndExecs *probablyARobot, duration_t delta)
    //{
    //    std::string snapshot{""};
    //    while(std::getline(*m_recordingFile, snapshot))
    //    {
    //        probablyARobot->getInputHandler() = snapshot;
    //        probablyARobot->checkAndExec();
    //        std::this_thread::sleep_for(delta);
    //    }
    //}

    void InputPlayer::playRecordingExec(HandlesChecksAndExecs *probablyARobot)
    {
        bool first{true};
        m_lastSnap = clock_t::now();
        std::string snapshot{""};
        while(std::getline(*m_recordingFile, snapshot))
        {
            timepoint_t now = clock_t::now();
            std::cout << snapshot;
            std::size_t i{0};
            std::chrono::duration<double> delta{std::stod(snapshot, &i)};
            probablyARobot->getInputHandler() = snapshot.substr(i);
            probablyARobot->checkAndExec();
            duration_t overheadTime{std::chrono::duration_cast<duration_t>(now - m_lastSnap) - delta};
            m_lastSnap = now;
            if (first)
            {
            std::this_thread::sleep_for(delta);
            }
            else
            {
            std::this_thread::sleep_for(delta - overheadTime);
            }
        }
    }

}
