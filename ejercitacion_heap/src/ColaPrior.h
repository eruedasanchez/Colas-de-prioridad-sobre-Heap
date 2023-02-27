#ifndef _COLAPRIOR_H_
#define _COLAPRIOR_H_

#include <vector>

using namespace std;

/* La clase T debe tener definido un operator< que implemente una relación de orden total. */
template<class T>
class ColaPrior {
public:
	ColaPrior();

	// Cantidad de elementos en la cola.
	int tam() const;

	// Encola un elemento.
	//
	// Nota: si se implementa usando un vector, es O(n) en peor caso.
	//
	void encolar(const T& elem);

	// Devuelve el elemento de mayor prioridad.
	// Pre: tam() > 0
	const T& proximo() const;

	// Saca el elemento de mayor prioridad.
	//
	// Nota: si se implementa usando un vector, es O(n) en peor caso.
	//
	// Pre: tam() > 0
	void desencolar();

	// Constructor que hace heapify.
	ColaPrior(const vector<T>& elems);

private:
	// COMPLETAR
    vector<T> _colaPrior;
    int _tam;

    /** Retorna la posicion del hijo izquierdo dado un indice **/
    int hijoIzquierdo(int indice);

    /** Retorna la posicion del hijo derecho dado un indice **/
    int hijoDerecho(int indice);

    /** Retorna la posicion del padre dado un indice **/
    int padre(int indice);

    /** Intercambia los elementos indicados en index1 y en index2 en el vector cprior **/
    void intercambiar(vector<T> &cprior, int index1, int index2);

    /** Intercambia los elementos indicados en index1 y en index2 en el vector cprior **/
    void siftDown(vector<T> &cprior, int index);

    /** Chequea si un indice tiene hijo derecho **/
    bool ColaPrior<T>::tieneHijoDerecho(vector<T> &cprior, int index);

    /** Chequea si el indice pasado por parametro representa una hoja en la cola de prioridad **/
    bool esHoja(vector<T> &cprior, int index);
};

#include "ColaPrior.hpp"

#endif /*_COLAPRIOR_H_*/
