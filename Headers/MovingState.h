#include <ctime>

class MovingState{
private:
    int timeForFixStopMoving;
    float positionChangeForStop;
    float positionChangeForStart;
    float lastStopPosition;
    float lastStopTimestamp;
    bool isMoving;
    bool cranePositions;

    bool isCraneStopped();
    bool isCraneMoving();
    void setLastStopPosition(time_t lastStopTimestamp, float lastStopPosition);
    bool isMoving();
    float cranePosition();
    float lastStopPosition();
    time_t lastStopTimestamp();

public:
    MovingState(int _timeForFixStopMoving = 10, float _positionChangeForStop = 3.0, float _positionChangeForStart = 3.0);
    void AddData(time_t timestamp, float cranePosition);
    ~MovingState();
};


