//
//  GraphicsApplication.hpp
//  vulkanTesting
//
//  Created by Paul Premakumar on 11/15/18.
//  Copyright © 2018 Paul Premakumar. All rights reserved.
//

#ifndef GraphicsApplication_hpp
#define GraphicsApplication_hpp

#include "window.hpp"
#include "HelloTriangleApplication.h"

class GraphicsApplication
{
public:
    
    GraphicsApplication();
    
    void run();
    
private:
    void initWindow();
    
private:
    HelloTriangleApplication _app;
    window _window;
};
#endif /* GraphicsApplication_hpp */
