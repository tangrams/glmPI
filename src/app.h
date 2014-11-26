#pragma once

#include "platform.h"

// Create resources and initialize the map view
void initialize();

// Resize the map view to a new width and height (in pixels)
void resize(int _newWidth, int _newHeight);

// Update the map state with the time interval since the last update
void update(float _dt);

// Render a new frame of the map view (if needed)
void render();

// Release resources and shut down renderer
void teardown();