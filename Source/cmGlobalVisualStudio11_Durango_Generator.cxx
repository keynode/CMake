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

static const char vs11_durango_generatorName[] = "Visual Studio 11 2012 Durango";

class cmGlobalVisualStudio11_Durango_Generator::Factory
  : public cmGlobalGeneratorFactory
{
public:
  virtual cmGlobalGenerator* CreateGlobalGenerator(const char* name) const
    {
			if (0 == strcmp(name,vs11_durango_generatorName))
			{
				return new cmGlobalVisualStudio11_Durango_Generator(name, "Durango", NULL);
			}
			else
			{
				return 0;
			}
    }

  virtual void GetDocumentation(cmDocumentationEntry& entry) const
    {
    entry.Name = vs11_durango_generatorName;
    entry.Brief = "Generates Visual Studio 11 (2012) Durango (Xbox One) project files.";
    }

  virtual void GetGenerators(std::vector<std::string>& names) const
    {
    names.push_back(vs11_durango_generatorName);
    }
};

//----------------------------------------------------------------------------
cmGlobalGeneratorFactory* cmGlobalVisualStudio11_Durango_Generator::NewFactory()
{
  return new Factory;
}

//----------------------------------------------------------------------------
cmGlobalVisualStudio11_Durango_Generator::cmGlobalVisualStudio11_Durango_Generator(
  const char* name, const char* platformName,
  const char* additionalPlatformDefinition)
  : cmGlobalVisualStudio10Generator(name, platformName,
                                   additionalPlatformDefinition)
{
  std::string vc11Express;
  this->ExpressEdition = false;
  this->PlatformToolset = "v110";
}

//----------------------------------------------------------------------------
bool
cmGlobalVisualStudio11_Durango_Generator::MatchesGeneratorName(const char* name) const
{
  return 0 == strcmp(vs11_durango_generatorName,name);
}

//----------------------------------------------------------------------------
void cmGlobalVisualStudio11_Durango_Generator::WriteSLNHeader(std::ostream& fout)
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
cmLocalGenerator *cmGlobalVisualStudio11_Durango_Generator::CreateLocalGenerator()
{
  cmLocalVisualStudio10Generator* lg =
    new cmLocalVisualStudio10Generator(cmLocalVisualStudioGenerator::VS11);
  lg->SetPlatformName(this->GetPlatformName());
  lg->SetGlobalGenerator(this);
  return lg;
}

//----------------------------------------------------------------------------
bool cmGlobalVisualStudio11_Durango_Generator::UseFolderProperty()
{
  // Intentionally skip over the parent class implementation and call the
  // grand-parent class's implementation. Folders are not supported by the
  // Express editions in VS10 and earlier, but they are in VS11 Express.
  return cmGlobalVisualStudio8Generator::UseFolderProperty();
}

//////////////////////////////////////////////////////////////////////////
void cmGlobalVisualStudio11_Durango_Generator::AddPlatformDefinitions( cmMakefile* mf )
{
	//mf->AddDefinition( "CMAKE_TOOLCHAIN_FILE","cmake/toolchain-durango.cmake" );
	cmGlobalVisualStudio10Generator::AddPlatformDefinitions(mf);
}
