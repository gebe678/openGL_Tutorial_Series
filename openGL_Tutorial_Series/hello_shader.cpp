#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

using namespace std;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

void framebufferCallback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main(){\n"
"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 fragColor;\n"
"void main(){\n"
"fragColor = vec4(1.0, 0.5, 0.2, 1.0);\n"
"}\0";

int helloShader()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Shader Example", NULL, NULL);
	glfwMakeContextCurrent(window);

	glfwSetFramebufferSizeCallback(window, framebufferCallback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "FAILED TO INITIALIZE GLAD" << endl;
		return -1;
	}

	// create and compile the vertex shader
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	// check the vertex shader for errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (success == GL_FALSE)
	{
		glGetShaderInfoLog(vertexShader, sizeof(infoLog), NULL, infoLog);
		cout << "Error compiling the vertex shader" << endl;
		cout << infoLog << endl;
	}

	// create and compile the fragment shader
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	// check to make sure the fragment shader compilation was a success
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (success == GL_FALSE)
	{
		glGetShaderInfoLog(fragmentShader, sizeof(infoLog), NULL, infoLog);
		cout << "ERROR COMPILING THE FRAGMENT SHADER" << endl;
		cout << infoLog << endl;
	}

	// link the shaders into a shader program
	unsigned int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	// check to make sure the shaders were linked successfully
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

	if (success == GL_FALSE)
	{
		glGetProgramInfoLog(shaderProgram, sizeof(infoLog), NULL, infoLog);
		cout << "ERROR LINKING THE PROGRAMS" << endl;
		cout << infoLog << endl;
	}

	// destroy the unused shaders
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	float verticies[] = 
	{
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};

	unsigned int VAO;
	unsigned int VBO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
	glEnableVertexAttribArray(0);

	// unbind the buffers
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwTerminate();

	return 0;
}

void framebufferCallback(GLFWwindow* window, int width, int height)
{
	glViewport(NULL, NULL, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}