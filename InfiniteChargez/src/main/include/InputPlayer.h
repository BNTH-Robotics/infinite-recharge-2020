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
    using clock_t  = std::chrono::steady_clock;
    using duration_t = std::chrono::duration<double>;
    using timepoint_t = std::chrono::time_point<clock_t>;
    public:
        InputPlayer () {};

        void load(std::ifstream &recordingFile);
        //void playTo(InputHandler &inputhandler);
        void playToAndExec(HandlesChecksAndExecs *probablyARobot);
        //void stop();
    private:
        std::ifstream *m_recordingFile{};
        std::thread m_recordingThread{};

        timepoint_t m_lastSnap;

        //void playRecordingExec(HandlesChecksAndExecs *probablyARobot, duration_t delta);
        void playRecordingExec(HandlesChecksAndExecs *probablyARobot);
    };
}
#endif