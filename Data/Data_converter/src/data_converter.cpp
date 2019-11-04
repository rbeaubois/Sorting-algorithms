#include <string>
#include <fstream>
#include <iostream>
#include "fileManager.h"

using namespace std;

int main() {


  string inputFile_name;
  string outputFile_name;

  cout << "File to convert ?" << endl;
  getline(cin, inputFile_name);

  outputFile_name = inputFile_name + "_RAM_FPGA.txt";

  class FileManager *inputFile = new FileManager(inputFile_name);
  class FileManager *outputFile = new FileManager(outputFile_name);

  inputFile->convert1(outputFile);

  return 0;
}
