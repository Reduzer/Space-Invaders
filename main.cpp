//
// Created by Fyn Deubner on 19.03.26.
//

#include <GLFW3/glfw3.h>

GLFWwindow* m_pWindow;
int m_nHeight = 480;
int m_nWidth = 640;
const char* m_pcTitle = "Space Invaders";

void error_callback(int error, const char* description)
{
    printf("Error: %s\n", description);
}

int main()
{

    GLFWwindow* window;


    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
