#include "Win.h"
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





struct FileInfo
{
	
	std::wstring filename;  //!use w string casue win has many file name in hind and other language
	std::wstring filepath; // key : 
};

bool sortFile(const FileInfo& file1, const FileInfo& file2) {
	// file1 and 2 for comp
	return file1.filename < file2.filename; // if yes then true 

}



int main() {
	std::string targetFolder{};
	std::cout << "User Add The Folder To Scan-";  // -
	std::getline(std::cin, targetFolder);
	std::vector<FileInfo> file{}; //! fileinfo is a vector that contain 2 value name and location
	//! safely report errors 
	std::error_code errorbyfilesystem;
	// how the iterator will work 
	auto option{ std::filesystem::directory_options::skip_permission_denied }; // 
	auto start{ std::filesystem::recursive_directory_iterator(targetFolder , option , errorbyfilesystem) };
	auto end{ std::filesystem::recursive_directory_iterator() }; // ! this is the end point we wan't the start to be like this (mean that all file are pushed)

	while (start != end) {
		// ! if no error find  
		if (!errorbyfilesystem) {

			FileInfo tempFile;
			tempFile.filename = start->path().filename().wstring();
			tempFile.filepath = start->path().wstring();
			file.push_back(tempFile);


		}
		start.increment(errorbyfilesystem); // !just move to the next file if error if no error then it will act Normal 


	}
	if (file.size() == 0) {
		std::cerr << "Error(Use Real File Location)";
	}
	else {
		std::cout << "File Size-" << file.size() << "\n";
		std::sort(file.begin(), file.end(), sortFile);  // ! begin and end a methold that give an object ittrator that point at the begin  and end 
		//! and this sort work in the file vector no need to make new var ect 
		// ? in  this i will add binery search ! 
	
		for (size_t i = 0; i < file.size(); i++) {
			std::wcout << GREEN << "[" << file[i].filename << "]" WHITE << '\n';
		}
		std::cout << "----------------------------------------------------------------------\n";
		std::wstring userGiveFileName{};
		std::wcout << RED << "Enter File Name-" << WHITE;
		// !Use getline so it captures spaces! (std::ws clears any leftover invisible 'Enters')
		std::getline(std::wcin >> std::ws, userGiveFileName);
		 int leftFileIndex{}; // size_t ()  / 
		 int rightFileIndex{ int(file.size()) - 1 };  // this will give me last index 
		 while (leftFileIndex <= rightFileIndex) { // loop need to work till left=right or < to right 
			 int tempMiddle{(leftFileIndex + rightFileIndex) / 2};
			 if (userGiveFileName == file[tempMiddle].filename) {
				 std::wcout << "Found The File" << '\n';
				 std::wcout << "File Path-" << file[tempMiddle].filepath << '\n';
				 winOpenFile(file[tempMiddle].filepath) ? std::cout << "fileopen \n" : std::cout << "not able to open file";
				 break;
			 } 
			 else if (file[tempMiddle].filename < userGiveFileName) { 
				 leftFileIndex = tempMiddle + 1; 
			 }
			 else{
				 rightFileIndex = tempMiddle - 1; 

			 }
		 }

	}


	
	system("pause");
	return 0;

}