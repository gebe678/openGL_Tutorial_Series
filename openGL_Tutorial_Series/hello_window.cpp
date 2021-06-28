//// libraries for using openGL
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//
//#include <iostream>
//
//void framebufferSizeCallback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
//int helloWindow()
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
//	// render loop
//	while (!glfwWindowShouldClose(window))
//	{
//		processInput(window);
//
//		// render
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glfwTerminate();
//	return 0;
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
//void framebufferSizeCallback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}