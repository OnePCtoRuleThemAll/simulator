#pragma once
#include <iostream>
#include <GLFW/glfw3.h>

class Window {
public:
    static Window& getInstance() {
        static Window instance;
        return instance;
    }

    GLFWwindow* getWindow() const {
        return window;
    }

    void setWindow(GLFWwindow* window) {
        this->window = window;
    }

private:
    GLFWwindow* window;

    Window() {
    }

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;
};