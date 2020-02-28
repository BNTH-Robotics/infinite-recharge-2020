#ifndef YEET_INPUT_RECORD_AND_PLAY
#define YEET_INPUT_RECORD_AND_PLAY
#include "InputPlayer.h"
#include "InputRecorder.h"
#include "HandlesChecksAndExecs.h"
#include "XboxInputHandler.h"

#include <chrono>
#include <fstream>
#include <string>
namespace utilities
{
    class InputRecordAndPlay
    {
    public:
        InputRecordAndPlay() {}

        void loadRecording(std::ifstream &recordingFile);
        void designateFile(std::ofstream &recordingFile);

        //void playLoadedRecordingTo(utilities::XboxInputHandler);
        void playLoadedRecordingToAndExec(HandlesChecksAndExecs *probablyARobot);
        //void pauseLoadedRecording();
        //void stopLoadedRecording();
        void recordFromAndTo(HandlesChecksAndExecs &probablyARobot, std::ofstream &outputFile);
        void snapFromAndWrite(HandlesChecksAndExecs *probablyARobot);
        //void stopRecording();
        void stopRecording(std::chrono::duration<double> &delta);

    private:
    InputRecorder m_recorder{};
    InputPlayer m_player{};
    std::ifstream *m_recording{};
    std::ofstream *m_recordedFile{};
    };
}
#endif
