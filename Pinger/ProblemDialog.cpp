#include "ProblemDialog.h"
#include "resource.h"
#include <stdlib.h>
#include <tchar.h>
#include <iostream>

INT_PTR CALLBACK ProblemDialogProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int correctAnswer;

	switch (message)
	{
	case WM_INITDIALOG:
	{
		SetForegroundWindow(hDlg);
		int a = rand() % 10;
		int b = rand() % 10;
		correctAnswer = a + b;

		wchar_t problemText[64];
		swprintf(problemText, 64, L"What is %d + %d?", a, b);
		SetDlgItemText(hDlg, IDC_PROBLEM_STATIC, problemText);
		return TRUE;
	}

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			wchar_t buffer[32];
			GetDlgItemText(hDlg, IDC_ANSWER_EDIT, buffer, 32);
			int userAnswer = _wtoi(buffer);

			if (userAnswer == correctAnswer)
			{
				EndDialog(hDlg, IDOK);
			}
			else
			{
				MessageBox(hDlg, L"Incorrect, try again!", L"Oops", MB_OK | MB_ICONEXCLAMATION);
			}
			return TRUE;
		}
		else if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, IDCANCEL);
			return TRUE;
		}
		break;
	}
	return FALSE;
}

bool ShowProblemDialog(HINSTANCE hInstance, HWND hParent)
{
	INT_PTR result = DialogBox(hInstance, MAKEINTRESOURCE(IDD_PROBLEM_DIALOG), hParent, ProblemDialogProc);
	std::cout << "got here" << std::endl;
	return (result == IDOK);

}