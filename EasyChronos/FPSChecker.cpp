#include "FPSChecker.h"

FPSChecker::FPSChecker()
{
    using namespace std::chrono;

    ElapsedTimeChecker = steady_clock::now();
    ElapsedFrameChecker = steady_clock::now();
}

void FPSChecker::ResetAllTimers()
{
    using namespace std::chrono;

    ElapsedTimeChecker = steady_clock::now();
    ElapsedFrameChecker = steady_clock::now();
}

void FPSChecker::ResetEachTimer(bool TimeChecker, bool FrameChecker)
{
    using namespace std::chrono;

    if (TimeChecker)
        ElapsedTimeChecker = steady_clock::now();
    if (FrameChecker)
        ElapsedFrameChecker = steady_clock::now();

}

bool FPSChecker::TimeHasElapsed(float amountOfMilliseconds)
{
    using namespace std::chrono;

    steady_clock::time_point now = steady_clock::now();

    if ((now - ElapsedTimeChecker) > duration<float, std::milli>(amountOfMilliseconds))
    {
        return true;
    }

    return false;
}

bool FPSChecker::FramesHaveElapsed(float frameCount, float fps)
{
    using namespace std::chrono;

    steady_clock::time_point now = steady_clock::now();

    if ((now - ElapsedFrameChecker) > duration<float>(frameCount / fps))
    {
        
        return true;
    }

    return false;
}
