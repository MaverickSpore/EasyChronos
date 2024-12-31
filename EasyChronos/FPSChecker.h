#pragma once

#include <cstdlib>
#include <chrono>

class FPSChecker
{
protected:
	std::chrono::steady_clock::time_point ElapsedTimeChecker;
	std::chrono::steady_clock::time_point ElapsedFrameChecker;

public:
	FPSChecker();

	// Call either reset method when a timer has returned true to reset the timer
	void ResetAllTimers();
	// Call either reset method when a timer has returned true to reset the timer
	void ResetEachTimer(bool TimeChecker = false, bool FrameChecker = false);

	// Checks if the amount of time has elapsed since the last method call
	bool TimeHasElapsed(float amountOfMilliseconds);

	// Checks if the amount of frames has elapsed since the last method call - if 30fps, pass through 30 as frameCount
	bool FramesHaveElapsed(float frameCount = 30, float fps = 30);
};

