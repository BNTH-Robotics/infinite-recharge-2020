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
        recordingInit();
    }

    if (leInputHandler.getButtonBackState() && isRecording) //Do not use elseif!!! If is for better response!!!
    {
        flushRecordingToFile();
    }

    if (isRecording)
    {
        recordControllerToFile();
    }

    if (leInputHandler.getButtonYState())
    {
        resetRecordingState();
    }
}

void Robot::recordingInit()
{
    isRecording = true;
    recordingEnabled = false;
    std::cout << m_chooser.GetSelected() << '\n';
    m_leRecordScribe.stopLoadedRecording();
    if (m_recordFile.is_open())
    {
        m_recordFile.close();
    }
    m_recordFile.clear();
    m_recordFile.open(inputRecordFileName + m_chooser.GetSelected());
    m_leRecordScribe.designateFile(m_recordFile);
}

void Robot::recordControllerToFile()
{
    std::cout << "recording" << '\n';
    m_leRecordScribe.snapFromAndWrite(this, getFrametime());
}

void Robot::flushRecordingToFile()
{
    isRecording = false;
    assert(m_recordFile.is_open());
    isRecording = false;
    m_leRecordScribe.stopRecording();

    m_recordFile.close();
}

void Robot::resetRecordingState()
{
    if (m_recordFile.is_open())
    {
        m_recordFile.close();
    }
    recordingEnabled = true;
    m_recordFile.open(inputRecordFileName + m_chooser.GetSelected());

    std::cout << "Recording Resetted" << '\n';
}