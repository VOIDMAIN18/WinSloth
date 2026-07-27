#include "Win.h"
#include "algo.h"
#include "console.h"
#include <string> 
#include <vector>
#include <filesystem>  
#include <sstream>
#include <algorithm> 
#include <conio.h> // for ui of fuzzy finder and header file provided by Microsoft

#define LOG_SYSTEM 

// ! all the var 
std::wstring usergivenfilename{};
std::vector<algo::FileSearch::FileInfo>currectmatch{};



algo::FileSearch algogetfilelogic;
consoleui::MainUiStart consoleUi;


bool sortFile(const algo::FileSearch::FileInfo& file1, const algo::FileSearch::FileInfo& file2) {
	// file1 and 2 for comp
	// ! algo::FileSearch::FileInfo why i am using this cause if i use algogetfilelogic it will give error cause c++ is very strict to make the diff b/w 
	// ! obj and the blueprints eparate when defining a function's parameters 
	// ? Because FileInfo is a type definition, we cannot use the dot (.) with the object name. We must use the scope resolution operator (::) with the class name itself.
	return file1.filename < file2.filename; // if yes then true 

}


int main() {
	consoleUi.openwin();
#ifdef  LOG_SYSTEM
	std::wclog << GREEN << "LOG-Now Running SearchDriveFunc\n" << RESET;
#endif 
	std::vector <std::wstring> totalDrivers{ algogetfilelogic.searchDrive() };
	if (totalDrivers.size() > 1) {
		std::cout << "Drivers more then 1";
	}
	else {
		std::wcout << " Only 1 Drive Found \n";
		std::wstring targetFolder{ totalDrivers[0] };
#ifdef LOG_SYSTEM 
		std::wclog << GREEN << "LOG-Now Running StoreFileFunc\n" << RESET;
#endif 

		std::vector foundfiles{ algogetfilelogic.storeFile(targetFolder) };

#ifdef  LOG_SYSTEM
		std::wclog << GREEN << "LOG-Now Done StoreFileFunc\n" << RESET;
#endif 

		std::sort(foundfiles.begin(), foundfiles.end(), sortFile);
#ifdef  LOG_SYSTEM
		std::wclog << GREEN << "LOG-Now Done STD::SORT\n" << RESET;
#endif 
		if (foundfiles.size() == 0) {
			std::cerr << RED << " Error No File Found" << GREEN;
		}
		else {
			std::cout << " " << foundfiles.size() << '\n';
			std::clog << " File scan is done" << '\n';
			Sleep(2000);
			system("cls");
			std::cout  << RED << "PRESS ANY KEY TO START SEARCH !"  << std::endl<< RESET;

			//fuzzy finder
			while (true) { //  it is re taking the value that the user given file name and then char by char 
				wchar_t key{ static_cast<wchar_t>(_getch()) }; // in  this it will give error cause _getch is a int and if i try to store it in wchar which is small it will give error 
				// to fix it i will convert it into wchar using casting 
				if (key == 27) { // esc key 
					std::cout << RED << "EXIT\n" << WHITE;
					break;
				}
				else {
					// 1 if the user is giving  /r or /t 
					if (key > 31) { // till 32 to 126 this is all visible keys 
						usergivenfilename += key; // 
						std::wcout << L"Search:" << usergivenfilename << L"\n\n";
						currectmatch = algogetfilelogic.fuzzyFinder(usergivenfilename, foundfiles);
						// ! THIS IS FOR print only 
						system("cls");
						for (size_t i{}; i < currectmatch.size() && i < 10; i++) { // ! the error way it was cou till 10 
							std::wcout << L"[" << GREEN << "(" << i << ")" << RED << currectmatch[i].filename << RED << "]" << L"\n\n";

						}

					}
					else if (key == 13) {


						if (!currectmatch.empty()) {
							winOpenFile(currectmatch[0].filepath);
						}
					}

				}

			}



















		}

	}








	system("pause");
	return 0;

}