//
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//
//#include <iostream>
//
//void framebufferSizeCallback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//void processInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//	{
//		glfwSetWindowShouldClose(window, true);
//	}
//}
//
//const char* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"void main(){;\n"
//"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"}\0";
//
//const char* fragmentShaderSource = "#version 330 core\n"
//"out vec4 fragColor;\n"
//"void main()\n"
//"{\n"
//"fragColor = vec4(1.0, 1.0, 0.0, 1.0);\n"
//"}\0";
//
//int helloTriangle()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	
//	GLFWwindow* window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
//	
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
//		
//	// load all openGL pointers with glad
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	// set up the shader program
//	unsigned int vertexShader;
//	vertexShader = glCreateShader(GL_VERTEX_SHADER);
//
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//
//	// check for errors with the shader compilation
//	int success;
//	char infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//
//	if (!success)
//	{
//		glGetShaderInfoLog(vertexShader, sizeof(infoLog), NULL, infoLog);
//		std::cout << "ERROR WITH SHADER COMPILATION" << infoLog << std::endl;
//		glDeleteShader(vertexShader);
//	}
//	else
//	{
//		std::cout << "vertex shader compilation success" << std::endl;
//	}
//
//	// create and compile the fragment shader
//	unsigned int fragmentShader;
//	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//
//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//	glCompileShader(fragmentShader);
//
//	// check for the compilation success of the fragment shader
//	int fragmentCompileSuccess;
//	char fragmentInfoLog[512];
//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragmentCompileSuccess);
//
//	if (fragmentCompileSuccess == GL_FALSE)
//	{
//		glGetShaderInfoLog(fragmentShader, sizeof(fragmentInfoLog), NULL, fragmentInfoLog);
//		std::cout << "ERROR COMPILING THE FRAGMENT SHADER" << fragmentInfoLog << std::endl;
//		glDeleteShader(fragmentShader);
//	}
//	else
//	{
//		std::cout << "fragment shader compilation success" << std::endl;
//	}
//
//	unsigned int shaderProgram;
//	shaderProgram = glCreateProgram();
//
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//
//	if (success == GL_FALSE)
//	{
//		glGetProgramInfoLog(shaderProgram, sizeof(infoLog), NULL, infoLog);
//		std::cout << "ERROR LINKING THE SHADER PROGRAM" << std::endl;
//		glDeleteProgram(shaderProgram);
//	}
//	else
//	{
//		std::cout << "shader program linked successfully" << std::endl;
//	}
//
//	// delete the unnescassary shaders
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//
//	float verticies[] = {
//		-0.5, -0.5, 0,
//		0.5, -0.5, 0,
//		0, 0.5, 0
//	};
//
//	unsigned int VBO, VAO;
//
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//
//	// Bind the vertex buffer so all subsequent vertex object buffer calls get saved here
//	glBindVertexArray(VAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);
//
//	// configure the vertex data for drawing
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
//	glEnableVertexAttribArray(0);
//
//	// unbinding the vertex buffer and the vertex array
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//
//	while (!glfwWindowShouldClose(window))
//	{
//		processInput(window);
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glUseProgram(shaderProgram);
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glfwTerminate();
//
//	return 0;
//}
