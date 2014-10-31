#include "../src/summarizer.cc"
#include "gtest/gtest.h"
#include <string.h>

using namespace std;

class VertexTest : public ::testing::Test {

	protected:

		virtual void SetUp() {
			v0.setContent("Om man har tidigare benbrott kan det bero på benskörhet och öka risken för att man får en ny fraktur. Har man minskat i längd, mer än tre centimeter före eller fem centimeter efter 70 års ålder, kan det bero på en sammanpressning av kotorna i ryggraden, som i sin tur kan bero på benskörhet");
			v1.setContent("Om man har tidigare benbrott kan det bero på benskörhet och öka risken för att man får en ny fraktur. Har man minskat i längd, mer än tre centimeter före eller fem centimeter efter 70 års ålder, kan det bero på en sammanpressning av kotorna i ryggraden, som i sin tur kan bero på benskörhet");
			v2.setContent("Om har tidigare benbrott kan det bero på benskörhet och öka risken för att man får en ny fraktur. Har man minskat i längd, mer än tre centimeter före eller fem centimeter efter 70 års ålder, kan det bero på en sammanpressning av kotorna i ryggraden, som i sin tur kan bero på benskörhet");
		}
	
		Vertex<string> v0;
		Vertex<string> v1;
		Vertex<string> v2;
		Vertex<string> v3;
};

TEST_F(VertexTest, Initializer) {
	EXPECT_EQ(v1.getScore() ,1);
	EXPECT_EQ(v3.getScore() ,1);
}

TEST_F(VertexTest, SettersAndGetters) {
	v0.setScore(5);
	v1.setScore(4);
	v2.setScore(3);

	EXPECT_EQ(v0.getScore(), 5);
	EXPECT_EQ(v1.getScore(), 4);
	EXPECT_EQ(v2.getScore(), 3);
}

TEST_F(VertexTest, CompareContent) {
	EXPECT_EQ(v0.compareTo(&v1), v1.compareTo(&v0));
	EXPECT_EQ(v0.compareTo(&v2), v2.compareTo(&v0));
}

TEST_F(VertexTest, AddNeighbor) {

	// test if no neighbor
	EXPECT_EQ(v0.numberOfEdges(), 0);

	// Add one neighbor
	v0.addEdge(&v1, 0.32);
	EXPECT_EQ(v0.numberOfEdges(), 1);

	// Add one neighbor
	v0.addEdge(&v2, 0.132);
	EXPECT_EQ(v0.numberOfEdges(), 2);

	EXPECT_EQ(v0.getEdgeAtIndex(0).weight, 0.32); 

}






