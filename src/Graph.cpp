/**
 *		Graph.cpp
 *
 *	Implemenation of Graph.cpp
 *	
 */
#include "Graph.h"
#include "Vertex.h"
#include <vector>
#include <stdexcept>      // std::out_of_range
#include <math.h>

#ifndef DAMPING_FACTOR
#define DAMPING_FACTOR 0.85
#endif

#ifndef THRESHOLD
#define THRESHOLD 0.1
#endif

/************************************
 *									*
 *	0. Constructor/Destructor		*
 *									*
 ************************************/
template<class T>
Graph<T>::Graph() {
}


// Destructor
template<class T>
Graph<T>::~Graph() {
}

/************************************
 *									*
 *	1. Setters						*
 *									*
 ************************************/
template<class T>
void Graph<T>::addVertex(Vertex<T>* newVertex) {
	vertices.push_back(newVertex);
}

/************************************
 *									*
 *	2. Getters 						*
 *									*
 ************************************/
template<class T>
vector<Vertex<T> *> Graph<T>::getVertices() {
	return vertices;
}

template<class T>
Vertex<T>* Graph<T>::getVertexAtIndex(int i) {
	try {
		return vertices.at(i);
	}  catch (const std::out_of_range& oor) {
    	std::cerr << "Out of Range error: " << oor.what() << '\n';
  	}
	return vertices.at(i);
}


template<class T>
int Graph<T>::numberOfVertices() {
	return vertices.size();
}

/************************************
 *									*
 *	3. Computations					*
 *									*
 ************************************/
/**
 *	This method build connections between edges by comparing them.
 *
 *
 */
template<class T>
//void Graph<T>::buildGraph(double (Vertex<T>::*compare)(Vertex<T>)){
void Graph<T>::buildGraph() {
	int limit = numberOfVertices(); // adjusting, cuz starting on index 0
	for (int i = 0; i < limit; i++)
	{
		for (int j = i+1; j < limit; j++)
		{
			double similarity = getVertexAtIndex(i)->compareTo(getVertexAtIndex(j));
			if (similarity > THRESHOLD)
			{
				vertices[i]->addEdge(vertices[j], similarity);
				vertices[j]->addEdge(vertices[i], similarity);
			}
		}
	}
}

/**
 *	Pseudo code for the ranking algorithm.
 *	Since the graph is undirected both the in and out vertices are the same
 *
 *
 */
template<class T>
void Graph<T>::rank() {
 	double d = DAMPING_FACTOR; // the damping factor, set to 0.85 by google.
 	//vector<GeneralVector *> vertices = graph.getVertices();
	double error = 0.0001, current_rank;	

	do {
		current_rank = vertices.at(0)->getScore();
	 	for (Vertex<T> *Vi : vertices) {
			double sum_first = 0.0;
	 		for (edge<T> Vi_in_edge : Vi->getEdges()) { // vj = inlinking vertices of vi
	 			double weight_jk = 1.0;
	 			for (auto Vj_out_edge : Vi_in_edge.neighbor->getEdges()) { // vk = out	linking vertices of vj
	 				weight_jk += Vj_out_edge.weight; // the sum of all outgoing edges from vj
	 			}
	 			sum_first += (Vi_in_edge.weight / weight_jk) * Vi_in_edge.neighbor->getScore(); // Sum upp all weights
	 		}
	 		Vi->setScore(d/numberOfVertices() + (1 - d) * sum_first); 

	 	}
 	} while (error < fabs(current_rank - getVertexAtIndex(0)->getScore()));// find convergence. 

 	/** ALT - norm is the first norm, 1-norm
 	 *	R0 <- S
 	 *	
 	 *	loop:
 	 *		 Ri+1 	<- ARi
 	 *			d 	<- norm(Ri) - norm(Ri+1)
 	 *		 Ri+1 	<- Ri+1 + dE
 	 *		delta	<- norm(Ri+1 - Ri)
 	 *	while( delta > error)
 	 *
 	 */

 }

/************************************
 *									*
 *	4. Manipulators					*
 *									*
 ************************************/
// removes a specific vertex
template<class T>
void Graph<T>::removeVertex(Vertex<T> vertex) {
	vertex;
	// Compare nodes and remove it?
	// or how should I find it?
}

// removes the node att index ver
template<class T>
void Graph<T>::removeVertexAt(int index) {
	vertices.erase(vertices.begin() + index);
}

template<class T>
void Graph<T>::insertSort() {
	int flag;
	do {
		flag = 0;
	    for (unsigned int i = 1; i < vertices.size(); ++i) {
	    	if (getVertexAtIndex(i)->getScore() > getVertexAtIndex(i-1)->getScore()) {
	    		swap(vertices[i], vertices[i-1]);
	    		flag++;
	    	}
	    }
	} while(flag != 0);
}


/************************************
 *									*
 *	5. Printers						*
 *									*
 ************************************/

template<class T>
void Graph<T>::print() {
	cout<<"GRAPH:\n";
	int i = 0;
	for (Vertex<T> *v : vertices)
	{
		cout<<"Vertex["<<i<<"]";
		v->print();
		v->printEdges();
		cout<<"\n";
		i++;
	}
}



