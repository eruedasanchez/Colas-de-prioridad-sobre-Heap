
template<class T>
ColaPrior<T>::ColaPrior() : _colaPrior(), _tam(0) {
	// COMPLETAR
    /** Inicializacion de una cola de prioridad vacia **/
}

template<class T>
int ColaPrior<T>::tam() const {
	// COMPLETAR
    return _tam;
}

template<class T>
void ColaPrior<T>::encolar(const T& elem) {
	// COMPLETAR
    _colaPrior.push_back(elem);
    siftUp(_colaPrior,_colaPrior.size()-1);
    _tam++;
}

template<class T>
void ColaPrior<T>::siftUp(vector<T> &cprior, int index){
    if(index != 0 && cprior[index] > cprior[padre(index)]){
        swap(cprior[index],cprior[padre(index)]);
        siftUp(cprior, padre(index));
    }
}

template<class T>
const T& ColaPrior<T>::proximo() const {
	// COMPLETAR
    return _colaPrior.front();
}

template<class T>
void ColaPrior<T>::desencolar() {
	    // COMPLETAR
        swap(_colaPrior.front(),_colaPrior.back());
        _colaPrior.pop_back();                                            // Se borra el ultimo elemento del vector
        _tam--;
        int index = 0;

        // Se reubica el elemento que se encontabra al final del vector para que se preserve el invariante de heap
        while(!esHoja(_colaPrior, index)){
            T maximo = _colaPrior[hijoIzquierdo(index)];
            int indiceMax = hijoIzquierdo(index);
            if(tieneHijoDerecho(_colaPrior,index)){
                maximo = max(_colaPrior[hijoDerecho(index)],_colaPrior[hijoIzquierdo(index)]);
                if(_colaPrior[hijoDerecho(index)] > _colaPrior[hijoIzquierdo(index)]){
                    indiceMax = hijoDerecho(index);
                }
            }

            if(maximo > _colaPrior[index]){
                swap(maximo,_colaPrior[index]);
                index = indiceMax;
            }
    }
}

template<class T>
bool ColaPrior<T>::tieneHijoDerecho(vector<T> &cprior, int index){
    if(hijoDerecho(index) < cprior.size()){
        return true;
    } else {
        return false;
    }
}

template<class T>
bool ColaPrior<T>::esHoja(vector<T> &cprior, int index){
    if(hijoDerecho(index) >= cprior.size() && hijoIzquierdo(index) >= cprior.size()){
        return true;
    } else {
        return false;
    }
}

template<class T>
ColaPrior<T>::ColaPrior(const vector<T>& elems) {
	// COMPLETAR
}

template <typename T>
int ColaPrior<T>::hijoIzquierdo(int indice) {
    return 2 * indice + 1;
}

template <typename T>
int ColaPrior<T>::hijoDerecho(int indice) {
    return 2 * indice + 2;
}

template <typename T>
int ColaPrior<T>::padre(int indice) {
    return (indice-1) / 2;
}



