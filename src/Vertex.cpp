#include "Vertex.h"
#include <string>
#include <stdexcept>      // std::out_of_range
#include <vector>

// Constructor
/************************************
 *									*
 *		Constructor/Destructor		*
 *									*
 ************************************/
template <typename T>
Vertex<T>::Vertex() {
	score = 1;
}

template <typename T>
Vertex<T>::Vertex(string str) {
	content = str;
	score = 1;
}


// Destructor
template <typename T>
Vertex<T>::~Vertex() {
}

/************************************
 *									*
 *				Setters				*
 *									*
 ************************************/
template <typename T>
void Vertex<T>::setContent(T data) {
	content = data;
}

template <typename T>
void Vertex<T>::addEdge(Vertex<T> *neighbor, double weight) {
	edge<T> e;
	e.neighbor = neighbor;
	e.weight = weight;
	edges.push_back(e);
}

template <typename T>
void Vertex<T>::setScore(double newScore) {
	score = newScore;
}

/************************************
 *									*
 *				Gettters			*
 *									*
 ************************************/
template <typename T>
T Vertex<T>::getContent() {
	return content;
}

template <typename T>
double Vertex<T>::getScore() {
	return score;
}

template <typename T>
vector<edge<T> > Vertex<T>::getEdges() {
	return edges;
}

template <typename T>
edge<T> Vertex<T>::getEdgeAtIndex(int i) {
  	return edges[i];

}

// the problem is that vector.size() gives all the objects in the vector. 
// since the vector has objects with vectors in them all vill be counted.
template <typename T>
int Vertex<T>::numberOfEdges() {
	return edges.size();
}
/************************************
 *									*
 *			Modifications			*
 *									*
 ************************************/


/************************************
 *									*
 *			Printers				*
 *									*
 ************************************/

template <typename T>
void Vertex<T>::print() {
	cout<<"Score: " << score << "\t content: \"" << content << "\"\n";
}
template <typename T>
void Vertex<T>::printEdges() {
	cout<<"Edges: \n";
	for (int i = 0; i < numberOfEdges(); ++i)
	{
		cout<<"Edge["<<i<<"].weight = "<<getEdgeAtIndex(i).weight; 
		cout<<"\n";
	}
	cout<<"-------------\n";

}
















