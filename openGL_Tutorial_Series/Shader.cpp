#include "Shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	std::ifstream vertexData;
	std::ifstream fragmentData;

	std::stringstream vertexBuffer;
	std::stringstream fragmentBuffer;

	string vertexDataSource;
	string fragmentDataSource;

	vertexData.open(vertexPath);

	if (vertexData.is_open())
	{
		vertexBuffer << vertexData.rdbuf();

		vertexDataSource = vertexBuffer.str();
	}

	fragmentData.open(fragmentPath);

	if (fragmentData.is_open())
	{
		fragmentBuffer << fragmentData.rdbuf();

		fragmentDataSource = fragmentBuffer.str();
	}

	const char* vertexShaderSource = vertexDataSource.c_str();
	const char* fragmentShaderSource = fragmentDataSource.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	checkForErrors(vertexShader, "SHADER", "vertex shader");

	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	checkForErrors(fragmentShader, "SHADER", "fragment shader");

	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
	checkForErrors(ID, "PROGRAM", "shader program");

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::checkForErrors(GLuint shader, string type, string name)
{
	int success;
	char infoLog[1024];

	if (type == "PROGRAM")
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);

		if (success == GL_FALSE)
		{
			glGetProgramInfoLog(shader, sizeof(infoLog), NULL, infoLog);
			std::cout << "ERROR LINKING THE PROGRAM" << std::endl;
			std::cout << infoLog << std::endl;
		}
	}
	else if (type == "SHADER")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (success == GL_FALSE)
		{
			glGetShaderInfoLog(shader, sizeof(infoLog), NULL, infoLog);
			std::cout << "ERROR COMPILING THE " << name << " SHADER" << std::endl;
			std::cout << infoLog << std::endl;
		}
	}
	else
	{
		std::cout << "ERROR INCORRECT TYPE" << std::endl;
	}
}

void Shader::use()
{
	glUseProgram(ID);
}