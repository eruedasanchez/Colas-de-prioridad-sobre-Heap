
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
    if(_colaPrior.size() == 0){
        /** Caso 1: Heap vacio **/
        _colaPrior[0] = elem;
        _tam = _tam + 1;
        return;
    }
}

template<class T>
const T& ColaPrior<T>::proximo() const {
	// COMPLETAR
    return _colaPrior[0];
}

template<class T>
void ColaPrior<T>::desencolar() {
	// COMPLETAR
    if(_colaPrior.size() == 1){
        /** CASO 1: La cola de prioridad tiene un solo elemento **/
        _colaPrior.pop_back(_colaPrior.back());
        _tam = 0;
    } else {
        /** CASO 2: La cola de prioridad tiene maas de un elemento **/
        intercambiar(_colaPrior, 0, _colaPrior.size()-1);
        _colaPrior.pop_back(_colaPrior.back());                            // Se borra el ultimo elemento del vector
        siftDown(_colaPrior, 0);                                 // Se reubica el elemento que se encontabra al final del vector para que se preserve el invariante de heap
    }
    return;
}

template<class T>
void ColaPrior<T>::intercambiar(vector<T> &cprior, int index1, int index2){
    T tmp = cprior[index1];
    cprior[index1] = cprior[index2];
    cprior[index2] = tmp;
}

template<class T>
void ColaPrior<T>::siftDown(vector<T> &cprior, int index){
    if(!esHoja(cprior, index)){
        T maximo = cprior[hijoIzquierdo(index)];
        int indiceMax = hijoIzquierdo(index);
        if(tieneHijoDerecho(cprior,index)){
            maximo = max(cprior[hijoDerecho(index)],cprior[hijoIzquierdo(index)]);
            indiceMax = max(hijoDerecho(index),hijoIzquierdo(index));
        }

        if(maximo > cprior[index]){
            swap(cprior[index],maximo);
            siftDown(cprior,indiceMax);
        }
    }
    return;
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
    vector<T> colaPrioridad(elems.size());

    /** Se agregan los elementos al vector respetando el invariante de heap **/
    for(T elem: elems){
        colaPrioridad.push_back(elem);
    }
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



