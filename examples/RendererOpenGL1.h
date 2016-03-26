#ifndef RSMZ_RENDEREROPENGL1_H
#define RSMZ_RENDEREROPENGL1_H

#include "Renderer.h"
#include <GL/gl.h>

namespace rsmz
{

class RendererOpenGL1 : public Renderer
{
public:
	RendererOpenGL1();
	virtual ~RendererOpenGL1();

	void init();
	virtual void render();
	void renderAxes();
    void renderCenter();
	void renderClear();
	void renderCube();
	void renderGrid();
	void renderObjects();
	void resize(int width, int height);

protected:
    glm::mat4 mProjection;
};

} // end namespace rsmz

#endif // RSMZ_RENDEREROPENGL1_H

/*
    LICENSE BEGIN

    trackball - A 3D view interactor for C++ programs.
    Copyright (C) 2016  Remik Ziemlinski

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    LICENSE END
*/
