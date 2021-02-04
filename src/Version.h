#pragma once

#include "VersionInfo.h"

/**
 * \class Version
 * \brief Class that can hold and make operations to a VersionInfo struct.
 */
class Version
{
  public:
    Version(unsigned int major, unsigned int minor, unsigned int build, unsigned int patch);
    Version(VersionInfo version);
    Version();
    ~Version();

  private:
    VersionInfo   m_versionInfo; // Field that holds the version information.
    unsigned char m_tag;         // Utility field to group versions.

  public:
    void SetVersion(unsigned int major, unsigned int minor, unsigned int build, unsigned int patch);
    void SetVersion(std::string versionString);
    std::string ToString();
};
