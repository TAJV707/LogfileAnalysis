#pragma once
#include "GUI.h"
#include <fstream>
#include <string>

class FileIO : public GUI{
  public:
    FileIO();
    int ReadData(std::string fileName);
    void SaveData();
    void WriteData(std::string fileName);
    std::string fileData[1000][8];
    int getCols();
    std::string getHeader();
    std::string getFileName();
  protected:
    std::string fileName;
    std::string header;
    int numCols;
};
