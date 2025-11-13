#ifndef LIST_H
#define LIST_H

template <typename T>
class List{
	public:
	virtual void insert (int pos,const T& e)=0;	//insertar elemento e en pos
	virtual void append (T e)=0;	//insertar e al final de la lista
	virtual void prepend (T e)=0;	//insertar e al principio de la lista
	virtual T remove(int pos)=0;	//elimina y devuelve el elmento que esté en pos
	virtual T get (int pos)=0;		//devuelve el elemento de pos
	virtual int search(const T& e)const=0;	//devuelve la 1º pos donde se encuentre e y si no lo encuentra devuelve -1
	virtual bool empty()const=0;	//indica si la lista está vacía
	virtual int size()const=0;		//devuelve el número de elementos de la lista (n)
};

#endif
