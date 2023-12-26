/*
 * Created by minse on 2023-12-26.
 */

#ifndef LINKEDLISTCONSOLE_LINKED_LIST_H
#define LINKEDLISTCONSOLE_LINKED_LIST_H

#include "node.h"

class LinkedList {
  Node* head;
  Node* tail;
  Node* current;
  int count;

 public:
  LinkedList();
  ~LinkedList();

  Node* newNode(int key);
  Node* read(int index);
  void traversal();

  Node* appendFromHead(Node* newNode);
  Node* appendFromTail(Node* newNode);

  Node* insertBefore(Node* newNode, int index);
  Node* insertAfter(Node* newNode, int index);

  Node* deleteFromHead();
  Node* deleteFromTail();
  Node* deleteNode(Node* nodeToDelete);
  void deleteAll();

  Node* modify(Node* nodeToModify, int key);

  Node* linearSearchByUnique(int key);
  void linearSearchByDuplicate(int key, int* size, Node** results[]);
  Node* binarySearchByUnique(int key);
  void binarySearchByDuplicate(int key, int* size, Node** results[]);

  void sortByBubble();
  void sortByInsertion();
  void sortBySelection();

  bool checkListSorted();
};

#endif //LINKEDLISTCONSOLE_LINKED_LIST_H
