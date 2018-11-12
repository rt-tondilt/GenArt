#include "shader_util.h"
#include <glm/glm.hpp>
/* #include <GLEW/glew.h> */

class Painting {

    public:
        shader_prog pshader;
        glm::vec3 position;
        float angle;
        glm::mat4 projectionMatrix;
        glm::mat4 viewMatrix;

        Painting(shader_prog pshader, glm::mat4 projectionMatrix, glm::mat4 viewMatrix) :
                    pshader(pshader),
                    position(glm::vec3(0)),
                    angle(0.f),
                    projectionMatrix(projectionMatrix),
                    viewMatrix(viewMatrix)
                    {};

        virtual void render(GLuint VAO) =0;
        ~Painting() {};
};
