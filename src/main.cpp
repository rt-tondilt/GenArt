// ---------------------------- Includes -------------------------- //
#include <stdlib.h>         // C++ standard library
#include <stack>            // We use the standard C++ stack implementation to create model matrix stacks
#include <memory>
#include <vector>            // We use the standard C++ stack implementation to create model matrix stacks
#include <unistd.h>         // Threading
#include <stdio.h>          // Input/Output
#include <GLEW/glew.h>      // OpenGL Extension Wrangler -
#include <GLFW/glfw3.h>     // Windows and input
#include <glm/glm.hpp>      // OpenGL math library

#include "camera.h"
#include "shader_util.h"    // Utility methods to keep this file a bit shorter.
#include "testpaintings.h"


// --------------- Forward declarations ------------- //
GLuint createQuad(glm::vec3 color, float s);
std::vector<Painting*> makePaintings();
// --- Load the shaders declared in glsl files in the project folder ---//
shader_prog basicshader("shaders/basic.vert.glsl", "shaders/basic.frag.glsl");
GLuint floorVAO, paintingVAO;
Camera cam;

std::vector<Painting*> makePaintings() {

    Painting *blue = new BluePainting(cam.projection, cam.view);
    blue->position = glm::vec3(-8.f, 0.f, -7.f);
    Painting *red = new RedPainting(cam.projection, cam.view);
    red->position = glm::vec3(2.f, 0.f, -7.f);

    std::vector<Painting*> vec = {blue, red};
    return vec;
}

void initWalls() {
    floorVAO = createQuad(glm::vec3(0.22, 0.22, 0.22), 50);
    paintingVAO = createQuad(glm::vec3(0.50, 0.50, 0.50), 4);
}

GLuint createQuad(glm::vec3 color, float s) {
    GLfloat vertices[] = {
                            -s, -s, 0.0,
                             s, -s, 0.0,
                             s,  s, 0.0,
                            -s,  s, 0.0
                        };

    GLubyte indices[] = {
                            0, 1, 2,
                            0, 2, 3
                        };

    GLfloat colors[] = {
                            color[0], color[1], color[2],
                            color[0], color[1], color[2],
                            color[0], color[1], color[2],
                            color[0], color[1], color[2]
                        };

    GLuint vertexArrayHandle;
    glGenVertexArrays(1, &vertexArrayHandle);
    glBindVertexArray(vertexArrayHandle);

    basicshader.attribute3fv("position", vertices, 12);
    basicshader.attribute3fv("color", colors, 12);

    // First step. We create a handle for our buffer
    GLuint vboHandle;
    glGenBuffers(1, &vboHandle);
    // Second step. We bind (activate) this buffer for the OpenGL state machine.
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboHandle);
    // Third step. We store the vertex indexes in the VBO.
    // These define the faces of the triangles, which make up the cube/
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLfloat)*12, indices, GL_STATIC_DRAW);
    //We return handle to vertex array. Step 4 takes place in method drawHangar.
    //Step 5 we skip, as all our assets have the same lifetime as rest of the program.
    return vertexArrayHandle;
}

void drawWorld() {
    basicshader.begin();
    basicshader.uniformMatrix4fv("viewMatrix", cam.view);
    std::stack<glm::mat4> ms;
    ms.push(glm::mat4(1.0));
    ms.push(ms.top()); //Floor
        ms.top() = glm::rotate(ms.top(), glm::radians(-90.0f), glm::vec3(1.0, 0.0, 0.0));
        ms.top() = glm::translate(ms.top(), glm::vec3(0.0, 0.0, -10.0));

        basicshader.uniformMatrix4fv("modelMatrix", ms.top());
        glBindVertexArray(floorVAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, 0);
    ms.pop();
    basicshader.end();
}

void drawPaintings() {
    std::stack<glm::mat4> ms;
    ms.push(glm::mat4(1.0));
    for (float i = 0.; i < 3.; i++) {
    ms.push(ms.top());
        ms.top() = glm::translate(ms.top(), glm::vec3(-8 + 10*i, 0.0, -7.0));

        basicshader.uniformMatrix4fv("modelMatrix", ms.top());
        glBindVertexArray(paintingVAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, 0);
    ms.pop();

    }
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(int argc, char *argv[]) {
    GLFWwindow *win;

    if (!glfwInit()) {
        exit (EXIT_FAILURE);
    }

    win = glfwCreateWindow(800, 600, "Generative Art Gallery", NULL, NULL);

    if (!win) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(win);
    glewExperimental = GL_TRUE;
    GLenum status = glewInit();

    if(status != GLEW_OK) {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(status));
    }

    const GLubyte* renderer = glGetString (GL_RENDERER); // get renderer string
    const GLubyte* version = glGetString (GL_VERSION); // version as a string
    printf ("Renderer: %s\n", renderer);
    printf ("OpenGL version supported %s\n", version);
    glfwSetKeyCallback(win, key_callback);

    basicshader.setup();
    basicshader.begin();
    basicshader.uniformMatrix4fv("projectionMatrix", cam.projection);
    basicshader.uniformMatrix4fv("viewMatrix", cam.view);

    initWalls();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


    //create our "paintings": they are initialized inside this function
    std::vector<Painting*> paintings = makePaintings();


    while (!glfwWindowShouldClose(win)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        drawWorld();
        //draw our paintings
        for (int i = 0; i<paintings.size(); i++) {
            paintings[i]->render(paintingVAO);
        }
        //
        //
        glfwSwapBuffers(win);
        glfwPollEvents();
        usleep(1000);
    }
    for (int i = 0; i<paintings.size(); i++) {
        delete paintings[i];
    }

    glfwTerminate();
    exit(EXIT_SUCCESS);

    return 0;
}
