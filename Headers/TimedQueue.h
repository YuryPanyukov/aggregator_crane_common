#include <ctime>
#include <queue>

template<typename Type>
class TimedQueue{
    private:
        int timeWindow;
        std::queue<time_t> timestamps;
        std::queue<Type> values;
        void pruneQueue();
    public:
        TimedQueue(int _timeWindow);
        ~TimedQueue() {}
        void addData(time_t timestamp, Type value);
        void clear();
};

template <typename Type>
inline void TimedQueue<Type>::pruneQueue(){
    while(!timestamps.empty()){
        time_t& lastTimestamp = timestamps.front();
        time_t& currentTimestamp = timestamps.back();
        if (currentTimestamp - lastTimestamp > timeWindow){
            timestamps.pop();
            values.pop();
        }else{
            break;
        }
    }
    
}

template <typename Type>
inline TimedQueue<Type>::TimedQueue(int _timeWindow)
{
    timeWindow = _timeWindow;
}

template <typename Type>
inline void TimedQueue<Type>::addData(time_t timestamp, Type value){
    timestamps.push(timestamp);
    values.push(value);

    pruneQueue();
}
