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
        if (keyboard.find(key) != keyboard.end()) {
            keyboard.at(key) = true;
        }
    }
    if (action == GLFW_RELEASE) {
        if (keyboard.find(key) != keyboard.end()) {
            keyboard.at(key) = false;
        }
    }
}



void tickKeyboard(float dt) {
    dt = dt * 4;
    if (keyboard.at(GLFW_KEY_W)) {
        cam.translate(0.f, 0.f, dt);
    }
    if (keyboard.at(GLFW_KEY_S)) {
        cam.translate(0.f, 0.f, -dt);
    }
    if (keyboard.at(GLFW_KEY_A)) {
        cam.translate(dt, 0.f, 0.f);
    }
    if (keyboard.at(GLFW_KEY_D)) {
        cam.translate(-dt, 0.f, 0.f);
    }
}


void initKeyboard() {
    keyboard.insert(std::make_pair(GLFW_KEY_W, false));
    keyboard.insert(std::make_pair(GLFW_KEY_A, false));
    keyboard.insert(std::make_pair(GLFW_KEY_S, false));
    keyboard.insert(std::make_pair(GLFW_KEY_D, false));
}

