#include "XboxInputHandler.h"
#include "Robot.h"

#include <thread>
#include <chrono>
#include <string>
#include <fstream>

void Robot::recordActionsExec(utilities::XboxInputHandler &leInputHandler, duration_t delta)
{
    if (leInputHandler.getButtonStartState() && recordingEnabled)
    {
        isRecording = true;
        recordingEnabled = false;
        meanDelta = delta.count();
        m_leRecordScribe.designateFile(m_recordFile);
    }
    if (leInputHandler.getButtonBackState() && isRecording) //Do not use elseif!!! If is for better response!!!
    {
        isRecording = false;
        assert(m_recordFile.is_open());
        isRecording = false;
        duration_t meanDeltaFinal{meanDelta};
        m_leRecordScribe.stopRecording(meanDeltaFinal);
        
        m_recordFile.close();
    }

    if (isRecording)
    {
        std::cout << "recording" << '\n';
        meanDelta = (meanDelta + delta.count()) / 2;
        m_leRecordScribe.snapFromAndWrite(this, delta);
    }
    if (leInputHandler.getButtonXPressed())
    {
        recordingEnabled = true;
        std::cout << "Recording Resetted";
    }
}