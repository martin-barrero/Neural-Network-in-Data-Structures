#include <iostream>
#include <vector>
#include <time.h>
#include <random>


using namespace std;

static random_device rd; 
static mt19937 gen(rd()); 

double randomFloat(double min, double max) {
    uniform_real_distribution<double> dis(min, max);
    return dis(gen);
}

class Neuron{ 
    private:
    vector<double> inputWeights;
    double bias_;
    double output_;

    public:
    Neuron(double amountWeights = 0.0):
        inputWeights(amountWeights, 0.0), bias_(1), output_(0.0) {
            for(double &numero : inputWeights){
                numero = randomFloat(0.0, 1.0);
            }
        }
    
    //Operaciones para imprimir parámetros de la neurona, solo para pruebas manuales
    void printWeigths(int i, int j){
        cout << "Capa: " << i << " Neurona: " << j << " " ;
        for(double c : inputWeights){
            cout << c << " ";
        }
        cout << endl;
    }

    void printBias(){
        cout << "bias: " << bias_ << endl;
    }

    //Operacion activacion ReLu
    double activationReLu(double value){
        if (value > 0) return value;
        else return 0;
    }

    //Operacion cálculo output de la neurona
    double calculateOutputValue(vector<double> &inputValues){ 
        double summation = 0.0;
        for(int i = 0; i < inputWeights.size(); i++){
            double iteration = inputValues[i] * inputWeights[i];
            summation += iteration;
        }
        summation += bias_;
        output_ = activationReLu(summation);
        return output_;
    }
};

//Clase Principal
class NeuralNetwork {
    private:
    vector<Neuron> input;
    vector<vector<Neuron>> midLayers;
    vector<Neuron> output;

    public:
    NeuralNetwork(unsigned int h = 3, unsigned int numOfNeurons = 3){
        for(int i = 0; i < 5; i++){
            input.push_back(Neuron(0));
        }

        for(int i = 0; i < h; i++){
            vector<Neuron> layer;
            for(int j = 0; j < numOfNeurons; j++){
                layer.push_back(Neuron(3));
            }
            midLayers.push_back(layer);
        }

        for(int i = 0; i < 2; i++){
            output.push_back(Neuron(3));
        }
    }

    vector<double> forward(vector<double> &inputs){
        vector<double> layerInputs = inputs;
        for(int i = 0; i < midLayers.size(); i++){
            vector<double> newInputs;
            for(int j = 0; j < midLayers[i].size(); j++){
                midLayers[i][j].printWeigths(i, j);
                newInputs.push_back(midLayers[i][j].calculateOutputValue(layerInputs));
            }
            layerInputs = newInputs;
        }
        vector<double> outputs;
        for(int i = 0; i < output.size(); i++){
            outputs.push_back(output[i].calculateOutputValue(layerInputs));
        }
        return outputs;
    }
    
};

int main(){
    vector<double> inputs = {1, 2, 1, 4, 2};
    NeuralNetwork prueba;

    vector<double> outputValues = prueba.forward(inputs);
    
    cout << "Salidas de la red neuronal:" << endl;
    for (double val : outputValues) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}