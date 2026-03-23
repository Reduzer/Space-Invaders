//
// Created by Fyn Deubner on 19.03.26.
//

#include <cstdio>
#include <cstdint>
#include <glew/glew.h>
#include <glfw/glfw3.h>

GLFWwindow* window;
int Height = 480;
int Width = 640;
const char* Title = "Space Invaders";


struct Buffer {
    size_t width, height;
    uint32_t* data;

    uint32_t rgbToUInt32(uint8_t red, uint8_t green, uint8_t blue){
        return (red << 24) | (green << 16) | (blue << 8) | 255;
    }
};

void buffer_clear(Buffer* buffer, uint32_t color)
{
    for(size_t i = 0; i < buffer->width * buffer->height; ++i)
    {
        buffer->data[i] = color;
    }
}

void error_callback(int error, const char* description)
{
    printf("Error: %s\n", description);
}

int main()
{
    //Initialize GLFW
    if (!glfwInit())
        return -1;

    // Initialize window with specific settings
    window = glfwCreateWindow(Width, Height, "Space Invaders", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    //Set OpenGL Version
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    //Initialize GLEW
    GLenum err = glewInit();
    if(err != GLEW_OK)
    {
        fprintf(stderr, "Error initializing GLEW.\n");
        glfwTerminate();
        return -1;
    }

    int anOpenGLInfo[2] = {-1,1};
    glGetIntegerv(GL_MAJOR_VERSION, &anOpenGLInfo[0]);
    glGetIntegerv(GL_MINOR_VERSION, &anOpenGLInfo[1]);

    printf("Using OpenGL: %d.%d\n", anOpenGLInfo[0], anOpenGLInfo[1]);

    glClearColor(1.0, 0.0, 0.0, 1.0);

    // Main Loop for the game
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
