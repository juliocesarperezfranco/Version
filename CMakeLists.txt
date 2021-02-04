CMAKE_MINIMUM_REQUIRED(3.15)
PROJECT(LibVersion VERSION 1.0.0.0 DESCRIPTION "Simple versioning library")

SET(LibVersionHeaders
  src/VersionInfo.h
  src/Version.h
)

SET(LibVersionSources
  src/Version.cxx
)

SET(LibVersionSources ${LibVersionHeaders} ${LibVersionSources})
ADD_LIBRARY(LibVersion ${LibVersionSources})

SET_TARGET_PROPERTIES(LibVersion PROPERTIES
  OUTPUT_NAME "LibVersion"
  DEBUG_POSTFIX "D"
)
