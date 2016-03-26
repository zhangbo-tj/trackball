#ifndef RSMZ_RENDERER_H
#define RSMZ_RENDERER_H

#include <GL/gl.h>
#include "Camera.h"

namespace rsmz
{
class Renderer
{
public:
	Renderer();
	virtual ~Renderer();

	virtual void render() = 0;

	void setCamera(Camera *c);
    const Camera* getCamera();

protected:
	Camera *mCamera;

}; // end class Renderer

} // end namespace rsmz

#endif // RSMZ_RENDERER_H

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
