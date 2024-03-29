#ifndef INC_2E_EVRP_SATELITE_H
#define INC_2E_EVRP_SATELITE_H

#include <boost/container/vector.hpp>
namespace BoostC = boost::container;
#include "EvRoute.h"
#include "Instance.h"


class TempoSaidaEvRoute
{

public:
    EvRoute *evRoute;

    explicit TempoSaidaEvRoute(EvRoute *evRouteAux){evRoute = evRouteAux;}

    bool operator < (const TempoSaidaEvRoute &tempo2) const
    {
        if(evRoute->routeSize > 2 && tempo2.evRoute->routeSize <= 2)
            return true;
        else if(evRoute->routeSize <= 2 && tempo2.evRoute->routeSize > 2)
            return false;

        return evRoute->route[0].tempoSaida < tempo2.evRoute->route[0].tempoSaida;
    }
};

class Satelite {
public:
    Satelite(const Instance&, int _satId);
    int getNRoutes() const;
    EvRoute& getRoute(int i);
    bool checkSatellite(std::string &erro, const Instance &Inst);
    void print(std::string &str, const Instance &instance);
    void print(const Instance &instance);


    BoostC::vector<EvRoute> vetEvRoute;

    // O vetor deve estar ordenado antes de ser utilizado
    BoostC::vector<TempoSaidaEvRoute> vetTempoSaidaEvRoute;

    void sortVetTempoSaidaEvRoute(){std::sort(vetTempoSaidaEvRoute.begin(), vetTempoSaidaEvRoute.end());};

    int tamVetEvRoute = -1;
    int sateliteId = -1;
    float demanda = 0.0;
    double distancia = 0.0;
};
#endif //INC_2E_EVRP_SATELITE_H
