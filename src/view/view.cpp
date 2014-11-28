#include "view.h"
#include "glm/gtx/string_cast.hpp"

View::View(float _width, float _height) {    
    // Set up projection matrix based on input width and height with an arbitrary zoom
    setAspect(_width, _height);

    // Set up view matrix
    m_pos = glm::dvec3(0, 0, 1000); // Start at 0 to begin
    glm::dvec3 direction = glm::dvec3(0, 0, -1); // Look straight down
    glm::dvec3 up = glm::dvec3(0, 1, 0); // Y-axis is 'up'
    m_view = glm::lookAt(m_pos, m_pos + direction, up);
}

void View::setAspect(float _width, float _height) {
    m_aspect = _width / _height;
    m_dirty = true;
}

void View::setPosition(double _x, double _y) {
    translate(_x - m_pos.x, _y - m_pos.y);
    m_dirty = true;
}

void View::translate(double _dx, double _dy) {
    m_pos.x += _dx;
    m_pos.y += _dy;
    m_view = glm::lookAt(m_pos, m_pos + glm::dvec3(0, 0, -1), glm::dvec3(0, 1, 0));
    m_dirty = true;
}

const glm::dmat4 View::getViewProjectionMatrix() const {
    return m_proj * m_view;
}

glm::dmat2 View::getBoundsRect() const {
    double hw = m_width * 0.5;
    double hh = m_height * 0.5;
    return glm::dmat2(m_pos.x - hw, m_pos.y - hh, m_pos.x + hw, m_pos.y + hh);
}
