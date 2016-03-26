#include "Animator.h"

namespace rsmz
{

Animator::Animator() :
    mAnimation(NONE),
    mFrame(0),
    mFrames(0),
    mFramesPerSecond(30.),
    mHeight(0),
    mInteractor(0),
    mWidth(0)
{
    stopwatch();
}

Animator::~Animator()
{
}

void Animator::animate()
{
    if (elapsedSeconds() < 1.0 / mFramesPerSecond) {
        return;
    }

    switch(mAnimation) {
        case FIRST_PERSON:
            firstperson();
            break;
        case ORBIT:
            orbit();
            break;
        case PAN:
            pan();
            break;
        case ROLL:
            roll();
            break;
        case ZOOM:
            zoom();
            break;
        case NONE: default:
            return;
            break;
    }

    stopwatch();
}

double Animator::elapsedSeconds()
{
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    std::chrono::duration<double> seconds = now - mTic;
    return seconds.count();
}

void Animator::firstperson()
{
}

void Animator::orbit()
{
    Camera *c = mInteractor->getCamera();

    if (0 == mFrame) {
        mFrames = 5 * mFramesPerSecond;
        c->setEye(1., 1., 1.);
        c->setUp(-0., -0., 1.);
        c->setCenter(0, 0, 0);
        c->update();
        mInteractor->setCamera(c);
    }

    double x = fmod(mFrame*4, mWidth);
    double y = mHeight * .74;
    mInteractor->setLeftClicked(true);
    mInteractor->setClickPoint(x, y);

    if (++mFrame >= mFrames) {
        mInteractor->setLeftClicked(false);
        reset();
    }
}

void Animator::pan()
{
}

void Animator::reset()
{
    mAnimation = NONE;
    mFrame = 0;
}

void Animator::roll()
{
}

void Animator::setAnimation(AnimationType type)
{
    mAnimation = type;
}

void Animator::setInteractor(TrackBallInteractor *i)
{
    mInteractor = i;
}

void Animator::setScreenSize(int w, int h)
{
    mWidth = w;
    mHeight = h;
}

void Animator::stopwatch()
{
    mTic = std::chrono::system_clock::now();
}

void Animator::zoom()
{
}

}

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
