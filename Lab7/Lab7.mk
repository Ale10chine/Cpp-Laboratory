##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lab7
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/alex1/Codlite_workspace/Codlite_workspace
ProjectPath            :=C:/Users/alex1/Codlite_workspace/Codlite_workspace/Lab7
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/Lab7
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=alex1
Date                   :=07/01/2023
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
Objects0=$(IntermediateDirectory)/Tester.cpp$(ObjectSuffix) $(IntermediateDirectory)/Maze.cpp$(ObjectSuffix) $(IntermediateDirectory)/RandomRobot.cpp$(ObjectSuffix) $(IntermediateDirectory)/MatrixPosition.cpp$(ObjectSuffix) $(IntermediateDirectory)/RightHandRuleRobot.cpp$(ObjectSuffix) 



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
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/alex1/Codlite_workspace/Codlite_workspace/Lab7/Tester.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Tester.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Tester.cpp$(DependSuffix): Tester.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Tester.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Tester.cpp$(DependSuffix) -MM Tester.cpp

$(IntermediateDirectory)/Tester.cpp$(PreprocessSuffix): Tester.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Tester.cpp$(PreprocessSuffix) Tester.cpp

$(IntermediateDirectory)/Maze.cpp$(ObjectSuffix): Maze.cpp $(IntermediateDirectory)/Maze.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/alex1/Codlite_workspace/Codlite_workspace/Lab7/Maze.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Maze.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Maze.cpp$(DependSuffix): Maze.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Maze.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Maze.cpp$(DependSuffix) -MM Maze.cpp

$(IntermediateDirectory)/Maze.cpp$(PreprocessSuffix): Maze.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Maze.cpp$(PreprocessSuffix) Maze.cpp

$(IntermediateDirectory)/RandomRobot.cpp$(ObjectSuffix): RandomRobot.cpp $(IntermediateDirectory)/RandomRobot.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/alex1/Codlite_workspace/Codlite_workspace/Lab7/RandomRobot.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RandomRobot.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RandomRobot.cpp$(DependSuffix): RandomRobot.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RandomRobot.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RandomRobot.cpp$(DependSuffix) -MM RandomRobot.cpp

$(IntermediateDirectory)/RandomRobot.cpp$(PreprocessSuffix): RandomRobot.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RandomRobot.cpp$(PreprocessSuffix) RandomRobot.cpp

$(IntermediateDirectory)/MatrixPosition.cpp$(ObjectSuffix): MatrixPosition.cpp $(IntermediateDirectory)/MatrixPosition.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/alex1/Codlite_workspace/Codlite_workspace/Lab7/MatrixPosition.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MatrixPosition.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MatrixPosition.cpp$(DependSuffix): MatrixPosition.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MatrixPosition.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MatrixPosition.cpp$(DependSuffix) -MM MatrixPosition.cpp

$(IntermediateDirectory)/MatrixPosition.cpp$(PreprocessSuffix): MatrixPosition.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MatrixPosition.cpp$(PreprocessSuffix) MatrixPosition.cpp

$(IntermediateDirectory)/RightHandRuleRobot.cpp$(ObjectSuffix): RightHandRuleRobot.cpp $(IntermediateDirectory)/RightHandRuleRobot.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/alex1/Codlite_workspace/Codlite_workspace/Lab7/RightHandRuleRobot.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RightHandRuleRobot.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RightHandRuleRobot.cpp$(DependSuffix): RightHandRuleRobot.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RightHandRuleRobot.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RightHandRuleRobot.cpp$(DependSuffix) -MM RightHandRuleRobot.cpp

$(IntermediateDirectory)/RightHandRuleRobot.cpp$(PreprocessSuffix): RightHandRuleRobot.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RightHandRuleRobot.cpp$(PreprocessSuffix) RightHandRuleRobot.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


