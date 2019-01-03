//
//  shaderReader.cpp
//  vulkanTesting
//
//  Created by Paul Premakumar on 9/25/18.
//  Copyright © 2018 Paul Premakumar. All rights reserved.
//

#include "shaderReader.hpp"

#include <ios>
#include <fstream>

std::vector<char> shaderReader::readFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::ate | std::ios::binary);

    if (!file.is_open()) {
        throw std::runtime_error("failed to open file!");
    }

    size_t fileSize = (size_t) file.tellg();
    std::vector<char> buffer(fileSize);

    file.seekg(0);
    file.read(buffer.data(), fileSize);

    file.close();

    return buffer;
}
