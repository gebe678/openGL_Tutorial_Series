#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using std::string;

class Shader
{

    private:
        
        void checkForErrors(GLuint shader, string type, string name);
        

    public:

        // the program ID
        GLuint ID;

        // constructor reads and builds the shader
        Shader(const char* vertexPath, const char* fragmentPath);
        // use/activate the shader
        void use();

};

#endif