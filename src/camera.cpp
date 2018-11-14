#include "camera.h"

    Camera::Camera() ://default constructor
        projection(glm::perspective(glm::radians(80.), 4./3., 0.1, 100.)),
        view(glm::lookAt(
            glm::vec3(3.0, 6.0, 15.0),
            glm::vec3(0.0, 0.0, 0.0),
            glm::vec3(0.0, 1.0, 0.0)
                    )
            ) {}

    Camera::Camera(glm::mat4 projection) ://with custom projection matrix
        projection(projection),
        view(glm::lookAt(
            glm::vec3(3.0, 6.0, 15.0), //Position
            glm::vec3(0.0, 0.0, 0.0),  //LookAt
            glm::vec3(0.0, 1.0, 0.0)   //Up
                    )
            ) {}

    void Camera::translate(float x, float y, float z) {
        view = glm::translate(view, glm::vec3(x, y, z));
    }

