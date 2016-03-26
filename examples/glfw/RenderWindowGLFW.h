#ifndef RSMZ_RENDERWINDOWGLFW_H
#define RSMZ_RENDERWINDOWGLFW_H

#include <GLFW/glfw3.h>

#include "TrackBallInteractor.h"
#include "RendererOpenGL1.h"
#include "Animator.h"

namespace rsmz
{
/**
 * Example using GLFW.
 * Only one window instance is supported, but this could be extended by
 * using a registry class to scale the static callback handlers.
 */
class RenderWindowGLFW
{
public:
    RenderWindowGLFW();
    ~RenderWindowGLFW();

	static RenderWindowGLFW & instance();
	int run(int width, int height);

	static void buttonCallback(GLFWwindow *window, int button, int action,
                               int mods);
	static void errorCallback(int error, const char* description);
	static void keyCallback(GLFWwindow *window, int key, int scancode,
                            int action, int mods);
	static void moveCallback(GLFWwindow *window, double xpos, double ypos);
	static void scrollCallback(GLFWwindow *window, double xpos, double ypos);
	static void sizeCallback(GLFWwindow *window, int width, int height);

private:
    Animator mAnimator;
	Camera mCamera;
	TrackBallInteractor mInteractor;
	RendererOpenGL1 mRenderer;
    GLFWwindow *mWindow;
};

} // end namespace rsmz

#endif // RSMZ_RENDERWINDOWGLFW_H

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
