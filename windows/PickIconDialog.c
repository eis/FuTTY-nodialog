/*
 * HACK: PuttyTray / Session Icon
 * Added this file
 */ 
#include <windows.h>
typedef WINSHELLAPI BOOL(WINAPI * fnPickIconDlg) (HWND hWndParent, LPTSTR pszFilename, LPDWORD pdwBufferSize, LPDWORD pdwIndex);

BOOL SelectIconA(HWND hWndParent, LPSTR lpszFilename, DWORD dwBufferSize, DWORD * pdwIndex) {
    BOOL result = FALSE;
    OSVERSIONINFO versioninfo;
    HMODULE shell32_module = GetModuleHandle("shell32.dll");
    versioninfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    GetVersionEx(&versioninfo);

	if (shell32_module) {
		fnPickIconDlg PickIconDlg = (fnPickIconDlg) GetProcAddress(shell32_module, (LPCSTR) 62);
		if (PickIconDlg) {
			if (versioninfo.dwPlatformId == VER_PLATFORM_WIN32_NT) {
				LPWSTR pszWideName = (LPWSTR) malloc(dwBufferSize);
				MultiByteToWideChar(CP_ACP, 0, lpszFilename, -1, pszWideName, dwBufferSize);
				result = PickIconDlg(hWndParent, (LPTSTR) pszWideName, &dwBufferSize, pdwIndex);
				WideCharToMultiByte(CP_ACP, 0, pszWideName, -1, lpszFilename, dwBufferSize, NULL, NULL);
				free(pszWideName);
			} else {
				result = PickIconDlg(hWndParent, (LPTSTR) lpszFilename, &dwBufferSize, pdwIndex);
			}
		}
		FreeLibrary(shell32_module);
    }

    return result;
}


BOOL SelectIconW(HWND hWndParent, LPWSTR lpszFilename, DWORD dwBufferSize, DWORD * pdwIndex) {
    BOOL result = FALSE;
    OSVERSIONINFO versioninfo;
    HMODULE shell32_module = GetModuleHandle("shell32.dll");
    versioninfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    GetVersionEx(&versioninfo);

	if (shell32_module) {
		fnPickIconDlg PickIconDlg = (fnPickIconDlg) GetProcAddress(shell32_module, (LPCSTR) 62);
		if (PickIconDlg) {
			if (versioninfo.dwPlatformId != VER_PLATFORM_WIN32_NT) {
				LPSTR pszMBName = (LPSTR) malloc(dwBufferSize);
				WideCharToMultiByte(CP_ACP, 0, lpszFilename, -1, pszMBName, dwBufferSize, NULL, NULL);
				result = PickIconDlg(hWndParent, (LPTSTR) pszMBName, &dwBufferSize, pdwIndex);
				MultiByteToWideChar(CP_ACP, 0, pszMBName, -1, lpszFilename, dwBufferSize);
				free(pszMBName);
			} else {
				result = PickIconDlg(hWndParent, (LPTSTR) lpszFilename, &dwBufferSize, pdwIndex);
			}
		}
		FreeLibrary(shell32_module);
    }

    return result;
}
