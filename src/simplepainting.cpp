#include "simplepainting.h"
#include <stack>

SimplePainting::SimplePainting( const char* vshaderpath, const char* fshaderpath ) :
    // calls the base class constructor: this is the important part: change your shaders here
    Painting(shader_prog(vshaderpath, fshaderpath))
    {
        /////////////
        //this setup call MUST be inside the derived class constructor:
        //it doesn't work if it's in the base class for whatever reason
        //setup compiles the shaders, creates the program, attaches and links the shaders
        pshader.setup();
        /////////////
        //begin just calls glUseUniform, and end calls glUseUniform(0)
        pshader.begin();

        //this uniform stays constant so it doesn't have to be changed after initial setup
        pshader.uniformMatrix4fv("projectionMatrix", projectionMatrix);
        pshader.end();
    };

void SimplePainting::render(GLuint VAO) {
    std::stack<glm::mat4> ms;
    ms.push(glm::mat4(1.0));

    //set up the shaders, uniforms
    //rendering is as usual, but beginning and ending their own shaders, as well as updating necessary uniforms
    //in this case im passing in a VAO to render because I don't want each painting to have its own VAO,
    //but in principle you can store the objects VAO inside it as well, and it'll probably be more convenient
    pshader.begin();
    pshader.uniformMatrix4fv("viewMatrix", viewMatrix);
    pshader.uniform1f("time", (float)glfwGetTime());
    /* glUniform1f(2, (float)glfwGetTime()); */

    ms.push(ms.top());
        ms.top() = glm::translate(ms.top(), position);
        ms.top() = glm::rotate(ms.top(), glm::radians(angle), glm::vec3(0., 1., 0.));
        //maybe we can even set up the modelMatrix only once in constructor as well if they don't move around
        pshader.uniformMatrix4fv("modelMatrix", ms.top());
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, 0);
    ms.pop();
    pshader.end();
};
