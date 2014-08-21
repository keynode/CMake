/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2000-2011 Kitware, Inc., Insight Software Consortium

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
#ifndef cmGlobalVisualStudio11_Durango_Generator_h
#define cmGlobalVisualStudio11_Durango_Generator_h

#include "cmGlobalVisualStudio11Generator.h"

class cmGlobalVisualStudio11_Durango_Generator :  public cmGlobalVisualStudio11Generator
{
public:
  cmGlobalVisualStudio11_Durango_Generator(const std::string& name, const std::string& platformName) : cmGlobalVisualStudio11Generator(name, platformName) {}
  static cmGlobalGeneratorFactory* NewFactory();

  virtual bool MatchesGeneratorName(const std::string& name) const;

private:
  class Factory;
  friend class Factory;
};
#endif
