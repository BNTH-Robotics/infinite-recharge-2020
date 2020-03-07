#include "InputPlayer.h"

#include <iostream>
#include <fstream>
#include <string>
#include <thread>

namespace utilities
{
    void InputPlayer::load(std::ifstream *recordingFile)
    {
        std::cout << "New file loaded\n";
        m_recordingFile = recordingFile;
    }

    void InputPlayer::playToAndExec(HandlesChecksAndExecs *probablyARobot)
    {

        //std::string delta{""};
        //std::getline(*m_recordingFile, delta);
        //duration_t deltaTime{std::stod(delta)};
        


        m_recordingThread = std::thread{static_cast<void (InputPlayer::*)(HandlesChecksAndExecs *)>(&InputPlayer::playRecordingExec), this, probablyARobot};
        m_recordingThread.detach();

    }
    
    void InputPlayer::playRecordingExec(HandlesChecksAndExecs *probablyARobot, duration_t delta)
    {
        std::string snapshot{""};
        while(std::getline(*m_recordingFile, snapshot))
        {
            probablyARobot->getInputHandler() = snapshot;
            probablyARobot->checkAndExec();
            std::this_thread::sleep_for(delta);
        }
    }

    void InputPlayer::playRecordingExec(HandlesChecksAndExecs *probablyARobot)
    {
        m_playbackEnabled = true;
        duration_t overheadTime{0};
        duration_t executionTime{0};
        timepoint_t now{clock_t::now()};
        timepoint_t lastSnap{clock_t::now()};
        std::string snapshot{""};
        while(std::getline(*m_recordingFile, snapshot))
        {
            if (!m_playbackEnabled)
            {
                std::cout << "Playback Stopped!\n";
                break;
            }
            std::size_t i{0};
            std::chrono::duration<double> delta{std::stod(snapshot, &i)};
            duration_t sleepTime{delta - overheadTime};

            std::this_thread::sleep_for((sleepTime));
            probablyARobot->getInputHandler() = snapshot.substr(i);
            probablyARobot->checkAndExec();
            //std::cout << snapshot << '\n';
            //overheadTime -= delta;
            now = clock_t::now();
            executionTime = std::chrono::duration_cast<duration_t>(now - lastSnap);
            lastSnap = now;
            //std::cout << "DeltaInput: " << sleepTime.count() << '\n';
            //std::cout << (executionTime).count() << '\n';
            overheadTime = executionTime - sleepTime;
        }
        std::cout << "Done Playing \n";
    }

}
