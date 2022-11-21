#ifndef INC_2E_EVRP_GREEDYALGORITHM_H
#define INC_2E_EVRP_GREEDYALGORITHM_H

#include "Solution.h"
#include "ViabilizadorRotaEv.h"
#include <list>
#include <boost/container/vector.hpp>
namespace BoostC = boost::container;

namespace GreedyAlgNS
{

    bool secondEchelonGreedy(Solution& Sol, const Instance& Inst, float alpha);
    void firstEchelonGreedy(Solution &Sol, const Instance &Inst, const float beta);
    void greedy(Solution &Sol, const Instance &Inst, const float alpha, const float beta);
    bool visitAllClientes(BoostC::vector<int> &visitedClients, const Instance &Inst);
    bool existeDemandaNaoAtendida(BoostC::vector<float> &demandaNaoAtendida);
    float palpiteTempoFinalPrimeiroNivel(const Instance& inst);
    bool insereEstacao(int rotaId, int satId);

    class Candidato
    {
    public:

        int rotaId = -1;
        int satelliteId = -1;
        float demand = 0.0;
        double incrementoDistancia = 0.0;
        int pos = -1;
        double tempoSaida = 0.0;

        Candidato(int _rotaId, int _satelliteId, float _demand, double _incrDist):rotaId(_rotaId), satelliteId(_satelliteId),
            demand(_demand), incrementoDistancia(_incrDist){};

        bool operator < (const Candidato &candidato) const {return incrementoDistancia < candidato.incrementoDistancia;}

    };


    class Insertion
    {
    public:

        int pos             = -1;       // Verificar se o indice rechargingS_Pos eh menor antes de inserir na solucao. O indice maior ja esta considerando +1
        int clientId        = -1;
        int routeId         = -1;
        int satId           = -1;
        float cost          = 0.0;
        float demand        = 0.0;
        NameViabRotaEv::InsercaoEstacao insercaoEstacao;

        Insertion(int pos, int clientId, float cost, float demand, float batteryCost, int routeId, int satId, int rsPos,
                  int rsId, NameViabRotaEv::InsercaoEstacao insercaoEstacao_)
        {
            this->pos = pos;
            this->clientId = clientId;
            this->cost = cost;
            this->demand = demand;
            this->routeId = routeId;
            this->satId = satId;

            if(insercaoEstacao_.distanciaRota < FLOAT_MAX)
                this->insercaoEstacao = insercaoEstacao_;
        }
        Insertion(int routeId) { this->routeId = routeId;}
        Insertion() = default;
        bool operator< (const Insertion& that) const {
            return (this->cost < that.cost);
        }
    };


    bool canInsert(EvRoute &evRoute, int node, const Instance &Instance, Insertion &insertion);
    bool canInsertSemBateria(EvRoute &evRoute, int node, const Instance &Instance, Insertion &insertion);
    bool insert(EvRoute &evRoute, Insertion& insertion, const Instance& Inst);
    bool verificaViabilidadeSatelite(double tempoChegada, Satelite &satelite, const Instance &instance, bool modficaSatelite);
}

#endif //INC_2E_EVRP_GREEDYALGORITHM_H

