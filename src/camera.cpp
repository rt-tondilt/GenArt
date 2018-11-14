#include "camera.h"
#include "stdio.h"

    Camera::Camera() ://default constructor
        projection(glm::perspective(glm::radians(80.), 4./3., 0.1, 100.)),
        view(glm::lookAt(
            glm::vec3(3.0, 6.0, 15.0),
            glm::vec3(0.0, 0.0, 0.0),
            glm::vec3(0.0, 1.0, 0.0)
            ))
        {
            initKeyboard();
        }

    Camera::Camera(glm::mat4 projection) ://with custom projection matrix
        projection(projection),
        view(glm::lookAt(
            glm::vec3(3.0, 6.0, 15.0), //Position
            glm::vec3(0.0, 0.0, 0.0),  //LookAt
            glm::vec3(0.0, 1.0, 0.0)   //Up
            ))
        {
            initKeyboard();
        }

    void Camera::translate(float x, float y, float z) {
        view = glm::translate(view, glm::vec3(x, y, z));
    }

    void Camera::initKeyboard() {
        keyboard.insert(std::make_pair(GLFW_KEY_W, false));
        keyboard.insert(std::make_pair(GLFW_KEY_A, false));
        keyboard.insert(std::make_pair(GLFW_KEY_S, false));
        keyboard.insert(std::make_pair(GLFW_KEY_D, false));
        keyboard.insert(std::make_pair(GLFW_KEY_LEFT_SHIFT, false));
    }

    //runs every frame
    void Camera::processInput(float dt) {

        //get mouse position difference from last frame
        double currmousex, currmousey;
        float xdiff, ydiff;
        glfwGetCursorPos(win, &currmousex, &currmousey);
        xdiff = currmousex - mx;
        ydiff = currmousey - my;
        mx = currmousex;
        my = currmousey;
        view = glm::rotate(view, glm::radians(xdiff), glm::vec3(0.f, 1.f, 0.f));
        view = glm::rotate(view, glm::radians(ydiff), glm::vec3(1.f, 0.f, 0.f));


        float mov = keyboard.at(GLFW_KEY_LEFT_SHIFT) ? dt * runspeed : dt * walkspeed;
        if (keyboard.at(GLFW_KEY_W)) {
            translate(0.f, 0.f, mov);
        }
        if (keyboard.at(GLFW_KEY_S)) {
            translate(0.f, 0.f, -mov);
        }
        if (keyboard.at(GLFW_KEY_A)) {
            translate(mov, 0.f, 0.f);
        }
        if (keyboard.at(GLFW_KEY_D)) {
            translate(-mov, 0.f, 0.f);
        }

    }


