/**
 *		Summarizer.cpp
 *
 *	1. Read file from disk.
 *	2. Explode file into array, each sentence becomes a Vertex.
 *	3. Build graph from the vertices.
 *	4. Run PageRank on graph.
 *	5. Extract summary based on the rank of each Vertex.
 *
 *	Classes:
 *		• Text - Reads and explode text file.
 *    	• Vertex<T> - A vertex of some type to build graph from
 *		• Graph - The graph to be ranked.
 *		• PageRank - Performes a rank on any given graph.
 * 		• Summarizer - Performes the summarizing of a text.
 * 
 *  Compare: Each time Vertex<T> is used a compare function must be written
 *          float compareTo(Vertex *neighbor);
 */
#include "src/summarizer.cc"
#include <iostream>
#include <fstream>
int main(int argc, char const *argv[])
{

string article =  "Burkina Faso's military chief is now the head of state of the West African nation, after unrest that led to the resignation of President Blaise Compaore. Gen. Honore Nabere Traore, the head of Burkina Faso's military, said Friday that he has taken over presidential duties and that he will lead the country through a political transition and elections. Faced with violent protests demanding an end to his 27-year rule, Compaore initially dissolved the government but said he would stay in power until elections could be carried out. He changed his mind, and on Friday announced his resignation. Compaore said he stepped down to preserve peace in the country. The new man in charge, Traore, appealed for calm and called for a return to a normal constitutional process. Security forces, including the military, will continue to maintain order and safety in the country, Traore added. France, the former colonial ruler of what is today Burkina Faso, welcomed the President's resignation and called for elections to happen quickly. Unrest has gripped Burkina Faso -- a key partner for Western countries in the campaign against Islamist militants -- since protests against Compaore's government turned violent Thursday.";

	
	Graph<string> graph;
	graph = initializeGraph(article);
	graph.buildGraph();
	graph.rank();

	graph.insertSort();

	cout << "Headline:\nBurkina Faso President resigns; military now in charge\n\n";
	cout << "Original Article:\n" << article << "\n";
	printf("\n\nSummarized Article:\n");
	print_summary(graph);
	printf("\n\n");
	printf("Graph size: %d nodes\t Text length: %lu\n", graph.numberOfVertices(), article.size());
	return 0;
}
