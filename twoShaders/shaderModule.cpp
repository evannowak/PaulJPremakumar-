//
//  shaderModule.cpp
//  vulkanTesting
//
//  Created by Paul Premakumar on 1/2/19.
//  Copyright © 2019 Paul Premakumar. All rights reserved.
//

#include <string>

#include "shaderModule.hpp"

shaderModule::shaderModule() : _shaderCreated(false),
_shaderModule(),
_shaderSource()
{

}


shaderModule::shaderModule(const std::vector<char> & shaderSource) :
_shaderCreated(false),
_shaderModule(),
_shaderSource(shaderSource)
{

}

void shaderModule::createShader(VkDevice & device)
{
    if (!_shaderCreated)
    {
        if (_shaderSource.size() == 0)
        {
            std::string errMsg("Shader was empty");
            throw std::runtime_error(errMsg);
        }
        VkShaderModuleCreateInfo createInfo = {};
        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        createInfo.codeSize = _shaderSource.size();
        createInfo.pCode = reinterpret_cast<const uint32_t*>(_shaderSource.data());

        if (vkCreateShaderModule(device, &createInfo, nullptr, &_shaderModule) != VK_SUCCESS) {
            throw std::runtime_error("failed to create shader module!");
        }

        _shaderCreated = true;
    }
}

VkShaderModule & shaderModule::getShaderModule()
{
    if (_shaderCreated)
    {
        return _shaderModule;
    }

    std::string errMsg("Shader was not created");
    throw std::runtime_error(errMsg);
}

void shaderModule::destroy(VkDevice &device)
{
    if (_shaderCreated)
    {
        vkDestroyShaderModule(device, _shaderModule, NULL);
    }
}
