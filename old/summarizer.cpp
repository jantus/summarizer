/**
 *		Summarizer.cpp
 *
 *	1. Read file from disk.
 *	2. Explode file into array, each sentence becomming an entry.
 *	3. Build graph.
 *	4. Run PageRank on graph.
 *	5. Extract summary based on the rank of each sentence.
 *
 *	Classes:
 *		• Text - Reads and explode text file.
 *		• Graph - The graph to be ranked.
 *		• PageRank - Performes a rank on any given graph.
 * 		• Summarizer - Performes the summarizing of a text.
 */
#include <iostream>
using namespace std;


class Summarizer {

};

class PageRank
{
public:

	/* data */
};


class Rectangle {
    int width, height;
  public:
    void set_values (int,int);
    int area() {return width*height;}
};

void Rectangle::set_values (int x, int y) {
  width = x;
  height = y;
}

int main () {
  Rectangle rect;
  rect.set_values (3,4);
  cout << "area: " << rect.area();
  cout << "\n";
  return 0;
}
