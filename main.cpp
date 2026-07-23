#include "Win.h"
#include "algo.h"
#include <string> 
#include <vector>
#include <filesystem>  
#include <sstream>
#include <algorithm> 

#define RESET  "\033[0m"  
#define RED    "\033[31m"
#define GREEN  "\033[32m"
#define YELLOW "\033[33m"
#define BLUE   "\033[34m"
#define WHITE  "\033[37m"


algo::FileSearch algogetfilelogic;


bool sortFile(const algo::FileSearch::FileInfo& file1, const algo::FileSearch::FileInfo& file2) {
	// file1 and 2 for comp
	// ! algo::FileSearch::FileInfo why i am using this cause if i use algogetfilelogic it will give error cause c++ is very strict to make the diff b/w 
	// ! obj and the blueprints eparate when defining a function's parameters 
	// ? Because FileInfo is a type definition, we cannot use the dot (.) with the object name. We must use the scope resolution operator (::) with the class name itself.
	return file1.filename < file2.filename; // if yes then true 

}


int main() {
	std::wstring targetFolder{};
	std::cout << "User Add The Folder To Scan-";  // -
	std::getline(std::wcin, targetFolder);
	std::vector foundfiles{ algogetfilelogic.storeFile(targetFolder)};
	if (foundfiles.size() == 0) {
		std::cerr << RED<< "error no file found" << GREEN;
	}
	else {
		std::cout << foundfiles.size() << '\n';
		std::sort(foundfiles.begin() , foundfiles.end() , sortFile);
		std::cout << "sort is done\n" ; 
		std::wstring usergivenfilename{};
		std::cout << "Enter File NAME -";
		std::getline(std::wcin ,usergivenfilename );
		size_t userfileindex{algogetfilelogic.binarySearch(usergivenfilename , foundfiles)};
		std::cout << "\nNumber-" << userfileindex << '\n';
		winOpenFile(foundfiles[userfileindex].filepath);
	


	}
	

	
	system("pause");
	return 0;

}