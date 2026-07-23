#pragma once
#include <iostream>
#include <string> 
#include <vector>
#include <filesystem>  
#include <sstream>
#include <algorithm> 

namespace algo {
	class FileSearch {
	public : 
		struct FileInfo
		{

			std::wstring filename;  //!use w string casue win has many file name in hind and other language
			std::wstring filepath; // key : 
		};

		
		std::vector<FileInfo> file{};
		std::error_code errorbyfilesystem;

	public: 
		std::vector<FileInfo> storeFile(std::wstring targetFolder) {
			
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

			return file;

		}

		size_t binarySearch(std::wstring fileName, std::vector<FileInfo>file) {
			size_t leftindex{}; // 0 
			size_t rightindex{ file.size() - 1 }; // 9 
			while (leftindex <= rightindex) {
				size_t tempmiddle{ (leftindex + rightindex) / 2 };
				if (fileName == file[tempmiddle].filename) {
					std::cout << "found the file";
					return tempmiddle;

				}else if (file[tempmiddle].filename <  fileName) {  // c < d  
					leftindex = tempmiddle + 1; 

				}
				else {
					rightindex = tempmiddle - 1; 

				}


			}
		} 








	 

	
	


	};

}