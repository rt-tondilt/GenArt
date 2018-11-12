#include <stack>
#include "testpaintings.h"

RedPainting::RedPainting(glm::mat4 projectionMatrix, glm::mat4 viewMatrix) :
    Painting(shader_prog("shaders/basic.vert.glsl", "shaders/redpainting.frag.glsl"), projectionMatrix, viewMatrix)
    {
        pshader.setup();
        pshader.begin();
        pshader.uniformMatrix4fv("projectionMatrix", projectionMatrix);
        pshader.end();
    };


void RedPainting::render(GLuint VAO) {
    std::stack<glm::mat4> ms;
    ms.push(glm::mat4(1.0));

    //set up the shaders, uniforms
    pshader.begin();
    pshader.uniformMatrix4fv("viewMatrix", viewMatrix);

    ms.push(ms.top());
        ms.top() = glm::translate(ms.top(), position);
        ms.top() = glm::rotate(ms.top(), glm::radians(angle), glm::vec3(0., 1., 0.));
        pshader.uniformMatrix4fv("modelMatrix", ms.top());
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, 0);
    ms.pop();
    pshader.end();
};

BluePainting::BluePainting(glm::mat4 projectionMatrix, glm::mat4 viewMatrix) :
    Painting(shader_prog("shaders/basic.vert.glsl", "shaders/bluepainting.frag.glsl"), projectionMatrix, viewMatrix)
    {
        pshader.setup();
        pshader.begin();
        pshader.uniformMatrix4fv("projectionMatrix", projectionMatrix);
        pshader.end();
    };


void BluePainting::render(GLuint VAO) {
    std::stack<glm::mat4> ms;
    ms.push(glm::mat4(1.0));

    //set up the shaders, uniforms
    pshader.begin();
    pshader.uniformMatrix4fv("viewMatrix", viewMatrix);

    ms.push(ms.top());
        ms.top() = glm::translate(ms.top(), position);
        ms.top() = glm::rotate(ms.top(), glm::radians(angle), glm::vec3(0., 1., 0.));
        pshader.uniformMatrix4fv("modelMatrix", ms.top());
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, 0);
    ms.pop();
    pshader.end();
};
