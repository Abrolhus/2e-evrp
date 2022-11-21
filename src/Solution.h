#ifndef INC_2E_EVRP_SOLUTION_H
#define INC_2E_EVRP_SOLUTION_H
#include <boost/container/vector.hpp>
namespace BoostC = boost::container;
#include "Satelite.h"

class Solution
{
public:
    Solution(const Instance& Inst);
    Solution(const Solution &solution);
    void copia(const Solution &solution);

    int getNSatelites() const;
    int findSatellite(int id) const;
    Satelite* getSatelite(int index);
    bool checkSolution(std::string &erro, const Instance &inst);
    void print(std::string &str,  const Instance &instance);
    void print(const Instance& Inst);
    double calcCost(const Instance&);
    float getDistanciaTotal();

    void atualizaVetSatTempoChegMax(const Instance &instance);

    // Possui numSat + 1 !!
    BoostC::vector<Satelite> satelites;
    // Guarda o ultimo tempo de chegada do veiculo do 1° nivel
    BoostC::vector<double> satTempoChegMax;
    int numTrucks;
    int numEvs;

    bool viavel = true;

    BoostC::vector<Route> primeiroNivel;

    bool mvShiftIntraRota = false;
    bool mvShiftInterRotas = false;
    bool mvCross = false;

    double distancia = 0.0;

};
#endif //INC_2E_EVRP_SOLUTION_H
