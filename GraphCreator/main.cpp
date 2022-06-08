/*
Name: Varun Krishnakumar
Date: 6/6/22
This is the graph creator program. It allows users to create and add nodes, make a path between nodes and give it a weight, delete a node and all of its pathways to other nodes, and also find the shortest path between 2 nodes using a breadth-first search and Dijkstra's Algorithm
 */

//all the libraries
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void printArrays(int graph[20][20], char  nodeNames[20][20]);

int main() {
  int graph [20][20]; //creates the graph to see pathways
  char input[2]; //character for input on what action the user wants to complete
  char nodeNames[20][20]; //character array for storing the node names
  char inputs[20]; //character array for reading in user inputs after commands
  int vertexCounter = 0; //integer for counting the number of vertices that the user has inputted

  for (int i = 0; i < 20; ++i) {
    for (int j= 0; j < 20; ++j) {
      //sets everything in the graph to be -1
      graph[i][j] = -1;
    }
  }

  for (int i = 0; i < 20; ++i) {
    nodeNames[i][0] = '\0';
  }

  while (true) {
    cout << "What would you like to do? Would you like to add a new vertex (AV), remove a vertex (RV), add an edge between two vertices (AE), remove an edge between two verticies (RE), or find the shortest (S) path between two nodes?" << endl;
    cin >> input;

    for (int i = 0; i < 2; ++i) {
      input[i] = toupper(input[i]);
    }

    if (strcmp(input, "AV") == 0) {
      //if the user wants to add a new node...
      cout << "Enter the name of the node that you would like to add" << endl; //ask the user what node they want to input
      cin >> inputs; //take in the input

      strcpy(nodeNames[vertexCounter], inputs);
      
      for (int i = 0; i < 20; ++i) {
	//go through the row and column for that node and set those array slots equal to 0 to show that the node exists
	graph[vertexCounter][i] = 0;
	graph[i][vertexCounter] = 0;
      }

      vertexCounter++;
      printArrays(graph, nodeNames);
    }

    else if (strcmp(input, "RV") == 0) {
      //if the user wants to remove a node...
      cout << "What node would you like to remove?"; //ask what node the user wants to remove
      cin >> inputs; //take in the input
      int nodeNameIndex = 0;

      for (int i = 0; i < 20; ++i) {
	if (strcmp(nodeNames[i], inputs) == 0) {
	  nodeNameIndex = i;
	  break;
	}
      }
      
      if (graph[nodeNameIndex][0] > -1) {
	//if the node actually exists...
	for (int i = 0; i < 20; ++i) {
	  //remove all pathways from that node and, in essence, make it so that the node doesn't exist anymore
	  graph[nodeNameIndex][i] = -1;
	  graph[i][nodeNameIndex] = -1;
	}
      }

      else {
	cout << "That node doesn't exist!" << endl;
      }

      printArrays(graph, nodeNames);
      
    }

    else if (strcmp(input, "AE") == 0) {
      cout << "You need two nodes to make a pathway" << endl;
      cout << "What is the first node?" << endl;
      cin >> inputs;

      int nodeNameIndexOne = 0;

      for (int i = 0; i < 20; ++i) {
	if (strcmp(nodeNames[i], inputs) == 0) {
	  nodeNameIndexOne = i;
	  break;
	}
      }
      
      cout << "What is the second node?" << endl;
      cin >> inputs;

      int nodeNameIndexTwo = 0;

      for (int i = 0; i < 20; ++i) {
	if (strcmp(nodeNames[i], inputs) == 0) {
	  nodeNameIndexTwo = i;
	  break;
	}
      }

      if (nodeNameIndexOne == nodeNameIndexTwo) {
	graph[nodeNameIndexOne][nodeNameIndexTwo] = 0;
	graph [nodeNameIndexTwo][nodeNameIndexOne] = 0;
      }

      else {
	int pathLength = 0;
	cout << "What is the length of this pathway?" << endl;
	cin >> pathLength;

	if (pathLength > 0) {
	  graph[nodeNameIndexOne][nodeNameIndexTwo] = pathLength;
	  graph[nodeNameIndexTwo][nodeNameIndexOne] = pathLength;
	}

	else {
	  cout << "You must have a positive path length!" << endl;
	}
      }
      printArrays(graph, nodeNames);
    }

    else if (strcmp(input, "RE") == 0) {
      cout << "Enter the 2 nodes that the pathway you would like to delete lies between" << endl;
      cout << "Node 1: ";
      cin >> inputs;

      int nodeNameIndexOne = 0;

      for (int i = 0; i < 20; ++i) {
	if (strcmp(nodeNames[i], inputs) == 0) {
	  nodeNameIndexOne = i;
	  break;
	}
      }

      cout << "Node 2: ";
      cin >> inputs;

      int nodeNameIndexTwo = 0;

      for (int i = 0; i < 20; ++i) {
	if (strcmp(nodeNames[i], inputs) == 0) {
	  nodeNameIndexTwo = i;
	  break;
	}
      }

      graph[nodeNameIndexOne][nodeNameIndexTwo] = 0;
      graph[nodeNameIndexTwo][nodeNameIndexOne] = 0;
    }

    else if (strcmp(input, "S") == 0) {
    }

    else {
      cout << "Not a valid input!" << endl;
    }
    printArrays(graph, nodeNames);
  }

  return 0;
}

void printArrays(int graph[20][20], char nodeNames[20][20]) {
  cout << "Graph:" << endl;
  for (int i = 0; i < 20; ++i) {
    for (int j = 0; j < 20; ++j) {
      cout << graph[i][j];
    }
    cout << endl;
  }

  cout << "Names: " << endl;
  for (int i = 0; i < 20; ++i) {
    cout << nodeNames[i];
    cout << endl;
  }
}
