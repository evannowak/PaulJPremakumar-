#include <iostream>
#include <vector>
#include <string>

#include "GraphicsApplication.hpp"

int main() {
    GraphicsApplication app;
    app.run();
    app.cleanup();
    return EXIT_SUCCESS;
}

