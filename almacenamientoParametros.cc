#include <iostream>
#include <vector>

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


int main(){
    return 0;
}