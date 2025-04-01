#include <iostream>
#include <vector>
#include <time.h>


using namespace std;

class Neuron{ 
    private:
    vector<double> inputWeights;
    double bias_;
    double output_;

    public:
    Neuron(double amountWeights = 0.0):
        inputWeights(amountWeights, 0.0), bias_(1), output_(0.0) {
            for(double &num : inputWeights){
                num = (rand() % 200 - 100) / 100.0; // Pesos entre -1.0 y 1.0
            }
        }
    
    //Operaciones para imprimir parámetros de la neurona, solo para pruebas manuales
    void printWeigths(){
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
    NeuralNetwork(unsigned int h = 3, unsigned int numOfNeurons = 3):
        input(5, Neuron(0)), midLayers(h, vector<Neuron> (numOfNeurons, Neuron(numOfNeurons))), output(2, Neuron(3)) {}

    vector<double> forward(vector<double> &inputs){
        vector<double> layerInputs = inputs;
        for(int i = 0; i < midLayers.size(); i++){
            vector<double> newInputs;
            for(int j = 0; j < midLayers[i].size(); j++){
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
    //Pruebas
    srand(time(0));

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