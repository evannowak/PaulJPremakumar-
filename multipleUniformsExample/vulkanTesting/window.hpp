//
//  window.hpp
//  vulkanTesting
//
//  Created by Paul Premakumar on 11/15/18.
//  Copyright © 2018 Paul Premakumar. All rights reserved.
//

#ifndef window_hpp
#define window_hpp

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class window {
public:
    window(int width, int height);
    
    void initWindow();
    
    void createSurface(const VkInstance & instance, VkSurfaceKHR  * surface);
    
    void destroyWindow();
    
    void terminate();
    
    GLFWwindow * getWindow() const;
    
private:
    unsigned int _width;
    unsigned int _height;
    GLFWwindow * _window = nullptr;
};

#endif /* window_hpp */
