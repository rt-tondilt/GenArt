#pragma once

#include "shader_util.h"
#include <glm/glm.hpp>
#include "globals.h"

class Painting {

    public:
        shader_prog pshader;
        glm::vec3 position;
        float angle;
        const glm::mat4 &projectionMatrix;
        const glm::mat4 &viewMatrix;

        Painting(shader_prog pshader) :
                    pshader(pshader),
                    position(glm::vec3(0)),
                    angle(0.f),
                    projectionMatrix(cam.projection),
                    viewMatrix(cam.view)
                    {};

        virtual void render(GLuint VAO) =0;
        ~Painting() {};
};
