#pragma once
//C++

#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <filesystem>
//M1
#include "M1Serialization/include/M1Serialization.h"

extern const std::string PATH_SERIALIZATION;
constexpr uint8_t LENGTH_TASKDESCRIPTION = 64;
constexpr uint8_t LENGTH_TASKCATEGORY = 13;

namespace m1
{
    inline std::ifstream::pos_type filesize(const char* filename)
    {
        std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
        return in.tellg();
    }
}
