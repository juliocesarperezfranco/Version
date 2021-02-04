#include "Version.h"

#include <vector>
#include <iostream>
#include <sstream>
#include <iostream>
#include <stdexcept>

Version::Version(unsigned int major, unsigned int minor, unsigned int build, unsigned int patch)
{
  SetVersion(major, minor, build, patch);
};

Version::Version(VersionInfo version)
{
  SetVersion(version.major, version.minor, version.build, version.patch);
};

Version::Version()
{
  SetVersion(0, 0, 0, 0);
};

Version::~Version()
{
};

void Version::SetVersion(unsigned int major, unsigned int minor, unsigned int build, unsigned int patch)
{
  this->m_versionInfo.major = major;
  this->m_versionInfo.major = minor;
  this->m_versionInfo.major = build;
  this->m_versionInfo.major = patch;
};

void Version::SetVersion(std::string versionString)
{
  this->SetVersion(0, 0, 0, 0); // This is the default value.
  std::stringstream ss(versionString);
  std::string item;
  std::vector<std::string> splittedStrings;
  while (std::getline(ss, item, '.'))
  {
    splittedStrings.push_back(item);
  }

  if(splittedStrings.size() < 1 || splittedStrings.size() > 4) // If the number of items is out of range, we throw an exception.
  {
    throw std::runtime_error("Invalid number of values: " + std::to_string(splittedStrings.size()) + ", string: " + versionString);
    return;
  }

  unsigned int counter = 0;
  int currentValue     = 0;
  for(auto it : splittedStrings)
  {
    try
    {
      currentValue = std::stoi(it);
    }
    catch(std::exception& e) // An invalid character found.
    {
      throw std::runtime_error("Invalid value at position " + std::to_string(counter) + ": " + it);
      currentValue = 0;
    }
    
    if(currentValue < 0) // Only unsigned values.
    {
      throw std::runtime_error("Negative value at position " + std::to_string(counter) + ": " + it);
    }

    switch(counter)
    {
      case 0:
      {
        this->m_versionInfo.major = currentValue;
      }
      case 1:
      {
        this->m_versionInfo.minor = currentValue;
      }
      case 2:
      {
        this->m_versionInfo.build = currentValue;
      }
      case 3:
      {
        this->m_versionInfo.patch = currentValue;
      }
      default:
      {
      }
    }
    counter++;
  }
};

std::string Version::ToString()
{
  auto result = std::to_string(this->m_versionInfo.major) + "." + std::to_string(this->m_versionInfo.minor) + "." + std::to_string(this->m_versionInfo.build) + "." + std::to_string(this->m_versionInfo.patch);
  return result;
};
