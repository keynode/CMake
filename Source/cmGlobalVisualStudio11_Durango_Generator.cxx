/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2000-2011 Kitware, Inc., Insight Software Consortium

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
#include "cmGlobalVisualStudio11_Durango_Generator.h"
#include "cmLocalVisualStudio10Generator.h"
#include "cmMakefile.h"

static const char durango_generatorName[] = "Visual Studio 11 2012 Durango";

class cmGlobalVisualStudio11_Durango_Generator::Factory
  : public cmGlobalGeneratorFactory
{
public:
  virtual cmGlobalGenerator* CreateGlobalGenerator(const std::string& name) const
    {
			if (0 == strcmp(name.c_str(),durango_generatorName))
			{
				return new cmGlobalVisualStudio11_Durango_Generator(name, "Durango", "");
			}
			else
			{
				return 0;
			}
    }

  virtual void GetDocumentation(cmDocumentationEntry& entry) const
    {
    entry.Name = durango_generatorName;
	entry.Brief = std::string("Generates project files for: ") + durango_generatorName;
    }

  virtual void GetGenerators(std::vector<std::string>& names) const
    {
    names.push_back(durango_generatorName);
    }
};

//----------------------------------------------------------------------------
cmGlobalGeneratorFactory* cmGlobalVisualStudio11_Durango_Generator::NewFactory()
{
  return new Factory;
}

//----------------------------------------------------------------------------
bool
cmGlobalVisualStudio11_Durango_Generator::MatchesGeneratorName(const std::string& name) const
{
  return 0 == strcmp(durango_generatorName,name.c_str());
}
