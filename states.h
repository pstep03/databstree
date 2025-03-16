#ifndef STATES_H
#define STATES_H

#include<unordered_set>
#include<string>

class checkState{
    public:
        static bool stateExists(const std::string& state);
};

#endif //STATES_H