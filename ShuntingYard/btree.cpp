#include <iostream>
#include <cstring>
#include "btree.h"
#inlude "node.h"
#include "stack.h"
#include "queue.h"
#include "bnode.h"

using namespace std;

btree:btree(queue * ouptutQueue, node * oqHead, node * sHead){
  while (ouptutQueue->isEmpty == false){
    bnode * outputNode = new bnode();
    bnode->data = outputQueue->dequeue(oqHead)->data;
    bnode->right = NULL;
    bnode->left = NULL
    if (outputNode->data == '+' || outputNode->data == '-' || outputNode->data == '*' || outputNode->data == '/' || outputNode->data == '^'){
      //if the value of the node is an operator, pop the previous two nodes off the stack and have the current node point to both of them
      outputNode->left = treePtr->pop(sHead);
      outputNode->right = treePtr-pop(sHead);
    }
    treePtr->push(outputNode);
  }
}

btree::~btree(){
}
