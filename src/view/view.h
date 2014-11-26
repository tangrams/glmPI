#pragma once

#include <vector>
#include <set>
#include <cmath>
#include <memory>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class View {
public:

    View(float _width = 800, float _height = 600);
    virtual ~View(){};

    void setAspect(float _width, float _height);
    void setPosition(double _x, double _y);
    void translate(double _dx, double _dy);

    const glm::dvec3& getPosition() const { return m_pos; };
    const glm::dmat4& getViewMatrix() const { return m_view; };
    const glm::dmat4& getProjectionMatrix() const { return m_proj; };
    const glm::dmat4 getViewProjectionMatrix() const;

    glm::dmat2 getBoundsRect() const; // Returns a rectangle of the current view range as [[x_min, y_min], [x_max, y_max]]
    bool viewChanged() const { return m_dirty; };

private:
    bool m_dirty;
    glm::dvec3 m_pos;
    glm::dmat4 m_view;
    glm::dmat4 m_proj;
    float m_width;
    float m_height;
    double m_aspect;
};

