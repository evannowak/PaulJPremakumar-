
//  HelloTriangleApplication.h
//  vulkanTesting
//
//  Created by Paul Premakumar on 9/5/18.
//  Copyright © 2018 Paul Premakumar. All rights reserved.
//

#ifndef HelloTriangleApplication_h
#define HelloTriangleApplication_h

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vector>
#include <string>

class HelloTriangleApplication {

public:
    void run();

private:
    void initWindow();

    void initVulkan();

    void setupDebugCallback();

    void mainLoop();

    void drawFrame();

    void cleanupSwapChain();

    void cleanup();

    // device suitability test
    bool isDeviceSuitable(const VkPhysicalDevice& device);

    void pickPhysicalDevice();

    void createLogicalDevice();

    void createSurface();

    void createSwapChain();

    VkImageView createImageView(VkImage image,
                                VkFormat format);

    void createImageViews();

    void createDescriptorSetLayout();

    void createDescriptorPool();

    void createDescriptorSets();

    void createGraphicsPipeline();

    void createRenderPass();

    void createFrameBuffers();

    void createCommandPool();

    // Create and finalize a command buffer to contain single time commands
    VkCommandBuffer beginSingleTimeCommands();
    void endSingleTimeCommands(VkCommandBuffer commandBuffer);

    void createImage(uint32_t width,
                     uint32_t height,
                     VkFormat format,
                     VkImageTiling tiling,
                     VkImageUsageFlags usage,
                     VkMemoryPropertyFlags properties,
                     VkImage& image,
                     VkDeviceMemory& imageMemory);

    void transitionImageLayout(VkImage image,
                               VkFormat format,
                               VkImageLayout oldLayout,
                               VkImageLayout newLayout);

    void copyBufferToImage(VkBuffer buffer,
                           VkImage image,
                           uint32_t width,
                           uint32_t height);

    void createTextureImage();

    void createTextureImageView();

    void createTextureSampler();

    void createBuffer(VkDeviceSize size,
                      VkBufferUsageFlags usage,
                      VkMemoryPropertyFlags properties,
                      VkBuffer& buffer,
                      VkDeviceMemory& bufferMemory);

    void copyBuffer(VkBuffer srcBuffer,
                    VkBuffer dstBuffer,
                    VkDeviceSize size);

    void createVertexBuffer();

    void createIndexBuffer();

    void createUniformBuffers();

    void updateUniformBuffer(uint32_t currentImage);

    uint32_t findMemoryType(uint32_t typeFilter,
                            VkMemoryPropertyFlags properties);

    void createCommandBuffers();

    void createSynchronizationObjects();

    VkShaderModule createShaderModule(const std::string & shaderFilePath);

    /**
     * Initialize the vulkan library by creating an instance.
     * This should be the first thing we do.
     **/
    void createInstance();

private:

    GLFWwindow* _window = nullptr;
    VkInstance _instance;
    VkQueue _graphicsQueue;
    VkPhysicalDevice _physicalDevice = VK_NULL_HANDLE;
    VkDevice _device;
    VkSurfaceKHR _surface;
    VkQueue _presentQueue;

    // Vertex Buffer
    VkBuffer _vertexBuffer;
    VkDeviceMemory _vertexBufferMemory;

    // Index Buffer
    VkBuffer _indexBuffer;
    VkDeviceMemory _indexBufferMemory;

    // Uniform Buffer
    std::vector<VkBuffer> _uniformBuffers;
    std::vector<VkDeviceMemory> _uniformBuffersMemory;

    // Texture
    VkImage _textureImage;
    VkDeviceMemory _textureImageMemory;
    VkImageView _textureImageView;
    VkSampler _textureSampler;

    // debug callback
    VkDebugUtilsMessengerEXT _callback;

    // swap chain
    VkSwapchainKHR _swapChain;
    VkFormat _swapChainImageFormat;
    VkExtent2D _swapChainExtent;
    std::vector<VkImage> _swapChainImages;
    std::vector<VkImageView> _swapChainImageViews;
    std::vector<VkFramebuffer> _swapChainBuffers;

    // shaders
    VkShaderModule _vertexShaderModule;
    VkShaderModule _fragmentShaderModule;

    // renderpass & pipeline
    VkRenderPass _renderPass;
    VkPipelineLayout _pipelineLayout;

    // descriptors
    VkDescriptorSetLayout _descriptorSetLayout;
    VkDescriptorPool _descriptorPool;
    std::vector<VkDescriptorSet> _descriptorSets;

    // graphics pipeline
    VkPipeline _graphicsPipeline;

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
