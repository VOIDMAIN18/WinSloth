#include <iostream>
#include <Windows.h>




inline bool winOpenFile(std::wstring filepath) {
   
    HINSTANCE result = ShellExecuteW(
        nullptr,          // No parent window
        L"open",          // The action we want to perform
        filepath.c_str(),        // ?The file we want to open / why c.str cause it is based on c and winapi is also based on c so it don't know what is wstring 
        nullptr,          // No extra parameters
        nullptr,          // No specific working directory
        SW_SHOWNORMAL     // Show the window normally
    );

    return result ?  1 :  0; 
}


