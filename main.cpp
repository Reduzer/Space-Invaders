#include <cstdio>
#include <../include/GLFW3/glfw3.h>

typedef void(*GLFWerrorfun)(int, const char *);

int nHeight = 640;
int nWidth = 480;
const char* pTitle = "Space Invaders";

GLFWwindow* m_pWindow;

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

int CreateWindow (int nHeight, int nWidth, const char* pTitle) {
    m_pWindow = glfwCreateWindow (nWidth, nHeight, pTitle, NULL, NULL);
    if (!m_pWindow) {
        glfwTerminate();
        return -1;
    }

    return 1;
}

int Setup() {
    int nResult = -1;
    glfwSetErrorCallback(error_callback);

    if (glfwInit()) {
        nResult = 1;
    }

    return nResult;
}

int main () {
    if (Setup() < 1)
        return -1;

    if (CreateWindow(nWidth, nHeight, pTitle) < 1)
        return -1;

    glfwMakeContextCurrent(m_pWindow);
}