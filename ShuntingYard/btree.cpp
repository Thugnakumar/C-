#include <iostream>
#include <cstring>
#include "btree.h"
#include "node.h"
#include "stack.h"
#include "queue.h"
#include "bnode.h"

using namespace std;

btree::btree(queue * outputQueue, node * oqHead){
  while (ouptutQueue->isEmpty(oqHead) == false){
    bnode * outputNode = new bnode();
    outputNode->data = outputQueue->dequeue(oqHead)->data;
    outputNode->right = NULL;
    outputNode->left = NULL;
    if (outputNode->data == '+' || outputNode->data == '-' || outputNode->data == '*' || outputNode->data == '/' || outputNode->data == '^'){
      //if the value of the node is an operator, pop the previous two nodes off the stack and have the current node point to both of them
      outputNode->left = treePtr->pop(sHead);
      outputNode->right = treePtr-pop(sHead);
    }
    treePtr->push(sHead, outputNode);
  }
}

bnode * btree::returnRoot(){
  return(treePtr->peek(sHead));
}

btree::~btree(){
}
