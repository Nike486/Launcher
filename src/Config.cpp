#include "Config.h"



void ConfigProgram::createConfigFile()
{
    std::ofstream fileJsonCreate("Config.json");
    nlohmann::json fileJson;

    fileJson["FilesJson"] = listFilesJson;

    fileJsonCreate << fileJson.dump(2);
}

