#include "VBO.h"

VBO::VBO(GLfloat* vertices, GLsizeiptr size){
    glGenBuffers(1, &ID); // genereting buffers for the id we made
    glBindBuffer(GL_ARRAY_BUFFER, ID); // binds the buffer to the id? i think
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW); // allocates data
}

void VBO::Bind() {
    glBindBuffer(GL_ARRAY_BUFFER, ID);  // Bind the VBO
}

void VBO::Unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);  // Unbind the VBO
}

void VBO::Delete() {
    glDeleteBuffers(1, &ID);  // Delete the VBO
}
