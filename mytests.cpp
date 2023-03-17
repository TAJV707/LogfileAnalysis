#include <gtest/gtest.h>
#include "project/GUI.h"
#include "project/GUI.cpp"
#include "project/FileIO.h"
#include "project/FileIO.cpp"
#include "project/Tools.h"
#include "project/Tools.cpp"

class GUITest : public ::testing::Test {
  void SetUp(){  }
  void TearDown(){  }
};

// tests the start function of the GUI class
// should ask for a file, and if the file is valid, should return 1
// if file is invalid, test will fail
TEST_F(GUITest, StartTestWithValidFile) {
  GUI* user = new GUI();
  GTEST_ASSERT_EQ(user->Start(), 1);
  delete user;
}
// test for getFileNames() function
TEST_F(GUITest, GetFileNamesTest){
  GUI* user = new GUI();
  user->Start();
  GTEST_ASSERT_EQ(user->getFileNames(0), "LogFile.csv");
  delete user;
}

////////////////////////////////////////////////////////////////////////////////

class FileIOTest : public ::testing::Test {
  void SetUp(){  }
  void TearDown(){  }
};
// file IO constructor test, also test the function getCols()
TEST_F(FileIOTest, ConstructorTest){
  FileIO* op = new FileIO();
  // maybe check file data
  GTEST_ASSERT_EQ(op->getCols(), 0);
  delete op;
}
// ReadData function test
TEST_F(FileIOTest, ReadDataTest){
  FileIO* op = new FileIO();
  GTEST_ASSERT_EQ(op->ReadData("LogFile.csv"), 1);
  GTEST_ASSERT_EQ(op->getFileName(), "LogFile.csv");
  // check file data
  delete op;
}

////////////////////////////////////////////////////////////////////////////////

class ToolsTest : public ::testing::Test {
  void SetUp(){  }
  void TearDown(){  }
};
// test the search function in Tools class
// easiest way to do this is by setting up a user and FileIO operator
// assumes valid file name, search key, and value key
TEST_F(ToolsTest, SearchTest){
  GUI* user = new GUI();
  user->Start();
  FileIO* op = new FileIO();
  op->ReadData(user->getFileNames(0));
  Tools* tool = new Tools();
  GTEST_ASSERT_EQ(tool->Search(op->fileData,op->getCols(),op->getHeader()), 1);
  delete user;
  delete op;
  delete tool;
}
// test filter function, very similar to search test
TEST_F(ToolsTest, FilterTest){
  GUI* user = new GUI();
  user->Start();
  FileIO* op = new FileIO();
  op->ReadData(user->getFileNames(0));
  Tools* tool = new Tools();
  GTEST_ASSERT_EQ(tool->Filter(op->fileData,op->getCols(),op->getHeader()), 1);
  delete user;
  delete op;
  delete tool;
}

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
