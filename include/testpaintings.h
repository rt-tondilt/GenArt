#pragma once
#include "painting.h"

//to create your own "painting" just inherit from the painting class, define your own construction and render methods
//(and whatever else methods you need)
//more details in testpaintings.cpp
class RedPainting: public Painting {
    public:
        RedPainting();
        void render(GLuint VAO);
};

class BluePainting: public Painting {
    public:
        BluePainting();
        void updateUniforms();
        void render(GLuint VAO);
};
