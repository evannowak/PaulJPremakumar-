//
//  shaderReader.hpp
//  vulkanTesting
//
//  Created by Paul Premakumar on 9/25/18.
//  Copyright © 2018 Paul Premakumar. All rights reserved.
//

#ifndef shaderReader_hpp
#define shaderReader_hpp

#include <vector>
#include <string>

namespace shaderReader {
    
    std::vector<char> readFile(const std::string & filePath);
}

#endif /* shaderReader_hpp */
