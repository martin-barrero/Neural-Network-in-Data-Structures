#include <iostream>
#include <vector>

using namespace std;

class Neuron{ 
    private:
    vector<double> inputWeights;
    double bias_;
    double output_;

    public:
    Neuron(double amountWeights = 0.0):
        inputWeights(amountWeights, 0.0), bias_(1), output_(0.0) {}

    //Esta operacion no es demasiado eficiente pero es solamente para pruebas, luego se puede desarrollar una idea mejor en otras versiones del código
    void inicializateNeuronWeights(vector<double> &weights){ //Pasa unos pesos dados al vector de inputWeigths de la neurona
        for(int i = 0; i < weights.size(); i++){
            inputWeights[i] = weights[i];
        }
    }
    
    //Operaciones para imprimir parámetros de la neurona, solo para pruebas manuales
    void printWeigths(){
        for(int c : inputWeights){
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
        return activationReLu(summation);
    }
};

//Clase Principal
class NeuralNetwork {
    private:
    vector<Neuron> input;
    vector<vector<Neuron>> midLayers;
    vector<Neuron> output;

    public:
    NeuralNetwork(vector<double> &firstWeights, unsigned int h, unsigned int numOfNeurons = 5):
        input(10, Neuron(0)), midLayers(5, vector<Neuron> (5, Neuron(3))), output(2, Neuron(3)) {}
};

int main(){
    //Pruebas
    vector<double> weights = {1, 2, 3};
    vector<double> inputs = {4, 2, 2};
    Neuron prueba(3);

    prueba.inicializateNeuronWeights(weights);
    prueba.printBias();
    prueba.printWeigths();

    double pruebaOutput = prueba.calculateOutputValue(inputs);
    cout << pruebaOutput << endl;
    return 0;
}