#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <stdio.h>


class GUI{
  public:
    GUI();
    int Start();
    void Quit();
    int getNumFiles();
    std::string getFileNames(int index);
  private:
    // array to store files
    std::string fileNames[100];
    int numFiles;

};
