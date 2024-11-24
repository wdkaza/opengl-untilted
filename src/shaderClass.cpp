#include"shaderClass.h"

// reads a text file and outputs a string with everything in the text file
std::string get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
    // read file content and convert it into strings
    std::string vertexCode = get_file_contents(vertexFile);
    std::string fragmentCode = get_file_contents(fragmentFile);

    // convers shaders soruce into character arrays
    const char* vertexSource = vertexCode.c_str();
    const char* fragmentSource = fragmentCode.c_str();

    // creates vertex shader and gets its reference
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

    // attaches vertex shader source to vertex shader object
    glShaderSource(vertexShader, 1, &vertexSource, NULL);

    // compiling into machine code
	glCompileShader(vertexShader);

    // creates fragment shader and compiles it into code
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    // attaches fragment shader source to fragment shader object
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);

    // compiles fragment shader into machine code
    glCompileShader(fragmentShader);

    // creating the id 
    ID = glCreateProgram();

    // attaches vertex and fragment shaders to shader programms
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);

    // wrapping everything into shader program
    glLinkProgram(ID);

    // deletes shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}
// activates shader
void Shader::Activate()
{
	glUseProgram(ID);
}

// deletes shader
void Shader::Delete()
{
	glDeleteProgram(ID);
}
