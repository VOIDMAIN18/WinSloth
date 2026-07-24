#pragma once

#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif


#define RESET       "\033[0m"
#define DIM         "\033[2;37m"
#define RED         "\033[31m"
#define GREEN       "\033[1;32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define WHITE       "\033[37m"
#define BOLD_WHITE  "\033[1;37m"
#define BOLD_CYAN   "\033[1;36m"

namespace consoleui {
    class MainUiStart {
    private:
        void init_console() {
#ifdef _WIN32
            SetConsoleOutputCP(CP_UTF8);
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            DWORD dwMode = 0;
            if (GetConsoleMode(hOut, &dwMode)) {
                dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
                SetConsoleMode(hOut, dwMode);
            }
#endif
        }

    public:
        void openwin() {
            
            init_console();

            std::cout << "\n";
            std::cout << BOLD_CYAN << "  ⚡ WINSLOTH " << RESET << DIM << "v1.0.0" << RESET << "\n";
            std::cout << DIM << "  ────────────────────────────────────────────" << RESET << "\n";
            std::cout << BOLD_WHITE << "  Fast file & executable search engine." << RESET << "\n";
            std::cout << DIM << "  Supported Platforms: Windows | Linux | macOS" << RESET << "\n\n";
            std::cout << "  " << GREEN << "●" << RESET << " Open Source " << DIM << "• Built by VOIDMAIN18 (C/C++)" << RESET << "\n\n";
            std::cout << "  " << BOLD_CYAN << "❯" << RESET << " Press " << BOLD_WHITE << "[ENTER]" << RESET << " to launch search... ";
            std::cin.get();
        }
    };
}