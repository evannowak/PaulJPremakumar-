//
//  shaderModule.hpp
//  vulkanTesting
//
//  Created by Paul Premakumar on 1/2/19.
//  Copyright © 2019 Paul Premakumar. All rights reserved.
//

#ifndef shaderModule_hpp
#define shaderModule_hpp

#include <vector>
#include "window.hpp"

class shaderModule
{
public:
    
    shaderModule();
    
    shaderModule(const std::vector<char> & shaderSource);
    
    void createShader(VkDevice& device);
    
    VkShaderModule & getShaderModule();
    
    void destroy(VkDevice & device);
private:
    bool _shaderCreated;
    VkShaderModule _shaderModule;
    std::vector<char> _shaderSource;
};
#endif /* shaderModule_hpp */
