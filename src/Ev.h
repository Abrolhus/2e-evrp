#ifndef EV_H
#include "Instance.h"
#include <vector>
#define EV_H
class EvNode{
public:
    EvNode(int nodeId, double time0, double time1, double battery) : 
            nodeId(nodeId), time0(time0), time1(time1), battery(battery){ }
    EvNode(int nodeId, double time0, double battery) : 
            nodeId(nodeId), time0(time0), battery(battery){ 
        time1 = time0;
    }
    int nodeId;
    double time0; // time before service
    double time1; // time after service (needed if recharging)
    double battery; // remaining battery
};
class Ev{
private:
    std::vector<EvNode> route;
    float totalDistance;
    int satelite;
    float totalDemand;
public:
    float getRemainingBattery(const Instance&);
    float getRemainingCapacity(const Instance&);
    const EvNode& at(int i);
    float getDemandOf(int i, const Instance& inst);
    EvNode& operator [](int pos);
};
#endif
