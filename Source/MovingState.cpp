#include <algorithm>

#include "include/MovingState.h"

MovingState::MovingState(int _timeForFixStopMoving = 10, float _positionChangeForStop = 3.0, float _positionChangeForStart = 3.0){
    timeForFixStopMoving = _timeForFixStopMoving;
    positionChangeForStop = _positionChangeForStop;
    positionChangeForStart = _positionChangeForStart;

    // cranePositions = new TimedQueue<float>(timeForFixStopMoving);

    isMoving = false;
    lastStopTimestampValue = 0.0;
}

void MovingState::AddData(time_t timestamp, float cranePosition){
    cranePositions->addData(timestamp, cranePosition);

    if (isMoving == true){
        if (isCraneStopped()){
            isMoving = false;
            lastStopPosition = cranePosition;
            lastStopTimestampValue = timestamp;
        }
    }else{
        if (isCraneMoving()){
            isMoving = true;
            lastStartTimestampValue = timestamp;
        }
    }   

}

MovingState::~MovingState(){
    // delete cranePositions;
}

bool MovingState::isCraneStopped(){
    const std::vector<float>& values = cranePositions->getValues();

    std::vector<float>::const_iterator max_value = std::max_element(values.begin(), values.end());
    std::vector<float>::const_iterator min_value = std::min_element(values.begin(), values.end());

    return max_value - min_value < positionChangeForStop;
}

bool MovingState::isCraneMoving(){
    const std::vector<float>& values = cranePositions->getValues();

    const float& last_value = values.back();

    return abs(last_value - lastStopPosition) > positionChangeForStart;
}

void MovingState::setLastStopPosition(time_t lastStopTimestamp, float lastStopPosition)
{
}

bool MovingState::getIsMoving()
{
    return isMoving;
}

float MovingState::cranePosition()
{
    return 0.0f;
}

float MovingState::getLastStopPosition()
{
    return 0.0f;
}

time_t MovingState::lastStopTimestamp()
{
    return time_t();
}
