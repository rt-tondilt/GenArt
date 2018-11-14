#pragma once
#include <glm/ext.hpp>
#include <map>
#include <GLFW/glfw3.h>

class Camera {

    public:
        glm::mat4 projection;
        glm::mat4 view;
        std::map<int, bool> keyboard;

        Camera();
        Camera(glm::mat4 projection);
        void translate(float x, float y, float z);
        void initKeyboard();
        void processInput(float dt);
};

