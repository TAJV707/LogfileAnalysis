#pragma once
#include "GUI.h"

class Tools : public GUI{
  public:
    Tools();
    int Search(std::string fileData[1000][8],int     numCols, std::string header);
    int Filter(std::string fileData[1000][8],int     numCols,     std::string header);
  protected:
    std::string fileName;

};
