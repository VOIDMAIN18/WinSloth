#include "Win.h"
#include "algo.h"
#include "console.h"
#include <string> 
#include <vector>
#include <filesystem>  
#include <sstream>
#include <algorithm> 
#include <conio.h> // for ui of fuzzy finder and header file provided by Microsoft

#define RESET  "\033[0m"  
#define RED    "\033[31m"
#define GREEN  "\033[32m"
#define YELLOW "\033[33m"
#define BLUE   "\033[34m"
#define WHITE  "\033[37m"


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
	std::wstring targetFolder{};
	std::cout << "User Add The Folder To Scan-";  // -
	std::getline(std::wcin, targetFolder);
	std::vector foundfiles{ algogetfilelogic.storeFile(targetFolder)};
	if (foundfiles.size() == 0) {
		std::cerr << RED<< "error no file found" << GREEN;
	}
	else {
		std::cout << foundfiles.size() << '\n';

		std::wstring usergivenfilename{};
		//fuzzy finder
		while (true) {
			wchar_t key{ static_cast<wchar_t>(_getch()) }; // in  this it will give error cause _getch is a int and if i try to store it in wchar which is small it will give error 
			// to fix it i will convert it into wchar using casting 
			if (key == 13) { // enter key 
				std::cout <<RED<< "EXIT\n" << WHITE;
				break;

			}
			else {
				usergivenfilename += key; 
				system("cls"); // !  just for test 
				std::wcout << L"Search:" << usergivenfilename << L"\n\n";
				std::vector<algo::FileSearch::FileInfo>currectmatch{ algogetfilelogic.fuzzyFinder(usergivenfilename , foundfiles) };
				for (size_t i{}; i < currectmatch.size(); i++) {
					std::wcout << L"[" << GREEN <<  "(" << i << ")" << RED << currectmatch[i].filename << RED << "]" << L"\n\n";
					




				}
				 


			




				
			}

		}
	
		


	


	}
	

	
	system("pause");
	return 0;

}