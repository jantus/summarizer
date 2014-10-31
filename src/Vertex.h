/**
 *		Vertex.h
 *
 *	class Vertex:
 *	A vertex represents a node in a graph.
 *	The vertex has edges that is paths to neighbors and a content to hold data.
 *	
 */
#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class Vertex;

template <typename T>
struct edge {
	Vertex<T> *neighbor;
	double weight;
};

/*
template <class T>
struct edge_t
{
	double weight;
	T *neighbor;
};
*/
template <typename T>
class Vertex {
		T content;
		double score;

		std::vector<edge<T> > edges;

	public:
	    Vertex ();
		Vertex(string content);
	    ~Vertex ();


	    /************************
	     *		Setters 		*
	     ************************/
		void addEdge(Vertex<T> *neighbor, double weight);
		void setContent(T data);
		void setScore(double newScore);

	    /************************
	     *		Getters 		*
	     ************************/
		T getContent();
		double getScore();
		vector<edge<T> > getEdges();
		edge<T> getEdgeAtIndex(int i);
		int numberOfEdges();
				
	    /************************
	     *		Modifications	*
	     ************************/
		double compareTo(Vertex *neighbor);

	    /************************
	     *		printers		*
	     ************************/
		void print();
		void printEdges();
};

#endif