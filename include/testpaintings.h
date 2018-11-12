#include "painting.h"

//to create your own "painting" just inherit from the painting class, define your own construction and render methods
//(and whatever else methods you need)
//more details in testpaintings.cpp
class RedPainting: public Painting {
    public:
        RedPainting(const glm::mat4 &projectionMatrix, const glm::mat4 &viewMatrix);
        void render(GLuint VAO);
};

class BluePainting: public Painting {
    public:
        BluePainting(const glm::mat4 &projectionMatrix, const glm::mat4 &viewMatrix);
        void render(GLuint VAO);
};
