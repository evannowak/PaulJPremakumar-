//
//  HelloTriangleApplication.h
//  vulkanTesting
//
//  Created by Paul Premakumar on 9/5/18.
//  Copyright © 2018 Paul Premakumar. All rights reserved.
//

#ifndef HelloTriangleApplication_h
#define HelloTriangleApplication_h

#include <vector>
#include <string>
#include <unordered_map>

#include "window.hpp"
#include "shaderModule.hpp"
#include "pipeline.hpp"

class HelloTriangleApplication {

public:

    HelloTriangleApplication();

    void setWindow(window * aWindow);

    void initializeGraphics();

    void cleanup();

    void run();

    void drawFrame();

    void updateUniformBuffer(uint32_t currentImage);

    void insertShaderSPIRV(const std::string shaderName, const std::vector<char> & vertexShader);

    // sets the SPIR-V vertex shader code
    void setVertexShaderSPV(const std::vector<char> & vertexShader);

    //// sets the SPIR-V fragment shader code
    void setFragmentShaderSPV(const std::vector<char> & fragmentShader);

private:
    void initWindow();

    void initVulkan();

    void setupDebugCallback();

    void mainLoop();

    void doCleanup();

    // device suitability test
    bool isDeviceSuitable(const VkPhysicalDevice& device);

    void pickPhysicalDevice();

    void createLogicalDevice();

    void createSurface();

    void createSwapChain();

    void createImageView();

    void createDescriptorSetLayout();

    void createGraphicsPipeline(std::string pipelineName, std::string vertexShader, std::string fragmentShader, float viewFactor = 1.0);

    void createSecondGraphicsPipeline(std::string pipelineName, std::string vertexShader, std::string fragmentShader);

    void createRenderPass();

    void createFrameBuffers();

    void createCommandPool();

    void createDescriptorPool();

    void createDescriptorSets();

    void createBuffer(VkDeviceSize size,
                      VkBufferUsageFlags usage,
                      VkMemoryPropertyFlags properties,
                      VkBuffer& buffer,
                      VkDeviceMemory& bufferMemory);

    void copyBuffer(VkBuffer srcBuffer,
                    VkBuffer dstBuffer,
                    VkDeviceSize size);

    void createVertexBuffer();

    void createUniformBuffers();

    uint32_t findMemoryType(uint32_t typeFilter,
                            VkMemoryPropertyFlags properties);


    void createCommandBuffers();

    void createSynchronizationObjects();

    VkShaderModule createShaderModule(const std::vector<char> & shaderBytes);

    /**
     * Initialize the vulkan library by creating an instance.
     * This should be the first thing we do.
     **/
    void createInstance();

private:

    window * _window = nullptr;
    VkInstance _instance;
    VkQueue _graphicsQueue;
    VkPhysicalDevice _physicalDevice = VK_NULL_HANDLE;
    VkDevice _device;
    VkSurfaceKHR _surface;
    VkQueue _presentQueue;
    VkBuffer _vertexBuffer;
    VkDeviceMemory _vertexBufferMemory;

    // debug callback
    VkDebugUtilsMessengerEXT _callback;

    // swap chain
    VkSwapchainKHR _swapChain;
    VkFormat _swapChainImageFormat;
    VkExtent2D _swapChainExtent;
    std::vector<VkImage> _swapChainImages;
    std::vector<VkImageView> _swapChainImageViews;
    std::vector<VkFramebuffer> _swapChainBuffers;

    // uniform buffer
    std::vector<VkBuffer> _uniformBuffers;
    std::vector<VkDeviceMemory> _uniformBuffersMemory;

    // uniform buffer2
    std::vector<VkBuffer> _uniformBuffers2;
    std::vector<VkDeviceMemory> _uniformBuffersMemory2;

    // shaders
    std::unordered_map<std::string, shaderModule> _shaders;

    // shader source
    std::vector<char> _vertexShader;
    std::vector<char> _fragmentShader;

    // shader Module
    VkShaderModule _vertexShaderModule;
    VkShaderModule _fragmentShaderModule;

    // renderpass & pipeline
    VkRenderPass _renderPass;
    VkDescriptorSetLayout _descriptorSetLayout;
    VkPipelineLayout _pipelineLayout;

    // graphics pipeline
    std::unordered_map<std::string, pipeline> _graphicsPipeLines;

    // descriptor
    VkDescriptorPool _descriptorPool;
    std::vector<VkDescriptorSet> _descriptorSets;

    // commands
    VkCommandPool _commandPool;
    std::vector<VkCommandBuffer> _commandBuffers;

    // semaphores
    std::vector<VkSemaphore> _imageAvailableSemaphores;
    std::vector<VkSemaphore> _renderFinishedSemaphores;
    std::vector<VkFence> _inFlightFences;
    // current frame
    size_t _currentFrame = 0;
};

#endif /* HelloTriangleApplication_h */
