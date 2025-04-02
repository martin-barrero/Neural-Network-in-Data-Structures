#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//Estructuras de datos mediante las cuales podriamos representar los parametros de una red neuronal (bias y pesos)
// PRIMERA OPCION
class Neuron{ 
    private:
        vector<double> Inputweights;
        double bias_;
        double output_;

    public:
    Neuron(unsigned int amountWeights):
        Inputweights(amountWeights, 0.0), bias_(0.0), output_(0.0) {}
};

// SEGUNDA OPCION
class RedNeuronalBST{
    private:
        class Neurona{
            public:
            unisgned int id;
            double bias;
            vector<double> weights;
            Neurona* left
            Neurona* right;

            public:
            Neurona(unsigned int i, double b, vector<double> w){
                id = i;
                bias = b;
                weights = w;
                left = nullptr;
                right = nullptr;
            }
        };

        Neurona* root;

        public:
        // Constructor basico (sin parametros para inciar en una red vacia)
        RedNeuronalBST(){
            root = nullptr;
        }
};


int main(){
    return 0;
}