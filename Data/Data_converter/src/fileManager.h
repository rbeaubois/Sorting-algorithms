#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileManager
{
private:
	string _filename;
	fstream _file;

	void fileOpen(bool clear = false);
	void fileCreate();
	bool fileExist();
	void fileClose();
	void init();

public:
  FileManager(string filename);
	void updateFileName(string filename);
  	void convert1(FileManager* outputFile);

	string getFileName();


};

#endif
