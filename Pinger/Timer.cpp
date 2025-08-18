#include "Timer.h"
#define TIMER_INTERVAL 5000

static bool g_timerRunning = false;

void StartTimer(HWND hWnd)
{
	if (!g_timerRunning)
	{
		SetTimer(hWnd, TIMER_ID, TIMER_INTERVAL, NULL);
		g_timerRunning = true;
	}
}

void StopTimer(HWND hWnd)
{
	if (g_timerRunning)
	{
		KillTimer(hWnd, TIMER_ID);
		g_timerRunning = false;
	}
}

bool IsTimerRunning()
{
	return g_timerRunning;
}
