#include "input.h"
#include <GLFW/glfw3.h>     // Windows and input
#include "globals.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS or action == GLFW_REPEAT) {
        if (key == GLFW_KEY_ESCAPE) {
            glfwSetWindowShouldClose(window, GL_TRUE);
        }
    }
    if (action == GLFW_PRESS) {
        if (cam.keyboard.find(key) != cam.keyboard.end()) {
            cam.keyboard.at(key) = true;
        }
    }
    if (action == GLFW_RELEASE) {
        if (cam.keyboard.find(key) != cam.keyboard.end()) {
            cam.keyboard.at(key) = false;
        }
    }
}



