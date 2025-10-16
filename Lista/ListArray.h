#ifndef LISTARRAY_H
#define LISTARRAY_H

#include "List.h"
#include <iostream>
#include <stdexcept>
template <typename T>

class ListArray: public List<T>{
	private:
		T*arr;		//puntero al incicio del array, tipo T genérico
		int n;		//número de elementos del array
		int max;	//tamaño actual del array
		static const int MIN:SIZE=2;	//tamaño mínimo del array

		void resize(int new_size){	//redimensionar el array
			T*new_arr= new T[new_size];

		}
	public:

};
