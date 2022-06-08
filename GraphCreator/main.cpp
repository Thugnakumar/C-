/*
Name: Varun Krishnakumar
Date: 6/6/22
This is the graph creator program. It allows users to create and add nodes, make a path between nodes and give it a weight, delete a node and all of its pathways to other nodes, and also find the shortest path between 2 nodes using a breadth-first search and Dijkstra's Algorithm
 */

//all the libraries
#include <iostream>
#include <ccstring>
#include <cctype>

using namespace std;

int main() {
  int graph [20][20]; //creates the graph to see pathways
  char input; //character for input on what action the user wants to complete
  char input2; //character for reading input on what the user wants to do in the graph after choosing their action

  for (int i = 0; i < 20; ++i) {
    for (int j= 0; j < 20; ++j) {
      //sets everything in the graph to be -1
      graph[i][j] = -1;
    }
  }
  
  while (true) {
    cout << "What would you like to do? Would you like to add (A) a new node, remove (R) a node, add a pathway (P) between two nodes, or find the shortest (S) path between two nodes?" << endl;
    cin >> input;

    input = toupper(input);

    if (strcmp(input, 'A') == 0) {
      //if the user wants to add a new node...
      cout << "Enter the name of the node that you would like to add (use a single lowercase letter between 'a' and 't')" << endl; //ask the user what node they want to input (must be between a and t)
      cin >> input2; //take in the input
      while (!(input2 >= 'a' && input2 <= 't')) {
	//if the user's input doesn't meet the input requirements, ask them to input again and again until it's valid
	cout << "Not a valid input! Try again!" << endl;
	cin >> input2;
      }
      
      int node = input2 - 97; //store the input as a number which equates to its row/column in the array

      for (int i = 0; i < 20; ++i) {
	//go through the row and column for that node and set those array slots equal to 0 to show that the node exists
	graph[node][i] = 0;
	graph[i][node] = 0;
      }
    }

    else if (strcmp(input, 'R') == 0) {
      //if the user wants to remove a node...
      cout << "What node would you like to remove (use a single lowercase letter between 'a' and 't')?"; //ask what node the user wants to remove
      cin >> input2; //take in the input

      while (!(input2 >= 'a' && input2 <= 't')) {
	//if the user's input doesn't meet the input requirements, ask them to input again and again until it's valid
	cout << "Not a valid input! Try again!" << endl;
	cin >> input2;
      }

      int node = input2 - 97; //set user's input to be the number that corresponds with that letter's location on the graph

      if (graph[node][0] > -1) {
	//if the node actually exists...
	for (int i = 0; i < 20; ++i) {
	  //remove all pathways from that node and, in essence, make it so that the node doesn't exist anymore
	  graph[node][i] = -1;
	  graph[i][node] = -1;
	}
      }

      else {
	cout << "That node doesn't exist!" << endl;
      }
      
    }

    else if (strcmp(input, 'P') == 0) {
      cout << "You need two nodes to make a pathway" << endl;
      cout << "What is the first node (use a single lowercase letter between 'a' and 't')?" << endl;
      cin >> input2;

      while (!(input2 >= 'a' && input2 <= 't')) {
	//if the user's input doesn't meet the input requirements, ask them to input again and again until it's valid
	cout << "Not a valid input! Try again!" << endl;
	cin >> input2;
      }

      int nodeOne = input2 - 97;
      
      cout << "What is the second node (use a single lowercase letter between 'a' and 't')?" << endl;
      cin >> input2;

      while (!(input2 >= 'a' && input2 <= 't')) {
	//if the user's input doesn't meet the input requirements, ask them to input again and again until it's valid
	cout << "Not a valid input! Try again!" << endl;
	cin >> input2;
      }

      int nodeTwo = input2 - 97;

      if (nodeOne == nodeTwo) {
	graph[nodeOne][nodeTwo] = 0;
	graph [nodeTwo][nodeOne] = 0;
      }

      else {
	int pathLength = 0;
	cout << "What is the length of this pathway?" << endl;
	cin >> pathLength;

	if (pathLength >= 0) {
	  graph[nodeOne][nodeTwo] = pathLength;
	  graph[nodeTwo][nodeOne] = pathLength;
	}

	else {
	  cout << "Can't have a negative path length!" << endl;
	}
      }

    }

    else if (strcmp(input, 'S') == 0) {
    }

    else {
      cout << "Not a valid input!" << endl;
    }
  }
  cout << "What would you like 
}
