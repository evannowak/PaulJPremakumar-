//
//  GraphicsApplication.cpp
//  vulkanTesting
//
//  Created by Paul Premakumar on 11/15/18.
//  Copyright © 2018 Paul Premakumar. All rights reserved.
//

#include <stdexcept>
#include <iostream>

#include "GraphicsApplication.hpp"
#include "HelloTriangleApplication.h"
#include "shaderReader.hpp"

namespace {
    uint32_t WIDTH = 800;
    uint32_t HEIGHT = 600;
}

GraphicsApplication::GraphicsApplication() : _app(),
                                             _window(WIDTH, HEIGHT)
{
    
    // initialize the window
    _window.initWindow();
    _app.setWindow(& _window);
    
    // create the shaders
    // const std::string vertexShaderSrc("/Users/ppremakumar/Documents/vulkansdk-macos-1.1.82.0/myVulkan/helloVulkan/vulkanTesting/vulkanTesting/shaders/singleUniformVertex.spv");
    const std::string vertexShaderSrc("/Users/ppremakumar/Documents/vulkansdk-macos-1.1.82.0/myVulkan/helloVulkan/vulkanTesting/vulkanTesting/shaders/twoUniformVert.spv");
    const std::string fragmentShaderSrc("/Users/ppremakumar/Documents/vulkansdk-macos-1.1.82.0/myVulkan/helloVulkan/vulkanTesting/vulkanTesting/shaders/frag.spv");
    std::vector<char> vertexShader(shaderReader::readFile(vertexShaderSrc));
    std::vector<char> fragmentShader(shaderReader::readFile(fragmentShaderSrc));
    _app.setVertexShaderSPV(std::move(vertexShader));
    _app.setFragmentShaderSPV(std::move(fragmentShader));
    
    // initialize the graphics
    _app.initializeGraphics();        
}

void GraphicsApplication::run() {
    try {
        while (!glfwWindowShouldClose(_window.getWindow())) {
            glfwPollEvents();
            _app.drawFrame();
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
