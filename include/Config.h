#pragma once
#include "nlohmann/json.hpp"
#include <fstream>
#include <vector>
#include <iostream>
#include "Game.h"

class ConfigProgram
{

private:
    ConfigGames configGames;
    std::vector<std::string> listFilesJson = configGames.getListGameJson();

public:

    void createConfigFile();

};