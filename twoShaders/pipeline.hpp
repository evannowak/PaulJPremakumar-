//
//  pipeline.hpp
//  vulkanTesting
//
//  Created by Paul Premakumar on 1/2/19.
//  Copyright © 2019 Paul Premakumar. All rights reserved.
//

#ifndef pipeline_hpp
#define pipeline_hpp

#include "window.hpp"

class pipeline
{
public:
    pipeline();
    
    void createPipeLine(VkDevice & device, VkRenderPass & renderPass);
    
    void destroy(VkDevice & device);
    
    VkPipeline & getPipeline();
    
    VkPipelineLayout & getPipeineLayout();
    
public:
    // Shaders
    VkShaderModule vertexShaderModule;
    VkShaderModule fragmentShaderModule;
    
    // vertexInputInfo
    VkPipelineVertexInputStateCreateInfo vertexInputInfo;
    
    // Input Assembly
    VkPipelineInputAssemblyStateCreateInfo inputAssembly;
    
    // view
    VkPipelineViewportStateCreateInfo viewportState;
    
    // Rasterizer
    VkPipelineRasterizationStateCreateInfo rasterizer;
    
    // Color blending
    VkPipelineColorBlendAttachmentState colorBlendAttachment;
    
    VkPipelineLayoutCreateInfo pipelineLayoutInfo;
    
private:
    VkPipelineLayout _pipelineLayout;
    VkPipeline _pipeLine;
};

#endif /* pipeline_hpp */
