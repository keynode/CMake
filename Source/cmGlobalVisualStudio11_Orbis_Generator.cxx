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
  virtual cmGlobalGenerator* CreateGlobalGenerator(const char* name) const
    {
			if (0 == strcmp(name,vs11_Orbis_generatorName))
			{
				return new cmGlobalVisualStudio11_Orbis_Generator(name, "ORBIS", NULL);
			}
			else
			{
				return 0;
			}
    }

  virtual void GetDocumentation(cmDocumentationEntry& entry) const
    {
    entry.Name = vs11_Orbis_generatorName;
    entry.Brief = "Generates Visual Studio 11 (2012) ORBIS (PS4) project files.";
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
  const char* name, const char* platformName,
  const char* additionalPlatformDefinition)
  : cmGlobalVisualStudio10Generator(name, platformName,
                                   additionalPlatformDefinition)
{
  std::string vc11Express;
  this->ExpressEdition = false;
  this->PlatformToolset = "clang";
}

//----------------------------------------------------------------------------
bool
cmGlobalVisualStudio11_Orbis_Generator::MatchesGeneratorName(const char* name) const
{
  return 0 == strcmp(vs11_Orbis_generatorName,name);
}

//----------------------------------------------------------------------------
void cmGlobalVisualStudio11_Orbis_Generator::WriteSLNHeader(std::ostream& fout)
{
  fout << "Microsoft Visual Studio Solution File, Format Version 12.00\n";
  if (this->ExpressEdition)
    {
    fout << "# Visual Studio Express 2012 for Windows Desktop\n";
    }
  else
    {
    fout << "# Visual Studio 2012\n";
    }
}

//----------------------------------------------------------------------------
cmLocalGenerator *cmGlobalVisualStudio11_Orbis_Generator::CreateLocalGenerator()
{
  cmLocalVisualStudio10Generator* lg =
    new cmLocalVisualStudio10Generator(cmLocalVisualStudioGenerator::VS11);
  lg->SetPlatformName(this->GetPlatformName());
	lg->SetExtraFlagTable(cm_CLang_ExtraFlagTable);
  lg->SetGlobalGenerator(this);
  return lg;
}

//----------------------------------------------------------------------------
bool cmGlobalVisualStudio11_Orbis_Generator::UseFolderProperty()
{
  // Intentionally skip over the parent class implementation and call the
  // grand-parent class's implementation. Folders are not supported by the
  // Express editions in VS10 and earlier, but they are in VS11 Express.
  return cmGlobalVisualStudio8Generator::UseFolderProperty();
}

//////////////////////////////////////////////////////////////////////////
void cmGlobalVisualStudio11_Orbis_Generator::AddPlatformDefinitions( cmMakefile* mf )
{
	//mf->AddDefinition( "CMAKE_TOOLCHAIN_FILE","cmake/toolchain-orbis.cmake" );
	cmGlobalVisualStudio10Generator::AddPlatformDefinitions(mf);
}

bool cmGlobalVisualStudio11_Orbis_Generator::NeedLinkLibraryDependencies( cmTarget& target )
{
	if (target.GetType() == cmTarget::EXECUTABLE)
	{
		return true;
	}
	return false;
}