#include "Ev.h"
float Ev::getRemainingBattery(const Instance& inst)
{
    return 0.0;
}
float Ev::getRemainingCapacity(const Instance& inst)
{
    return inst.getEvCap() - this->totalDemand;
}
float Ev::getDemandOf(int i, const Instance& inst)
{
    return inst.getDemand(this->route.at(i).nodeId); // get demand of nodeId
}
const EvNode& Ev::at(int i)
{
    return this->route.at(i);
}
EvNode& Ev::operator[](int pos)
{
    return route.at(pos);
}
