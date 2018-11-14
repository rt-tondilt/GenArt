#pragma once
#include <GLFW/glfw3.h>     // Windows and input

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void initKeyboard();
void tickKeyboard(float dt);
