/*
This program reads and parses input data representing countries and their relationships, then constructs
a minimal spanning tree (MST) using Kruskal's algorithm to calculate the minimal reconstruction cost
for building and destroying roads. The costs for building and destroying roads are converted from
characters to numerical values and the connected components are identified using Union-Find data structure.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <algorithm>

using namespace std;

// Class definition for UnionFind data structure
class UnionFind {
public:
    // Store parent pointers
    vector<int> arrayP;
    // Store set sizes
    vector<int> arrayS;

    // Constructor to initialize arrays
    UnionFind(int numberElem) : arrayP(numberElem), arrayS(numberElem, 0) {
        for (int i = 0; i < numberElem; i++) {
            // Initialize parent pointer
            arrayP[i] = i;
        }
    }

    // Find operation to get the root of the set
    int gRoot(int valX) {
        return (arrayP[valX] == valX) ? valX : (arrayP[valX] = gRoot(arrayP[valX]));
    }

    // Union operation to merge two sets
    void uSets(int valX, int valY) {
        int rootX = gRoot(valX);
        int rootY = gRoot(valY);
        // If in the same set
        if (rootX == rootY) return;

        if (arrayS[rootX] > arrayS[rootY]) {
            arrayP[rootY] = rootX;
        } else {
            arrayP[rootX] = rootY;
            if (arrayS[rootX] == arrayS[rootY]) {
                arrayS[rootY]++;
            }
        }
    }
};

// Struct representing an edge in the graph
struct Edge {
    int start;
    int dest;
    int edgeC;

    Edge(int edgeA, int edgeB, int cost) {
        start = edgeA;
        dest = edgeB;
        edgeC = cost;
    }
};

// Function to compare edges based on their cost
bool edgeComp(const Edge &edgeA, const Edge &edgeB) {
    return edgeA.edgeC < edgeB.edgeC;
}

// Function to convert character to cost value
int convertCharToCost(char charVal) {
    return ('A' <= charVal && charVal <= 'Z') ? charVal - 'A' :
           ('a' <= charVal && charVal <= 'z') ? charVal - 'a' + 26 : -1;
}

// Compute the cost of the minimum spanning tree
int computeCost(const string &inputC, const string &inputB, const string &inputD) {
    // Initialize to 1 to count the first country
    int sizeGraph = 1;
    for (char charVal : inputC) {
        if (charVal == ',') {
            // Each comma encountered increments the sizeGraph
            sizeGraph++;
        }
    }

    // Initialize matrices and lists
    vector<vector<int>> matrixC, matrixB, matrixD, listE;
    matrixC.resize(sizeGraph);
    matrixB.resize(sizeGraph);
    matrixD.resize(sizeGraph);
    listE.resize(sizeGraph);

    for (int i = 0; i < sizeGraph; i++) {
        matrixC[i].assign(sizeGraph, 0);
        matrixB[i].assign(sizeGraph, 0);
        matrixD[i].assign(sizeGraph, 0);
        listE[i].assign(sizeGraph, 0);
    }

    // Populate matrix C
    istringstream streamC(inputC);
    int index = 0, j = 0;
    while (streamC) {
        char charVal;
        streamC >> charVal;

        if (!streamC) break;
        matrixC[index][j] = charVal - '0';
        j++;

        if (j == sizeGraph) {
            j = 0;
            index++;
            streamC.ignore();
        }
    }

    // Populate matrices B and D
    istringstream streamB(inputB), streamD(inputD);
    index = 0, j = 0;
    while (streamB && streamD) {
        char charB, charD;
        streamB >> charB;
        streamD >> charD;
        if (!streamB || !streamD) break;
        matrixB[index][j] = convertCharToCost(charB);
        matrixD[index][j] = convertCharToCost(charD);
        j++;
        if (j == sizeGraph) {
            j = 0;
            index++;
            streamB.ignore();
            streamD.ignore();
        }
    }

    // Initialize UnionFind data structure
    UnionFind unionFind(sizeGraph);
    vector<Edge> edgeList;
    index = 0;
    j = 1;
    while (index < sizeGraph) {
        while (j < sizeGraph) {
            if (matrixC[index][j] == 0) {
                edgeList.push_back(Edge(index, j, matrixB[index][j]));
            } else {
                edgeList.push_back(Edge(index, j, -matrixD[index][j]));
            }
            j++;
        }
        index++;
        j = index + 1;
    }

    // Sort edges based on cost
    sort(edgeList.begin(), edgeList.end(), edgeComp);

    // Compute the cost of the minimum spanning tree
    int costTree = 0;
    vector<Edge>::size_type loopVar = 0;
    while (loopVar < edgeList.size()) {
        const Edge &edgeCurr = edgeList[loopVar];
        int setU = unionFind.gRoot(edgeCurr.start);
        int setV = unionFind.gRoot(edgeCurr.dest);

        if (setU != setV) {
            unionFind.uSets(setU, setV);
            costTree += edgeCurr.edgeC;
            listE[edgeCurr.start][edgeCurr.dest] = listE[edgeCurr.dest][edgeCurr.start] = 1;
        }
        loopVar++;
    }

    // Compute the sum of costs for unused edges
    int sumCost = 0;
    index = 0;
    while (index < sizeGraph) {
        j = index + 1;
        while (j < sizeGraph) {
            if (matrixC[index][j] == 1 && listE[index][j] == 0) {
                sumCost += matrixD[index][j];
            } else if (matrixC[index][j] == 0 && listE[index][j] == 1) {
                sumCost += matrixB[index][j];
            }
            j++;
        }
        index++;
    }
    return sumCost;
}

int main() {
    string inputC, inputB, inputD;
    // Country relations and corresponding costs
    cin >> inputC >> inputB >> inputD;
    // Compute the minimum total cost
    int resultCalculation = computeCost(inputC, inputB, inputD);
    cout << resultCalculation << endl;
    return 0;
}
