#include "../src/summarizer.cc"
#include "gtest/gtest.h"
#include <string.h>

using namespace std;

class GraphTest : public ::testing::Test {

	protected:

		virtual void SetUp() {

			v0.setContent("Nordkorea anklagade på måndagen USA och Sydkorea för att fabricera bevis om att landet använt drönare för att spionera på Väst.");
			v1.setContent("– Om Washington endast lyssnar på vad dess lakejer basunerar så är det oundvikligt så att [USA] kommer att anklagas för att vara en senil farfar som försöker trösta ett gråtande barn, säger en talesperson för den nordkoreanska militären till landets statliga nyhetsbyrå KCNA.");
			v2.setContent("Den sydkoreanska presidenten, Park Geun-Hye, kallas i samma veva för ”politiskt prostituerad”.");
			v3.setContent("Sydkorea säger att uttalandet är ”djupt beklagligt”.");
			v4.setContent("– Nordkorea är inte ett riktigt land, eller hur? Där finns inte mänskliga rättigheter och frihet. Landet existerar enkom för en persons skull, säger Kim Min-Seok, talesperson för Sydkoreas försvarsdepartement till nyhetsbyrån Reuters.");
			v5.setContent("Formellt sett befinner sig Sydkorea och Nordkorea i krig. Koreakriget som pågick 1950–1953 avslutades med vapenvila, inte med ett fredsavtal.");
			v6.setContent("De verbala angreppen från Nordkorea har den senaste tiden varit legio. Medan Sydkoreas president getts olika tillmäle som låter påskina att hon är lösaktig så har USA:s president, Barack Obama, kallats ”hallick” och ”galen svart apa”.");

			v7.setContent("Sydkorea och USA undersökte tillsammans de tre drönare som inom loppet av två veckor hittades på olika platser nära den koreanska gränsen.");
			v8.setContent("Misstankarna om drönarnas ursprung riktades som väntat mot Nordkorea.");
			v9.setContent("Det avfärdar diktaturen som ”en charad” iscensatt för att avleda uppmärksamheten från färjekatastrofen i Sydkorea den 16 april – en olycka som den sydkoreanska regeringen fått svidande kritik för från anhöriga till offren.");

			i = 0.0;
			j = 0;

		}
	
		Vertex<string> v0;
		Vertex<string> v1;
		Vertex<string> v2;
		Vertex<string> v3;
		Vertex<string> v4;
		Vertex<string> v5;	
		Vertex<string> v6;
		Vertex<string> v7;
		Vertex<string> v8;
		Vertex<string> v9;
		double i;
		int j;
		Graph<string> graph;

};

TEST_F(GraphTest, Initializer) {
	EXPECT_EQ(graph.numberOfVertices(),0);
}

TEST_F(GraphTest, AddVertices) {
	graph.addVertex(&v0);
	EXPECT_EQ(graph.numberOfVertices(),1);
	graph.addVertex(&v1);
	graph.addVertex(&v2);
	EXPECT_EQ(graph.numberOfVertices(),3);
}

TEST_F(GraphTest, VertexGetterAndSetter) {
	graph.addVertex(&v0);
	graph.addVertex(&v1);
	graph.addVertex(&v2);
	graph.addVertex(&v3);
	graph.addVertex(&v4);
	graph.addVertex(&v5);


	graph.getVertexAtIndex(0)->setScore(7);
	graph.getVertexAtIndex(1)->setScore(6);
	graph.getVertexAtIndex(2)->setScore(5);
	graph.getVertexAtIndex(3)->setScore(4);
	graph.getVertexAtIndex(4)->setScore(3);
	graph.getVertexAtIndex(5)->setScore(2);


	EXPECT_EQ(graph.getVertexAtIndex(0)->getScore(), 7);
	EXPECT_EQ(graph.getVertexAtIndex(1)->getScore(), 6);
	EXPECT_EQ(graph.getVertexAtIndex(2)->getScore(), 5);
	EXPECT_EQ(graph.getVertexAtIndex(3)->getScore(), 4);
	EXPECT_EQ(graph.getVertexAtIndex(4)->getScore(), 3);
	EXPECT_EQ(graph.getVertexAtIndex(5)->getScore(), 2);

	graph.buildGraph();
	i = 0.0;
	for (edge<string> e : graph.getVertexAtIndex(0)->getEdges()) { // vk = out	linking vertices of vj
		++i;
		Vertex<string> *v = e.neighbor;
		v->setScore(7);

	}
	i = 0.0;
	for (edge<string> e : graph.getVertexAtIndex(1)->getEdges())
	{
		++i;
		EXPECT_EQ(e.neighbor->getScore() , 7);
	}	
}

TEST_F(GraphTest, BuildGraph) {
	graph.addVertex(&v0);
	graph.addVertex(&v1);
	graph.addVertex(&v2);
	graph.addVertex(&v3);
	graph.addVertex(&v4);
	graph.addVertex(&v5);

	// Build a graph of the vertices
	graph.buildGraph();
	
	// Expected size of the graph
	EXPECT_EQ(graph.numberOfVertices(),6);
	
	// check to see if all vertices has the same number of vertices
	for (int i = 0; i < graph.numberOfVertices(); ++i)
	{
		EXPECT_EQ(graph.getVertexAtIndex(i)->numberOfEdges(), graph.numberOfVertices()-1);
	}
}	

TEST_F(GraphTest, EdgeTest) {
	graph.addVertex(&v0);
	graph.addVertex(&v1);
	graph.addVertex(&v2);
	graph.addVertex(&v3);
	graph.addVertex(&v4);
	graph.addVertex(&v5);

	// Build a graph of the vertices
	graph.buildGraph();	

	EXPECT_EQ(graph.getVertexAtIndex(0)->numberOfEdges(),5);
	EXPECT_EQ(graph.getVertexAtIndex(1)->numberOfEdges(),5);
	EXPECT_EQ(graph.getVertexAtIndex(2)->numberOfEdges(),5);
	EXPECT_EQ(graph.getVertexAtIndex(3)->numberOfEdges(),5);
	EXPECT_EQ(graph.getVertexAtIndex(4)->numberOfEdges(),5);
	EXPECT_EQ(graph.getVertexAtIndex(5)->numberOfEdges(),5);

	EXPECT_EQ(graph.getVertexAtIndex(0)->getEdges().size(),5);
	EXPECT_EQ(graph.getVertexAtIndex(1)->getEdges().size(),5);
	EXPECT_EQ(graph.getVertexAtIndex(2)->getEdges().size(),5);
	EXPECT_EQ(graph.getVertexAtIndex(3)->getEdges().size(),5);
	EXPECT_EQ(graph.getVertexAtIndex(4)->getEdges().size(),5);
	EXPECT_EQ(graph.getVertexAtIndex(5)->getEdges().size(),5);


 	for (auto Vi : graph.getVertices()) { // for all vertices in the graph
		for (auto Vj : Vi->getEdges()) { // for all vertices in the graph
 			i++;
 		}
		EXPECT_EQ(i,5);
		i = 0;
		j++;
 	}
	EXPECT_EQ(j,6);
}

TEST_F(GraphTest, RankTest) {
	graph.addVertex(&v0);
	graph.addVertex(&v1);
	graph.addVertex(&v2);
	graph.addVertex(&v3);
	graph.addVertex(&v4);
	graph.addVertex(&v5);
	graph.addVertex(&v6);
	graph.addVertex(&v7);
	graph.addVertex(&v8);
	graph.addVertex(&v9);

	// Build a graph of the vertices
	graph.buildGraph();

	graph.rank();

	graph.insertSort();

}





















