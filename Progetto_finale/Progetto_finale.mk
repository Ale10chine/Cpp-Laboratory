##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Progetto_Finale
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/alex1/Codlite_workspace/Codlite_workspace
ProjectPath            :=C:/Users/alex1/Codlite_workspace/Codlite_workspace/Progetto_finale
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/Progetto_finale
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=alex1
Date                   :=01/08/2023
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
Objects0=$(IntermediateDirectory)/BattleShip.cpp$(ObjectSuffix) $(IntermediateDirectory)/Battlefield.cpp$(ObjectSuffix) $(IntermediateDirectory)/Human.cpp$(ObjectSuffix) $(IntermediateDirectory)/Computer.cpp$(ObjectSuffix) $(IntermediateDirectory)/Coordinate.cpp$(ObjectSuffix) $(IntermediateDirectory)/replay.cpp$(ObjectSuffix) $(IntermediateDirectory)/battaglia_navale.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submarine.cpp$(ObjectSuffix) $(IntermediateDirectory)/SupportVessel.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/BattleShip.cpp$(ObjectSuffix): BattleShip.cpp $(IntermediateDirectory)/BattleShip.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/alex1/Codlite_workspace/Codlite_workspace/Progetto_finale/BattleShip.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BattleShip.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BattleShip.cpp$(DependSuffix): BattleShip.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BattleShip.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BattleShip.cpp$(DependSuffix) -MM BattleShip.cpp

$(IntermediateDirectory)/BattleShip.cpp$(PreprocessSuffix): BattleShip.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BattleShip.cpp$(PreprocessSuffix) BattleShip.cpp

$(IntermediateDirectory)/Battlefield.cpp$(ObjectSuffix): Battlefield.cpp $(IntermediateDirectory)/Battlefield.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/alex1/Codlite_workspace/Codlite_workspace/Progetto_finale/Battlefield.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Battlefield.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Battlefield.cpp$(DependSuffix): Battlefield.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Battlefield.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Battlefield.cpp$(DependSuffix) -MM Battlefield.cpp

$(IntermediateDirectory)/Battlefield.cpp$(PreprocessSuffix): Battlefield.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Battlefield.cpp$(PreprocessSuffix) Battlefield.cpp

$(IntermediateDirectory)/Human.cpp$(ObjectSuffix): Human.cpp $(IntermediateDirectory)/Human.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/alex1/Codlite_workspace/Codlite_workspace/Progetto_finale/Human.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Human.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Human.cpp$(DependSuffix): Human.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Human.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Human.cpp$(DependSuffix) -MM Human.cpp

$(IntermediateDirectory)/Human.cpp$(PreprocessSuffix): Human.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Human.cpp$(PreprocessSuffix) Human.cpp

$(IntermediateDirectory)/Computer.cpp$(ObjectSuffix): Computer.cpp $(IntermediateDirectory)/Computer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/alex1/Codlite_workspace/Codlite_workspace/Progetto_finale/Computer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Computer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Computer.cpp$(DependSuffix): Computer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Computer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Computer.cpp$(DependSuffix) -MM Computer.cpp

$(IntermediateDirectory)/Computer.cpp$(PreprocessSuffix): Computer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Computer.cpp$(PreprocessSuffix) Computer.cpp

$(IntermediateDirectory)/Coordinate.cpp$(ObjectSuffix): Coordinate.cpp $(IntermediateDirectory)/Coordinate.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/alex1/Codlite_workspace/Codlite_workspace/Progetto_finale/Coordinate.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Coordinate.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Coordinate.cpp$(DependSuffix): Coordinate.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Coordinate.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Coordinate.cpp$(DependSuffix) -MM Coordinate.cpp

$(IntermediateDirectory)/Coordinate.cpp$(PreprocessSuffix): Coordinate.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Coordinate.cpp$(PreprocessSuffix) Coordinate.cpp

$(IntermediateDirectory)/replay.cpp$(ObjectSuffix): replay.cpp $(IntermediateDirectory)/replay.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/alex1/Codlite_workspace/Codlite_workspace/Progetto_finale/replay.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/replay.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/replay.cpp$(DependSuffix): replay.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/replay.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/replay.cpp$(DependSuffix) -MM replay.cpp

$(IntermediateDirectory)/replay.cpp$(PreprocessSuffix): replay.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/replay.cpp$(PreprocessSuffix) replay.cpp

$(IntermediateDirectory)/battaglia_navale.cpp$(ObjectSuffix): battaglia_navale.cpp $(IntermediateDirectory)/battaglia_navale.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/alex1/Codlite_workspace/Codlite_workspace/Progetto_finale/battaglia_navale.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/battaglia_navale.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/battaglia_navale.cpp$(DependSuffix): battaglia_navale.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/battaglia_navale.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/battaglia_navale.cpp$(DependSuffix) -MM battaglia_navale.cpp

$(IntermediateDirectory)/battaglia_navale.cpp$(PreprocessSuffix): battaglia_navale.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/battaglia_navale.cpp$(PreprocessSuffix) battaglia_navale.cpp

$(IntermediateDirectory)/Submarine.cpp$(ObjectSuffix): Submarine.cpp $(IntermediateDirectory)/Submarine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/alex1/Codlite_workspace/Codlite_workspace/Progetto_finale/Submarine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submarine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submarine.cpp$(DependSuffix): Submarine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submarine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submarine.cpp$(DependSuffix) -MM Submarine.cpp

$(IntermediateDirectory)/Submarine.cpp$(PreprocessSuffix): Submarine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submarine.cpp$(PreprocessSuffix) Submarine.cpp

$(IntermediateDirectory)/SupportVessel.cpp$(ObjectSuffix): SupportVessel.cpp $(IntermediateDirectory)/SupportVessel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/alex1/Codlite_workspace/Codlite_workspace/Progetto_finale/SupportVessel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SupportVessel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SupportVessel.cpp$(DependSuffix): SupportVessel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SupportVessel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SupportVessel.cpp$(DependSuffix) -MM SupportVessel.cpp

$(IntermediateDirectory)/SupportVessel.cpp$(PreprocessSuffix): SupportVessel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SupportVessel.cpp$(PreprocessSuffix) SupportVessel.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


