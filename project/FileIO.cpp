#include "FileIO.h"
#include <fstream>
#include <string>

FileIO::FileIO(){
  std::string fileData[1000][8];
  numCols = 0;
}
std::string FileIO::getFileName(){
  return fileName;
}
int FileIO::getCols(){
  return numCols;
}
std::string FileIO::getHeader(){
  return header;
}
int FileIO::ReadData(std::string fileName){
  this->fileName = fileName;
  std::ifstream fileInput;
  fileInput.open(fileName);
  std::string temp;
  // Reads in the junk header file
  fileInput >> temp;
  header = temp;
  numCols = 0;
  while(!fileInput.eof()){
    for(int i = 0; i < 7;i++){
      fileInput >> temp;
      if(fileInput.eof()){
        break;
      }
      fileData[i][numCols] = temp;
      }
    numCols++;
  }
  numCols++;
  fileInput.close();
  return 1;
}

void FileIO::SaveData(){
  std::ofstream fileOutput;
  fileOutput.open(fileName);
  fileOutput << header << std::endl;
  for(int i = 0; i < 7;i++){
    for(int j = 0; j < numCols;j++){
      fileOutput << fileData[j][i] << " ";
    }
    fileOutput << std::endl;
  }
  fileOutput.close();

}

void FileIO::WriteData(std::string fileName){
  std::ofstream fileOutput;
  fileOutput.open(fileName);
  fileOutput << header << std::endl;
  for(int i = 0; i < 7;i++){
    for(int j = 0; j < numCols;j++){
      fileOutput << fileData[j][i] << " ";
    }
    fileOutput << std::endl;
  }
  fileOutput.close();
}
