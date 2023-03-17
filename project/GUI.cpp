#include "GUI.h"

GUI::GUI(){
  std::string fileNames[100];
  int numFiles = 1;
}

// function to start program -- input mode and files
int GUI::Start(){
  std::cout << "Welcome to the Logfile Analysis Framework" << std::endl;
  char mode;
  std::cout << "Would you like to use Batch (B) or Interactive (I) Mode" <<            std::endl;
  std::cin >> mode;
  if (mode == 'B'){
    std::cout << "This functionality is not yet implemented, exiting program" <<         std::endl;
    return 0;
  }else{
    // interactive mode
    numFiles = 1;
  }
  // loop to upload multiple files (Batch mode)
  // this functionality will be implemented in a later version of Loafr
  for(int i = 0; i < numFiles; i++ ){
    std::string tempFileName;
    // loop to make sure the file is valid
    while(1){
      std::cout << "Please enter valid file name" << std::endl;
      std::cin >> tempFileName;
      std::ifstream fileInput(tempFileName);
      if(fileInput){
        fileNames[i] = tempFileName;
        break;
      }
    }
  }
  return 1;
}

int GUI::getNumFiles(){
  return numFiles;
}

std::string GUI::getFileNames(int index){
  return fileNames[index];
}

// exit program
void GUI::Quit(){
  exit(0);
}
