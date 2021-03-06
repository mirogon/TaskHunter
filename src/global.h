#pragma once
//C++

#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <filesystem>
#include <sys/stat.h>
#include <sys/types.h>
#include <Windows.h>
#include <ShlObj.h>

//M1
#include "M1Serialization/include/M1Serialization.h"

constexpr uint8_t LENGTH_TASKDESCRIPTION = 64;
constexpr uint8_t LENGTH_TASKCATEGORY = 13;

extern std::string PATH_SERIALIZATION;

namespace m1
{
    inline std::ifstream::pos_type filesize(const char* filename)
    {
        std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
        return in.tellg();
    }
}
