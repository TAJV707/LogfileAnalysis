#include "Tools.h"
#include <iostream>
Tools::Tools(){
  // constrcutor
}

int Tools::Search(std::string fileData[1000][8],int numCols, std::string header){
  std::cout << "Please choose a search key:" <<    std::endl;
  std::cout << header << std::endl;

  std::string response;
  std::cin >> response;
  int colPrint = -1;
  if(response == "Date"){
    colPrint = 0;
  }else if(response == "ID"){
    colPrint = 1;
  }else if(response == "FirstName"){
    colPrint = 2;
  }else if(response == "LastName"){
    colPrint = 3;
  }else if(response == "Gender"){
    colPrint = 4;
  }else if(response == "Age"){
    colPrint = 5;
  }else if(response == "Salary"){
    colPrint = 6;
  }else{
    std::cout << "Key Not Found" << std::endl;
    return 0;
  }
  std::cout << "Please choose a value key:" << std::endl;
  std::string value;
  std::cin >> value;
  int index = -1;
  for(int j = 0; j < numCols; j++){
    // check
    if(fileData[colPrint][j] == value){
      index = j;
      break;
    }
  }
  // error checking value not found
    if(index == -1){
      std::cout << "Data not found" << std::endl;
      return 0;
    }

    for(int j = 0; j < numCols;j++){
      std::cout << fileData[j][index] << " ";
    }
    std::cout << std::endl;

    // function succeeds in finding data
    return 1;

}
int Tools::Filter(std::string fileData[1000][8],int numCols, std::string header){
  std::cout << "Please choose a search key:" <<    std::endl;
  std::cout << header << std::endl;
  std::string response;
  std::cin >> response;
  int colPrint = -1;
  int r1, r2;
  char j;
  std::string search;
  if(response == "Date"){
    std::cout << "Please enter two years (smaller one first): ";
    std::cin >> r1 >> r2;
    colPrint = 0;
  }else if(response == "ID"){
    std::cout << "Please enter two IDS (smaller one first): ";
    std::cin >> r1 >> r2;
    colPrint = 1;
  }else if(response == "FirstName"){
    std::cout << "Please enter a first name: ";
    std::cin >> search;
    colPrint = 2;
  }else if(response == "LastName"){
    std::cout << "Please enter a last name: ";
    std::cin >> search;
    colPrint = 3;
  }else if(response == "Gender"){
    std::cout << "Please enter a gender (M or F): ";
    std::cin >> search;
    colPrint = 4;
  }else if(response == "Age"){
    std::cout << "Please enter two ages (smaller one first):";
    std::cin >> r1 >> r2;
    colPrint = 5;
  }else if(response == "Salary"){
    std::cout << "Please enter two salaries (smaller one first): ";
    std::cin >> r1 >> r2;
    colPrint = 6;
  }else{
    std::cout << "Key Not Found" << std::endl;
    return 0;
  }
  bool copy;
  for(int j = 0; j < numCols-2; j++){
    copy = false;
    // Filter Date
    if(colPrint == 2 || colPrint == 3 ||colPrint == 4){
      if(fileData[colPrint][j] == search){
        copy = true;
      }
    // Salary, Age, ID, Date, 0,1,5,6
    }else{
      // Converting string to int
      std::string fileString = fileData[colPrint][j];
      int fileInt = std::stoi(fileString);
      if(r1 <= fileInt && fileInt <= r2){
        copy = true;
      }
    }
    // Now copy over the data
    if(copy == true){
       for(int i = 0; i < numCols;i++){
        std::cout << fileData[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }
  // success
  return 1;
}
