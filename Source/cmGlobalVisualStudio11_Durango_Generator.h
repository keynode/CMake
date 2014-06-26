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

#include "cmGlobalVisualStudio10Generator.h"


/** \class cmGlobalVisualStudio11_Durango_Generator  */
class cmGlobalVisualStudio11_Durango_Generator:
  public cmGlobalVisualStudio10Generator
{
public:
  cmGlobalVisualStudio11_Durango_Generator(const char* name,
    const char* platformName, const char* additionalPlatformDefinition);
  static cmGlobalGeneratorFactory* NewFactory();

  virtual bool MatchesGeneratorName(const char* name) const;

  virtual void WriteSLNHeader(std::ostream& fout);

  ///! create the correct local generator
  virtual cmLocalGenerator *CreateLocalGenerator();

  /** TODO: VS 11 user macro support. */
  virtual std::string GetUserMacrosDirectory() { return ""; }
protected:
	virtual void AddPlatformDefinitions(cmMakefile* mf);

  virtual const char* GetIDEVersion() { return "11.0"; }
  bool UseFolderProperty();

private:
  class Factory;
  friend class Factory;
};
#endif
