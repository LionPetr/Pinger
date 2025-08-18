#pragma once
#include <windows.h>
#define TIMER_ID 1



void StartTimer(HWND hWnd);

void StopTimer(HWND hWnd);

bool IsTimerRunning();