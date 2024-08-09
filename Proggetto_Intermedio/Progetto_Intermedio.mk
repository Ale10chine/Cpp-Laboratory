##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Progetto_Intermedio
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/alex1/Codlite_workspace/Codlite_workspace
ProjectPath            :=C:/Users/alex1/Codlite_workspace/Codlite_workspace/Proggetto_Intermedio
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/Proggetto_Intermedio
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=alex1
Date                   :=22/12/2022
CodeLitePath           :="C:/Program Files/CodeLite"
MakeDirCommand         :=mkdir
LinkerName             :=C:/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=C:/Users/alex1/Codlite_workspace/Codlite_workspace/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\build-$(WorkspaceConfiguration)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/mingw64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/mingw64/bin/ar.exe rcu
CXX      := C:/mingw64/bin/g++.exe
CC       := C:/mingw64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/Tester.cpp$(ObjectSuffix) $(IntermediateDirectory)/Book.cpp$(ObjectSuffix) $(IntermediateDirectory)/Date.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@if not exist "$(OutputDirectory)" $(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Tester.cpp$(ObjectSuffix): Tester.cpp $(IntermediateDirectory)/Tester.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/alex1/Codlite_workspace/Codlite_workspace/Proggetto_Intermedio/Tester.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Tester.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Tester.cpp$(DependSuffix): Tester.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Tester.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Tester.cpp$(DependSuffix) -MM Tester.cpp

$(IntermediateDirectory)/Tester.cpp$(PreprocessSuffix): Tester.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Tester.cpp$(PreprocessSuffix) Tester.cpp

$(IntermediateDirectory)/Book.cpp$(ObjectSuffix): Book.cpp $(IntermediateDirectory)/Book.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/alex1/Codlite_workspace/Codlite_workspace/Proggetto_Intermedio/Book.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Book.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Book.cpp$(DependSuffix): Book.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Book.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Book.cpp$(DependSuffix) -MM Book.cpp

$(IntermediateDirectory)/Book.cpp$(PreprocessSuffix): Book.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Book.cpp$(PreprocessSuffix) Book.cpp

$(IntermediateDirectory)/Date.cpp$(ObjectSuffix): Date.cpp $(IntermediateDirectory)/Date.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/alex1/Codlite_workspace/Codlite_workspace/Proggetto_Intermedio/Date.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Date.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Date.cpp$(DependSuffix): Date.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Date.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Date.cpp$(DependSuffix) -MM Date.cpp

$(IntermediateDirectory)/Date.cpp$(PreprocessSuffix): Date.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Date.cpp$(PreprocessSuffix) Date.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


