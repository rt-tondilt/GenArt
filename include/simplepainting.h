#include "painting.h"

class SimplePainting: public Painting {
    public:
        SimplePainting(const char* vshaderpath, const char* fshaderpath);
        void render(GLuint VAO);
};
