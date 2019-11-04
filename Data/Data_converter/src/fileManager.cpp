#include "fileManager.h"

#define FILE_CLEAR 		true
#define VALUES_PER_LINE	10
#define ARRAY_SIZE		64000

FileManager::FileManager(string filename) {
	_filename = filename;
	init();
}

void FileManager::init() {
	if (!fileExist())
		fileCreate();
	fileOpen();
	fileClose();
	cout << "File Manager initialized correctly with \"" << _filename << "\" file." << endl;
}

void FileManager::updateFileName(string filename) {
	_filename = filename;
	init();
}

void FileManager::fileOpen(bool clear) {
	try {

		if (clear)
			_file.open(_filename, ofstream::out | ofstream::trunc); // Clear all the content of the file
		else
			_file.open(_filename);

		if (!_file.is_open()) {
			cout << "Error when opening file, is the file available ?" << endl;
			exit(1);//Erreur fatale pour le moment
		}

	} catch (...) {
		cout << "Error when opening file." << endl;
		exit(0);
	}
}

void FileManager::fileCreate() {

	cout << "Creation of the file ... " << endl;

	try {

		ofstream createdFile;
		createdFile.open(_filename);
		createdFile.close();

	} catch (...) {
		cout << "File creation error." << endl;
		exit(0);
	}

}

void FileManager::fileClose() {
	_file.close();
}

bool FileManager::fileExist() {

	if (_filename.empty()) {
		cout << "Please type a valid name." << endl;
		exit(0); //Erreur fatale pour le moment
	}

	_file.open(_filename);

	if (!_file.is_open()) {
		cout << "File don't exist yet." << endl;
		return false;
	}

	_file.close();
	return true;
}



void FileManager::convert1(FileManager* outputFile) {
  int c = 0;
  int e = 0;

  if (fileExist()) {
		fileOpen();
	} else {
		cout << "Error FileManager LOAD : file don't exist." << endl;
		exit(0);
	}

	if (outputFile->fileExist()) {
		outputFile->fileOpen(FILE_CLEAR); // Open and clear all the content of the file
	} else {
		cout << "Error FileManager SAVE : file don't exist, or error in file saving." << endl;
		exit(0);
	}

	outputFile->_file << '{';
	while (e!=ARRAY_SIZE) {
		string tmp;
		string buf;
		
		c++;
		e++;
		_file >> tmp;
		outputFile->_file << "x\"" + tmp + "\"";
		if(e!=ARRAY_SIZE){
			outputFile->_file << ',';
		}
		if(c==VALUES_PER_LINE){
			c = 0;
			outputFile->_file << endl;
		}
		tmp.clear();
	}
	outputFile->_file << '}';
  
  cout << "Conv saved into file \"" << outputFile->getFileName() << "\"." << endl;
  fileClose();
  outputFile->fileClose();
}

string FileManager::getFileName() {
	return _filename;
}
