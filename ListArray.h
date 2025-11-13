#ifndef LISTARRAY_H
#define LISTARRAY_H

#include "List.h"
#include <ostream>

template <typename T>
class ListArray: public List<T>{
	private:
		T*arr;	//puntero hacia el inicio del array, tipo T genérico
		int n;	//números de elementos del array
		int max; //tamaño actual del array

		static const int MIN_SIZE=2;	//tamaño mínimo del array


		void resize(int new_size){	//redimensionar el array
			T*new_arr= new T[new_size];
		}

	public:
//método constructor
		ListArray(){	//reserva memoria dinámica para crear ...
			arr=new T[MIN_SIZE];	//nuevo array elementos tipo T
			//inicializar atributos
			n=0;		
			max=MIN_SIZE;
		}		
//método destructor
		~ListArray(){	//libera memoria dinámica reservada
			//liberar memoria dinámica
			delete [] arr;
		}

		
		
		//métodos de List.h

		void insert(int pos,const T& e) override{	//inserta elemento e en la posicion pos
			//ver si está dentro del rango
			if(pos<0||pos>n){	//está fuera-> excepción
				throw std::out_of_range("Posición fuera de rango.");
			}
			
			else{	//dentro del rango
				if(n==max){	//si tiene el tamaño máximo
					resize(max*2);	//ampliar tamaño
				}
			}
				//desplazar elementos->derecha
				for(int i=n;i>pos; --i){
					arr[i]=arr[i-1];
				}
				arr[pos]=e;	//insertar nuevo elemento
				n++;
		}

		void append(T e)override{	//insertar al final
			insert(n, e);
		}

		void prepend(T e)override{	//insertar al principio
			insert(0,e);
		}

		T remove(int pos)override{	//elimina y devuelve el elemento situado en la posicion pos
			//verificar si está en el rango
			if(pos<0||pos>n){
			//excepcion
				throw std::out_of_range("Posición fuera de rango.");	
			}
			else{	//dentro del rango
				T remove= arr[pos];	//guardar valor que voy a eliminar
				for(int i=pos; i<n-1; i++){	//desplazar elementos->izquierda
					arr[i]= arr[i+1];
				}	
				//actualizar tamaño del array
				n--;
				//devolver valor eliminado
				return remove;
			}
		} 

		T get(int pos)override{		//devuelve el elemento situado en la posicion pos
			//verificar si está en el rango permitido
			if(pos<0|pos>n){	//fuera del rango
				throw std:: out_of_range("Posición fuera de rango.");
			}
			else{
				return arr[pos];	//devuelve el valor 
			}
		}

		int search(const T& e)const override{	//devuelve la pos donde se encuentre el 1º e o -1 si no se encuentra
		//buscar elemento e y devolver su posición
		for(int i=0; i<n; i++){
			if(arr[i]==e){
			//devolver posición
				return i;
				}
			}
			return -1;
		}

		
		bool empty()const override{		//indica si la lista está vacía
			//devolver true si la lista está vacía
			return n==0;
		}

		int size()const override{		//devuelve n (nº elementos de la lista)
			//devolver número de elementos de la lista
			return n;
		}

	//sobrecargar el operador []
		T operator[](int pos)const{	//devuelve el elemento que esté en pos
			//verificar rango
			if(pos<0||pos>n){
				//excepción
				throw std::out_of_range("Posición fiera d erango.");
			}
			else{
				return arr[pos];	//devuelve el valor
			}
		}

	//sobrecargar el operador <<
		//imprime una instancia de ListArray<T> por pantalla
		friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list){
			for(int i=0; i<list.n; i++){	//list.n para imrpimir solo los valores de la lista válidos (los vacíos no)
				out<<list.arr[i];	//imprime elemento actual
				if(i<list.n-1){
					out<< ", ";	//si no es el útlimo-> espacio
				}
			}
			return out;
		}
};

#endif
