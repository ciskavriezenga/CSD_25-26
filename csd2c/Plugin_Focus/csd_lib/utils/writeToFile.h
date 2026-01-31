#pragma once

#include <fstream>
#include <iostream>
#include <memory>
#include <sys/stat.h>

class WriteToFile {
public:
  WriteToFile (const std::string& fileName, bool overwrite = false);
  ~WriteToFile();

  bool write (const std::string& text);

private:
  bool fileExists (const std::string& fileName);
  bool openFile (const std::string& fileName);
  std::ofstream file;
};
