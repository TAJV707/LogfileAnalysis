#include <iostream>
#include "GUI.h"
#include "FileIO.h"
#include "Tools.h"

int main() {

  // initiate new user
  GUI* user = new GUI();
  // start function starts program, asks for mode and valid files
  if(!user->Start()){
    exit(0);
  }

  // initiate new file operator
  FileIO* op = new FileIO();
  //user->getFileNames(0);

  // read data from the uploaded file
  // the data is stored in a  member variable inside FileIO operator
  if(!op->ReadData(user->getFileNames(0))){
    std::cout << "FileIO ReadData function failed" << std::endl;
    exit(0);
  }
  Tools* tool = new Tools();

  std::cout << "You have successfully entered data" << std::endl;

  while(1){
    std::string response;
    std::cout << "Would you like to 'Search', 'Sort', 'Filter' or 'Quit'?" <<           std::endl;
    std::cin >> response;
    if(response == "Search"){
      if(!tool->Search(op->fileData,op->getCols(),op->getHeader())){
        continue;
      }
    }
    else if(response == "Filter"){
       if(!tool->Filter(op->fileData,op->getCols(),op->getHeader())){
         continue;
       }
    }else if(response == "Quit"){
      std::cout << "Goodbye, thank you for using our program" << std::endl;
      exit(0);
    }
    else{
      std::cout << "This functionality is not yet implemented" << std::endl;
    }
  }

  op->WriteData("help.csv");


}
