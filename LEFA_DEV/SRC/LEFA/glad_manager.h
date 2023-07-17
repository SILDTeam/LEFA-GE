

void consoleGLVersion()
{
    printf("engine OpenGl Version : 2.1 \n");
    const char* version = (const char*)glGetString(GL_VERSION);
    printf("device OpenGL Version : %s\n", version);
}

