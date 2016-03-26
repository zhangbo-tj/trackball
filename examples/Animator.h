#ifndef RSMZ_ANIMATOR_H
#define RSMZ_ANIMATOR_H

#include <chrono>
#include "TrackBallInteractor.h"

namespace rsmz
{

class Animator
{
public:
    typedef enum AnimationType {
        NONE, FIRST_PERSON, ORBIT, PAN, ROLL, ZOOM
    } AnimationType;

    Animator();
    ~Animator();

    void animate();
    double elapsedSeconds();
    void firstperson();
    void orbit();
    void pan();
    void reset();
    void roll();
    void setAnimation(AnimationType type);
    void setScreenSize(int w, int h);
    void setInteractor(TrackBallInteractor *i);
    void stopwatch();
    void zoom();

private:
    AnimationType mAnimation;
    TrackBallInteractor *mInteractor;
    int mFrame;
    int mFrames;
    float mFramesPerSecond;
    int mHeight;
    std::chrono::time_point<std::chrono::system_clock> mTic;
    int mWidth;
};


}
#endif // RSMZ_ANIMATOR_H

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
