#ifndef YEET_INPUT_PLAYER_H
#define YEET_INPUT_PLAYER_H
#include "HandlesChecksAndExecs.h"
#include "InputHandler.h"

#include <chrono>
#include <thread>
#include <fstream>
namespace utilities
{
    class InputPlayer
    {
    using duration_t = std::chrono::duration<double>;
    public:
        InputPlayer () {};

        void load(std::ifstream &recordingFile);
        //void playTo(InputHandler &inputhandler);
        void playToAndExec(HandlesChecksAndExecs &probablyARobot);
        //void stop();
    private:
        std::ifstream *m_recordingFile{};
        std::thread m_recordingThread{};

        //void playRecordingExec(HandlesChecksAndExecs *probablyARobot, duration_t delta);
        void playRecordingExec(HandlesChecksAndExecs *probablyARobot);

        


    };
}
#endif