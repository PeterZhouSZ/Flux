#pragma once

#include "Util/Matrix4f.h"
#include "Util/Vector3f.h"

#include <glad/glad.h>

#include <vector>

namespace Flux {
    class Framebuffer;
    class Shader;
    class Entity;
    class Transform;
    class Camera;

    enum Capability {
        BLENDING = GL_BLEND,
        FACE_CULLING = GL_CULL_FACE,
        DEPTH_TEST = GL_DEPTH_TEST,
        STENCIL_TEST = GL_STENCIL_TEST,
        POLYGON_OFFSET = GL_POLYGON_OFFSET_FILL
    };

    class RenderState {
    public:
        RenderState() :
            clearColor(1, 0, 1),
            projMatrix(),
            viewMatrix(),
            modelMatrix()
        {
            glGenVertexArrays(1, &quadVao);
        }

        void enable(Capability capability);
        void disable(Capability capability);
        void setClearColor(float r, float g, float b, float a);
        
        void drawQuad() const;
        void setCamera(Shader& shader, Entity& camera);
        void setCamera(Shader& shader, Transform& t, Camera& cam);

        Matrix4f projMatrix;
        Matrix4f viewMatrix;
        Matrix4f modelMatrix;

        static GLuint quadVao;

        static const Framebuffer* currentFramebuffer;

        static GLuint getActiveTexture();
        static void setActiveTexture(unsigned int textureUnit);
        static void bindTexture(GLenum target, GLuint texture);

        static std::vector<unsigned int> textureUnits;
        
    private:
        Vector3f clearColor;

        static unsigned int activeTextureUnit;
    };
}
