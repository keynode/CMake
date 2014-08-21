/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2000-2011 Kitware, Inc., Insight Software Consortium

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
#include "cmGlobalVisualStudio11_Orbis_Generator.h"
#include "cmLocalVisualStudio10Generator.h"
#include "cmMakefile.h"

static const char vs11_Orbis_generatorName[] = "Visual Studio 11 2012 ORBIS";
static const char vs12_Orbis_generatorName[] = "Visual Studio 12 2013 ORBIS";

//----------------------------------------------------------------------------
static cmVS7FlagTable cm_CLang_ExtraFlagTable[] =
{
	{"OptimizationLevel", "OL0", "No Optimization",       "Level0", 0},
	{"OptimizationLevel", "OL1", "Standard Optimization", "Level1", 0},
	{"OptimizationLevel", "OL2", "Full Optimization",     "Level2", 0},
	{"OptimizationLevel", "OL3", "Full with Inlining Optimization", "Level3", 0},
	{"OptimizationLevel", "OL4", "Optimize for Size",     "Levels", 0},
	{"FastMath", "ffast-math", "Fast Math",     "true", 0},
	{"NoStrictAliasing", "fno-strict-aliasing", "No Strict Aliasing", "true", 0},
	{"UnrollLoops", "funroll-loops", "Unroll Loops", "true", 0},
	{"RuntimeTypeInfo", "fno-rtti", "Enable Run-Time Type Information", "false", 0},
	{"RuntimeTypeInfo", "frtti", "Enable Run-Time Type Information", "true", 0},
	{"GenerateDebugInformation", "g", "Generate Debug Information", "true", 0},

	{0,0,0,0,0}
};

class cmGlobalVisualStudio11_Orbis_Generator::Factory
  : public cmGlobalGeneratorFactory
{
public:
  virtual cmGlobalGenerator* CreateGlobalGenerator(const std::string& name) const
    {
			if (0 == strcmp(name.c_str(),vs11_Orbis_generatorName))
			{
				return new cmGlobalVisualStudio11_Orbis_Generator(name, "ORBIS");
			}
			else
			{
				return 0;
			}
    }

  virtual void GetDocumentation(cmDocumentationEntry& entry) const
    {
    entry.Name = vs11_Orbis_generatorName;
	entry.Brief = std::string("Generates project files for: ") + vs11_Orbis_generatorName;
    }

  virtual void GetGenerators(std::vector<std::string>& names) const
    {
    names.push_back(vs11_Orbis_generatorName);
    }
};

//----------------------------------------------------------------------------
cmGlobalGeneratorFactory* cmGlobalVisualStudio11_Orbis_Generator::NewFactory()
{
  return new Factory;
}

//----------------------------------------------------------------------------
cmGlobalVisualStudio11_Orbis_Generator::cmGlobalVisualStudio11_Orbis_Generator(
  const std::string& name, const std::string& platformName)
  : cmGlobalVisualStudio11Generator(name, platformName)
{
  this->DefaultPlatformToolset = "clang";
}

//----------------------------------------------------------------------------
bool
cmGlobalVisualStudio11_Orbis_Generator::MatchesGeneratorName(const std::string& name) const
{
  return 0 == strcmp(vs11_Orbis_generatorName,name.c_str());
}

//----------------------------------------------------------------------------
cmLocalGenerator *cmGlobalVisualStudio11_Orbis_Generator::CreateLocalGenerator()
{
  cmLocalVisualStudio10Generator* lg =
		new cmLocalVisualStudio10Generator(cmLocalVisualStudioGenerator::VS12);
  lg->SetExtraFlagTable(cm_CLang_ExtraFlagTable);
  lg->SetGlobalGenerator(this);
  return lg;
}

bool cmGlobalVisualStudio11_Orbis_Generator::NeedLinkLibraryDependencies( cmTarget& target )
{
	if (target.GetType() == cmTarget::EXECUTABLE)
	{
		return true;
	}
	return false;
}