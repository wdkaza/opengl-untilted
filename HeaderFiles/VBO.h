#ifndef VBO_H
#define VBO_H
// VBO = vertex buffer objects

#include <glad/glad.h>

// vertex buffer objects class
class VBO {
public:
    // id of the VBO
    GLuint ID;

    // Constructor: Creates a VBO and uploads vertex data to it
    // Parameters:
    // - vertices: Pointer to an array of vertex data
    // - size: The size (in bytes) of the vertex data array
    VBO(GLfloat* vertices, GLsizeiptr size);
    // bindinding so it can be used in current context
    void Bind();
    // unbinding to prevent accidental modification
    void Unbind();
    // deletes vbo from gpu memory
    void Delete();
};

#endif