#include "app.h"

#include "GLES2/gl2.h"
#include "EGL/egl.h"
#include "EGL/eglext.h"

#include <memory>
#include <utility>
#include <cmath>

#include "platform.h"
#include "view/view.h"
#include "util/vertexLayout.h"
#include "util/vboMesh.h"
#include "util/shaderProgram.h"

std::shared_ptr<View> m_view;
std::shared_ptr<VertexLayout> m_vertexLayout;
std::shared_ptr<VboMesh> m_geometry;
std::shared_ptr<ShaderProgram> m_shaderProgram;

void initialize() {
    logMsg("%s\n", "initialize");

    // Create view
    m_view = std::make_shared<View>();

    m_vertexLayout = std::shared_ptr<VertexLayout>(new VertexLayout({
			    {"a_position",3,GL_FLOAT,false,0},
			    {"a_color",4,GL_FLOAT,false,0},
			    {"a_normal",3,GL_FLOAT,false,0},
			    {"a_texcoord",2,GL_FLOAT,false,0}
			}));
    m_geometry = std::shared_ptr<VboMesh>(new VboMesh(m_vertexLayout,GL_TRIANGLES));	

    // Set up openGL state
    glDisable(GL_BLEND);
    glDisable(GL_STENCIL_TEST);
    glEnable(GL_DEPTH_TEST);
    glClearDepthf(1.0);
    glDepthRangef(0.0, 1.0);
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    
    logMsg("%s\n", "finish initialize");   
}

void resize(int _newWidth, int _newHeight) {
    logMsg("%s\n", "resize");
    
    glViewport(0, 0, _newWidth, _newHeight);

    if (m_view) {
        m_view->setAspect(_newWidth, _newHeight);
    }
}

void update(float _dt) {
    
}

void render() {
    // Set up openGL for new frame
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // glm::dmat4 view = m_view->getViewMatrix();
    // glm::dmat4 viewProj = m_view->getViewProjectionMatrix();

    //
    //

    // TODO: This error checking is incomplete and only marginally useful
    // 1. We need to continue calling glGetError until no error states remain
    // 2. Repeating an error message 60 times per second is not useful, try to consolidate
    GLenum glError = glGetError();
    if (glError) {
        logMsg("GL Error %d!!!\n", glError);
    }
}

void teardown() {
    // TODO: Release resources!
}
