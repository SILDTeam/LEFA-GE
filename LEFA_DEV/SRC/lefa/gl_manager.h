//OpenGL short



//glad_gl version
/*
#ifdef GL_2_0
#   define GL_VERSION_2_0
#   define SHADER_110
#endif
*/

#ifdef GL_2_1
#   define GL_VERSION_2_1
#   define SHADER_120
#endif

#ifdef GL_3_0
#   define GL_VERSION_3_0
#   define SHADER_130
#endif

#ifdef GL_3_1
#   define GL_VERSION_3_1
#   define SHADER_140
#endif

#ifdef GL_3_2
#   define GL_VERSION_3_2
#   define SHADER_150
#endif

#ifdef GL_3_3
#   define GL_VERSION_3_3
#   define SHADER_330
#endif

#ifdef GL_4_0
#   define GL_VERSION_4_0
#   define shader_400
#endif

#ifdef GL_4_1
#   define GL_VERSION_4_1
#   define SHADER_410
#endif

#ifdef GL_4_2
#   define GL_VERSION_4_2
#   define SHADER_420
#endif


/*
#ifdef SHADER_110
#   define load_110
#endif
*/


#ifdef SHADER_120
#   define load_120
#endif

#ifdef SHADER_130
#   define load_130
#endif

#ifdef SHADER_140
#   define load_140
#endif

#ifdef SHADER_150
#   define load_150
#endif

#ifdef SHADER_330
#   define load_330
#endif

#ifdef SHADER_120
#   define load_410
#endif

#ifdef SHADER_420
#   define load_420
#endif



#include"lefa/ThirdParty/glad/OpenGL/glad_gl.h";
#include"lefa/Render/OpenGL/Shader/shaderv.h";
#include"lefa/Render/OpenGL/Shader/shaderLoader.h";



/*
void showConsoleGLVersion()
{
    printf("engine OpenGl Version : 2.1 \n");
    const char* version = (const char*)glGetString(GL_VERSION);
    printf("device OpenGL Version : %s\n", version);
}
*/
