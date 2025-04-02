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
class RedNeuronalBST1{
    private:
        class Neurona1{
            public:
            unsigned int id;
            double bias;
            vector<double> weights;
            Neurona1* left;
            Neurona1* right;

            public:
            Neurona1(unsigned int i, double b, vector<double> w){
                id = i;
                bias = b;
                weights = w;
                left = nullptr;
                right = nullptr;
            }
        };

        Neurona1* root;

        public:
        // Constructor basico (sin parametros para inciar en una red vacia)
        RedNeuronalBST1(){
            root = nullptr;
        }
};

class RedNeuronalBST {
    private:
        class Neurona {
        public:
            string id;  // Cambiamos a string para el formato jerárquico
            double bias;
            vector<double> weights;
            Neurona* left;
            Neurona* right;
    
            Neurona(string i, double b, vector<double> w){
                id = i;
                bias = b;
                weights = w;
                left = nullptr;
                right = nullptr;
            }
        };
    
        Neurona* root;
        vector<int> contadorPorCapa;  // Para generar IDs automáticos relacionados con la capa correspndiente 
    
    public:
        RedNeuronalBST(){
            root = nullptr;
        }
    
    private:
        // Genera ID jerárquico (ej: "0-3" para 4ta neurona en capa 0) (empieza en "0-0") capa-inidice
        string generarID(int capa) {
            if (capa >= contadorPorCapa.size()) {
                contadorPorCapa.resize(capa + 1, 0); // hacemos el resize y en esa nueva posicion se empieza en 0
            }
            return to_string(capa) + "-" + to_string(contadorPorCapa[capa]++); // convierte el numero a un char y une todo ahi en un string (ahora si analisa el key lexicograficamente como dijo gustavo)
        }

        void inOrder(Neurona* nodo) {
            if (!nodo) return; // no hay nd
            inOrder(nodo->left); // primero se va por la izquierda
            cout << "ID: " << nodo->id 
                 << " | Bias: " << nodo->bias 
                 << " | Pesos: { ";
            for (double w : nodo->weights){ // itera sobre los elementos edl vector de pesos para mostrarlos
                cout << w << " ";
            }
            cout << "}"; 
            cout << endl;
            inOrder(nodo->right); // ahora lo mismo pero por la derecha
        }
    
    public:
        // Inserta una neurona en el BST (ordenado por ID string)
        void insertarNeurona(int capa, double bias, vector<double> weights) {
            string nuevoID = generarID(capa);
            Neurona* nueva = new Neurona(nuevoID, bias, weights);
    
            if (!root) { // arbol vacio
                root = nueva;
            } else {
                Neurona* current = root;
                while (true) {
                    if (nuevoID < current->id) {  // Comparación lexicográfica
                        if (!current->left) { // si no hay hijo izq
                            current->left = nueva; // se inserta aca
                            break; // chao me fui
                        }
                        current = current->left; // sino se mueve al hijo izquierdo
                    } else {
                        if (!current->right) { // si no hay hijo der
                            current->right = nueva; // se inserta aca
                            break; // chao por aca
                        }
                        current = current->right; // sino se mueve al hijo derecho
                    }
                }
            }
            cout << "Neurona insertada - ID: " << nuevoID << endl; // NOTA: aca no valide lo de si el ID es igual porque siempre se van a crear diferentes
        }
    
        // Recorrido para mostrar el árbol ordenado
        void mostrarRed() {
            cout << "Red Neuronal (BST in-order):" << endl;
            inOrder(root);
        }
    };
    
    // Ejemplo de uso
    int main() {
        RedNeuronalBST red;

        // Insertar neuronas de prueba
        red.insertarNeurona(1, 0.1, {0.5, 0.3});    // Capa 1, Neurona 0
        red.insertarNeurona(0, 0.2, {0.1, 0.9});    // Capa 0, Neurona 0
        red.insertarNeurona(2, 0.3, {0.4});         // Capa 2, Neurona 0
        red.insertarNeurona(0, 0.4, {0.7, 0.2});    // Capa 0, Neurona 1
        red.insertarNeurona(1, 0.5, {0.6, 0.8});    // Capa 1, Neurona 1
    
        // Mostrar el árbol ordenado por ID
        red.mostrarRed();
        
        return 0;
    }