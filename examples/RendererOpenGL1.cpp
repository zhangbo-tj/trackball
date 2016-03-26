#include "RendererOpenGL1.h"

#include <math.h>
#include <iostream>
#include <string.h> // memcpy

#define GLM_FORCE_RADIANS
#include <glm/gtc/type_ptr.hpp> // value_ptr
#include <glm/gtc/matrix_transform.hpp> // perspective

namespace rsmz
{

RendererOpenGL1::RendererOpenGL1() : Renderer()
{
}

RendererOpenGL1::~RendererOpenGL1()
{
}

void RendererOpenGL1::init()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	// Enable transparency.
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void RendererOpenGL1::render()
{
	renderClear();
	renderObjects();
}

void RendererOpenGL1::renderCenter()
{
    glPointSize(4);
    glBegin(GL_POINTS);

    if (mCamera) {
        const glm::vec3 & p = mCamera->getCenter();
        glColor3f (1.f, 1.f, 0.f);
        glVertex3f(p.x, p.y, p.z);
    }

    glEnd();
}

void RendererOpenGL1::renderClear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
}

void RendererOpenGL1::renderObjects()
{
    glPushMatrix();
    glMultMatrixf(glm::value_ptr(mProjection));

	if (mCamera) {
		glPushMatrix();
		glMultMatrixf(mCamera->getMatrixFlat());
	}

    renderCenter();
	renderGrid();
	renderAxes();
	renderCube();

	if (mCamera) {
		glPopMatrix();
	}

    glPopMatrix();
}

void RendererOpenGL1::renderAxes()
{
	glLineWidth(2);

	glBegin(GL_LINES);
    glColor3f ( 1.f,    0.f,  0.f);
    glVertex3f( 0.0f,   0.f,  0.f);
    glVertex3f( 0.5f,   0.f,  0.f);
    glColor3f ( 0.f,    1.f,  0.f);
    glVertex3f( 0.f,    0.f,  0.f);
    glVertex3f( 0.f,   0.5f,  0.f);
    glColor3f ( 0.f,    0.f,  1.f);
    glVertex3f( 0.0f,   0.f,  0.f);
    glVertex3f( 0.f,    0.f,  0.5f);
	glEnd();
}

void RendererOpenGL1::renderCube()
{
	GLfloat alpha = .9f;

    glBegin(GL_TRIANGLES);
    glColor4f ( .8f,    0.4f,   0.4f, alpha);
    glVertex3f( 0.2f,   0.f,   0.f);
    glVertex3f( 0.2f,   0.2f,  0.f);
    glVertex3f( 0.2f,   0.2f,  0.2f);
    glVertex3f( 0.2f,   0.f,   0.f);
    glVertex3f( 0.2f,   0.f,   0.2f);
    glVertex3f( 0.2f,   0.2f,  0.2f);

    glColor4f ( .4f,    0.2f,   0.2f, alpha);
    glVertex3f( 0.f,    0.f,   0.f);
    glVertex3f( 0.f,    0.2f,  0.f);
    glVertex3f( 0.f,    0.2f,  0.2f);
    glVertex3f( 0.f,    0.f,   0.f);
    glVertex3f( 0.f,    0.f,   0.2f);
    glVertex3f( 0.f,    0.2f,  0.2f);

    glColor4f ( 0.4f,   0.8f,  0.4f, alpha);
    glVertex3f( 0.f,    0.2f,  0.f);
	glVertex3f( 0.2f,   0.2f,  0.f);
	glVertex3f( 0.2f,   0.2f,  0.2f);
    glVertex3f( 0.f,    0.2f,  0.f);
	glVertex3f( 0.f,    0.2f,  0.2f);
	glVertex3f( 0.2f,   0.2f,  0.2f);

    glColor4f ( 0.2f,   0.4f,  0.2f, alpha);
    glVertex3f( 0.f,    0.f,  0.f);
	glVertex3f( 0.2f,   0.f,  0.f);
	glVertex3f( 0.2f,   0.f,  0.2f);
    glVertex3f( 0.f,    0.f,  0.f);
	glVertex3f( 0.f,    0.f,  0.2f);
	glVertex3f( 0.2f,   0.f,  0.2f);

    glColor4f ( .4f,    .4f,   .8f, alpha);
    glVertex3f( 0.f,    0.f,   0.2f);
    glVertex3f( 0.f,    0.2f,  0.2f);
    glVertex3f( 0.2f,   0.2f,  0.2f);
    glVertex3f( 0.f,    0.f,   0.2f);
    glVertex3f( 0.2f,   0.f,   0.2f);
    glVertex3f( 0.2f,   0.2f,  0.2f);

    glColor4f ( 0.2f,   0.2f,  .4f, alpha);
    glVertex3f( 0.f,    0.f,   0.f);
    glVertex3f( 0.f,    0.2f,  0.f);
    glVertex3f( 0.2f,   0.2f,  0.f);
    glVertex3f( 0.f,    0.f,   0.f);
    glVertex3f( 0.2f,   0.f,   0.f);
    glVertex3f( 0.2f,   0.2f,  0.f);

    glEnd();
}

void RendererOpenGL1::renderGrid()
{
	float p, d = .1, mn=-1.f, mx=1.f, eps=-1e-4;
	int i, n = 20;
    #define WHITE() glColor4f(1.f, 1.f, 1.f, .2f)

	glLineWidth(1);
	glBegin(GL_LINES);

	for(i = 0; i <= n; ++i) {
		p = mn + i*d;

        if (i == 0 || i == 10 || i == n) {
            glColor4f(0.f, 1.f, 0.f, .3f);
        } else {
            WHITE();
        }
		glVertex3f(p, mn, eps);
		glVertex3f(p, mx, eps);

        if (i == 0 || i == 10 || i == n) {
            glColor4f(1.f, 0.f, 0.f, .3f);
        } else {
            WHITE();
        }
		glVertex3f(mn, p, eps);
		glVertex3f(mx, p, eps);
	}

	glEnd();
    #undef WHITE
}

void RendererOpenGL1::resize(int width, int height)
{
	if (0 == height) {
		height = 1; // Avoid division by zero.
	}

	GLfloat ratio = width / (GLfloat) height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    mProjection = glm::perspective(glm::radians(45.0f), ratio, .01f, 100.f);
}

} // end namespace rsmz

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
