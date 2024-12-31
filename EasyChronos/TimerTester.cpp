#pragma once

#include "FPSChecker.h"
#include <iostream>

//#define TimerTester

#ifdef TimerTester

int main()
{

	FPSChecker timerObj;

	while (true)
	{
		float frameCount = 10;
		float fps = 60;

		if (timerObj.FramesHaveElapsed(frameCount, fps))
		{
			std::cout << frameCount << " frames have elapsed at " << fps << " fps\n";
			timerObj.ResetEachTimer(false, true);
		}

		float timeAmount = 1000;

		if (timerObj.TimeHasElapsed(timeAmount))
		{
			std::cout << timeAmount << " milliseconds, or " << timeAmount/1000 << " seconds have elapsed\n";
			timerObj.ResetEachTimer(true, false);
		}
	}



	return 0;
}


#endif // TimerTester