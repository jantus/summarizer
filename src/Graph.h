/**
 *		Graph.h
 *
 *	class Graph:
 *	Takes given an array and compare function this class builds a graph
 *	based on relation between 
 *	
 *	the graph is an array where each index of the array is a pointer to a vertex.
 */
#include "Vertex.h"
#include <vector>



template<class T>
class Graph
{
	private:
		
		std::vector<Vertex<T> *> vertices;

	public:
		Graph();
		~Graph();

		/********************************
		 *	1. Setters					*
		 ********************************/
		void addVertex(Vertex<T> *newVertex);

		/********************************
		 *	2. Getters					*
		 ********************************/
		vector< Vertex<T> *> getVertices();		
		Vertex<T> *getVertexAtIndex(int i);
		int numberOfVertices();
	
		/********************************
		 *	3. Computations				*
		 ********************************/
		void buildGraph();
		void rank();	
		/********************************
		 *	4. Manipulations			*
		 ********************************/
		void removeVertex(Vertex<T> vertex);
		void removeVertexAt(int index);
		void insertSort();

		/********************************
		 *	5. printers					*
		 ********************************/
		void print();

};