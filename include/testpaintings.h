#include "painting.h"

class RedPainting: public Painting {
    public:
        RedPainting(glm::mat4 projectionMatrix, glm::mat4 viewMatrix);
        void render(GLuint VAO);
};