#pragma once
#include <glm/ext.hpp>
#include <map>
#include <GLFW/glfw3.h>

class Camera {

    public:
        glm::vec3 worldpos;
        glm::vec2 rotation;
        glm::mat4 projection;
        glm::mat4 view;
        GLFWwindow *win;
        const float walkspeed = 4.f;
        const float runspeed = 10.f;
        std::map<int, bool> keyboard;
        double mx = 0, my = 0;

        Camera();
        Camera(glm::mat4 projection);
        void translate(float x, float y, float z);
        void initKeyboard();
        void processInput(float dt);
        void updateViewMat();
};

