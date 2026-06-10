#include <iostream>
#include <string> 
#include <vector>
#include <filesystem>
#include <sstream>


struct FileInfo
{
	std::wstring filename;  // use w string casue win has many file name in hind and other language
	std::wstring filepath;


};




int main() {
	std::string targetFolder{};
	std::cout << "User Add The Folder To Scan-";  // -
	std::getline(std::cin, targetFolder);
	std::vector<FileInfo> file{};
	//! safely report errors 
	std::error_code errorbyfilesystem;
	// how the iterator will work 
	auto option{ std::filesystem::directory_options::skip_permission_denied };
	auto start{ std::filesystem::recursive_directory_iterator(targetFolder , option , errorbyfilesystem) };
	auto end{ std::filesystem::recursive_directory_iterator() }; // ! this is the end point we wan't the start to be like this (mean that all file are pushed)

	while (start != end) {
		// ! if no error find  
		if (!errorbyfilesystem) {

			FileInfo tempFile;
			tempFile.filename = start->path().filename().wstring();   // 
			tempFile.filepath = start->path().wstring();
			file.push_back(tempFile);


		}
		start.increment(errorbyfilesystem);


	}

	std::cout << "File Size-" << file.size();

	system("pause");

	return 0;

}