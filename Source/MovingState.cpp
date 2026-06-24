#include "MovingState.h"

MovingState::MovingState(int _timeForFixStopMoving = 10, float _positionChangeForStop = 3.0, float _positionChangeForStart = 3.0)
{
}

MovingState::~MovingState()
{
}

bool MovingState::isCraneStopped()
{
    return false;
}

bool MovingState::isCraneMoving()
{
    return false;
}

void MovingState::setLastStopPosition(time_t lastStopTimestamp, float lastStopPosition)
{
}

bool MovingState::isMoving()
{
    return false;
}

float MovingState::cranePosition()
{
    return 0.0f;
}

float MovingState::lastStopPosition()
{
    return 0.0f;
}

time_t MovingState::lastStopTimestamp()
{
    return time_t();
}
