#include <ctime>
#include "TimedQueue.h"

class MovingState{
private:
    int timeForFixStopMoving;
    float positionChangeForStop;
    float positionChangeForStart;
    
    float lastStopPosition = -1.0;

    time_t lastStopTimestampValue;
    time_t lastStartTimestampValue;
    bool isMoving;
    TimedQueue<float>* cranePositions;

    bool isCraneStopped();
    bool isCraneMoving();
    void setLastStopPosition(time_t lastStopTimestamp, float lastStopPosition);
    bool getIsMoving();
    float cranePosition();
    float getLastStopPosition();
    time_t lastStopTimestamp();

public:
    MovingState(int _timeForFixStopMoving = 10, float _positionChangeForStop = 3.0, float _positionChangeForStart = 3.0);
    void AddData(time_t timestamp, float cranePosition);
    ~MovingState();
};


