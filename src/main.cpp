#include<iostream>
#include<math.h>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"



// width and height
const unsigned int width = 800;
const unsigned int height = 800;


// verticies cordinates
float vertices[] = {
    // COORDINATES          // COLORS
    -0.5f, -0.5f, 0.0f,    1.0f, 0.0f, 0.0f,  // Lower left corner (red)
     0.5f, -0.5f, 0.0f,    0.0f, 1.0f, 0.0f,  // Lower right corner (green)
     0.0f,  0.5f, 0.0f,    0.0f, 0.0f, 1.0f   // Upper corner (blue)
};
unsigned int indices[] = {
    0, 1, 2  // triangle
};


// declaring a function where if you change the size of the window viewport changes too
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main(){
    //initialize glfw
    glfwInit();
    // choosing a major version for glfw
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    // choosing a minor version for glfw
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // choosing a profile what you want to you either CORE or COMPAT
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // creates a window                 | height | width | name | no idea | no idea |
    GLFWwindow* window = glfwCreateWindow(800, 600, "triangles", NULL, NULL);
    if(window == NULL)
    {  
        //debuging
        std::cout << "failed to create glfw window " << std::endl;
        glfwTerminate();
        // returns -1
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Load GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    gladLoadGL();
    // load GLAD so it can configure glfw
	// specify view port for the window
	// in this case view port goes from  x = 0, y = 0, to x = 800, y = 800
    // you can display other elements outside viewport basicly some type of resolution
	glViewport(0, 0, 800, 800);
    // generates Shader object using shaders defualt.vert and default.frag
    Shader shaderProgram("/home/wdkaza/Desktop/OpenGL(scary)/Recource Files/Shaders/default.vert", "/home/wdkaza/Desktop/OpenGL(scary)/Recource Files/Shaders/default.frag");

    // alrigth the other stuff now

    // generates VAO and binds it 
    VAO VAO1;
    VAO1.Bind();

    EBO EBO1(indices, sizeof(indices));

    // generates vertex buffer objects and links it to vertices
	VBO VBO1(vertices, sizeof(vertices));

    //linking vertex attributes 
    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0); // position
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));  // color

    //unbinds to not make accidental modification
	VBO1.Unbind(); 
    VAO1.Unbind();
    EBO1.Unbind();

    //glfw calls this function every time the window is resized
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    while(!glfwWindowShouldClose(window))
    {



        // rendering commands hereA
        //...

        // clears background color with those values
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // clears everything? i dont know
        glClear(GL_COLOR_BUFFER_BIT);


        shaderProgram.Activate();

        VAO1.Bind();


        //...
		glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);
        //swaps colors in a buffer? (a large 2D buffer that contains color values for each pixel in GLFW’s 
        glfwSwapBuffers(window);
        //checks if any events are triggered
        glfwPollEvents();
    }

    VAO1.Delete();
    VBO1.Delete();
	EBO1.Delete();
    shaderProgram.Delete();

    glfwTerminate();
    // returns 0
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    //changes viewport
    glViewport(0, 0, width, height);
}