#include "InputPlayer.h"

#include <fstream>
#include <string>
#include <thread>

namespace utilities
{
    void InputPlayer::load(std::ifstream &recordingFile)
    {
        m_recordingFile = &recordingFile;

    }

    void InputPlayer::playToAndExec(HandlesChecksAndExecs &probablyARobot)
    {

        //std::string delta{""};
        //std::getline(*m_recordingFile, delta);

        //duration_t deltaTime{std::stod(delta)};
        


        m_recordingThread = std::thread{&InputPlayer::playRecordingExec, this, &probablyARobot};
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
        std::string snapshot{""};
        while(std::getline(*m_recordingFile, snapshot))
        {
            std::size_t i{0};
            std::chrono::duration<double> delta{std::stod(snapshot, &i)};
            probablyARobot->getInputHandler() = snapshot.substr(i);
            probablyARobot->checkAndExec();
            std::this_thread::sleep_for(delta);
        }
    }

}
