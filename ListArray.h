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
		ListArray(){
			arr=new T[MIN_SIZE];	//nuevo array elementos tipo T
			//inicializar atributos
			n=0;		
			max=MIN_SIZE;
		}		

		~ListArray(){
			//liberar memoria dinámica
			delete [] arr;
		}

		
		
		//métodos de List.h

		void insert(int pos,const T& e) override{
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

		T remove(int pos)override{
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

		T get(int pos)override{
			//verificar si está en el rango permitido
			if(pos<0|pos>n){	//fuera del rango
				throw std:: out_of_range("Posición fuera de rango.");
			}
			else{
				return arr[pos];
			}
		}

		int search(const T& e)const override{
		//buscar elemento e y devolver su posición
		for(int i=0; i<n; i++){
			if(arr[i]==e){
			//devolver posición
				return i;
				}
			}
			return -1;
		}

		
		bool empty()const override{
			//devolver true si la lista está vacía
			return n==0;
		}

		int size()const override{
			//devolver número de elementos de la lista
			return n;
		}

		//sobrecargar el operador []
		T operator[](int pos)const{
			//verificar rango
			if(pos<0||pos>n){
				//excepción
				throw std::out_of_range("Posición fiera d erango.");
			}
			else{
				return arr[pos];
			}
		}

		//sobrecargar el operador <<
		friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list){
			for(int i=0; i<list.n; i++){
				out<<list.arr[i];	//imprime elemento actual
				if(i<list.n-1){
					out<< ", ";	//si no es el útlimo-> espacio
				}
			}
			return out;
		}
};

#endif
