//
//  window.cpp
//  vulkanTesting
//
//  Created by Paul Premakumar on 11/15/18.
//  Copyright © 2018 Paul Premakumar. All rights reserved.
//

#include "window.hpp"

#include <stdexcept>

window::window(int width, int height) : _width(width),
                                        _height(height)
{

}

void window::cleanUp()
{
    glfwDestroyWindow(_window);

    glfwTerminate();
}

void window::createSurface(const VkInstance & instance, VkSurfaceKHR  * surface)
{
    if (glfwCreateWindowSurface(instance, _window, nullptr, surface) != VK_SUCCESS)
    {
        throw std::runtime_error("failed to create window");
    }
}


void window::initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    _window = glfwCreateWindow(_width, _height, "Vulkan window", nullptr, nullptr);
}

GLFWwindow * window::getWindow() const {
    return _window;
}

