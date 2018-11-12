#include <glm/ext.hpp>

class Camera {

    public:
        glm::mat4 projection;
        glm::mat4 view;
        Camera();
        Camera(glm::mat4 projection);
};
