/*
 * Created by Minseok Chu on 2023-12-26.
 */

#include "linked_list.h"

#include <iostream>

LinkedList::LinkedList() {
  this->head = nullptr;
  this->tail = nullptr;
  this->current = nullptr;
  this->count = 0;
}

LinkedList::~LinkedList() { deleteAll(); }

Node* LinkedList::newNode(int key) {
  this->current = new Node();

  this->current->next = nullptr;
  this->current->previous = nullptr;
  this->current->key = key;

  return this->current;
}

Node* LinkedList::read(int index) {
  if (index < 0 || index > this->count - 1) {
    return nullptr;
  }

  if (this->head == nullptr || this->tail == nullptr) {
    return nullptr;
  }

  this->current = this->head;

  while (index > 0) {
    this->current = this->current->next;
    --index;
  }

  return this->current;
}

void LinkedList::traversal() {
  this->current = this->head;

  for (int i = 0; i < this->count; ++i) {
    std::cout << this->current->key << " ";
    this->current = this->current->next;
  }

  std::cout << std::endl;
}

Node* LinkedList::appendFromHead(Node* newNode) {
  if (this->head == nullptr || this->tail == nullptr) {
    this->head = newNode;
    this->tail = newNode;
    ++this->count;

    return newNode;
  }

  newNode->next = this->head;
  this->head->previous = newNode;
  this->head = newNode;
  this->current = newNode;

  ++this->count;

  return this->current;
}

Node* LinkedList::appendFromTail(Node* newNode) {
  if (this->head == nullptr || this->tail == nullptr) {
    this->head = newNode;
    this->tail = newNode;
    ++this->count;

    return newNode;
  }

  newNode->previous = this->tail;
  this->tail->next = newNode;
  this->tail = newNode;
  this->current = newNode;

  ++this->count;

  return this->current;
}

Node* LinkedList::insertBefore(Node* newNode, int index) {
  if (this->count == 0) {
    return nullptr;
  }

  if (index < 0 || index > this->count - 1) {
    return nullptr;
  }

  this->current = this->head;

  while (index > 0) {
    this->current = this->current->next;
    --index;
  }

  newNode->next = this->current;
  newNode->previous = this->current->previous;

  this->current->previous->next = newNode;
  this->current->previous = newNode;

  ++this->count;

  return newNode;
}

Node* LinkedList::insertAfter(Node* newNode, int index) {
  if (this->count == 0) {
    return nullptr;
  }

  if (index < 0 || index > this->count - 1) {
    return nullptr;
  }

  this->current = this->head;

  while (index > 0) {
    this->current = this->current->next;
    --index;
  }

  newNode->previous = this->current;
  newNode->next = this->current->next;

  this->current->next->previous = newNode;
  this->current->next = newNode;

  ++this->count;

  return this->current;
}

Node* LinkedList::deleteFromHead() {
  if (this->count == 0) {
    return nullptr;
  }

  this->current = this->head;

  this->head->next->previous = this->head->next;
  this->head = this->head->next;

  --this->count;

  return this->current;
}

Node* LinkedList::deleteFromTail() {
  if (this->count == 0) {
    return nullptr;
  }

  this->current = this->head;

  this->tail->previous->next = this->tail->previous;
  this->tail = this->tail->previous;

  --this->count;

  return this->current;
}

Node* LinkedList::deleteNode(Node* nodeToDelete) {
  if (this->count == 0 || nodeToDelete == nullptr) {
    return nullptr;
  }

  this->current = this->head;

  while (this->current != nodeToDelete) {
    this->current = this->current->next;
  }

  this->current->next->previous = this->current->previous;
  this->current->previous->next = this->current->next;

  --this->count;

  return nodeToDelete;
}

void LinkedList::deleteAll() {
  this->current = this->head;

  while (this->current != this->tail) {
    this->current = this->current->next;
    delete this->current->previous;
  }

  delete this->current;

  this->count = 0;
  this->head = nullptr;
  this->tail = nullptr;
  this->current = nullptr;
}

Node* LinkedList::modify(Node* nodeToModify, int key) {
  if (this->count == 0 || nodeToModify == nullptr) {
    return nullptr;
  }

  this->current = this->head;

  while (this->current != nodeToModify) {
    this->current = this->current->next;
  }

  this->current->key = key;

  return this->current;
}

Node* LinkedList::linearSearchByUnique(int key) {
  if (this->head == nullptr || this->tail == nullptr || this->count == 0) {
    std::cout << "리스트가 비어 있습니다!";
    return nullptr;
  }

  this->current = this->head;

  int i = 0;

  while (this->current != this->tail) {
    if (this->current->key == key) {
      break;
    }

    this->current = this->current->next;
    ++i;
  }

  if (this->current->key != key) {
    std::cout << "결과 :  찾지 못 함!";
    return nullptr;
  }

  std::cout << "결과 : " << i;

  return this->current;
}

void LinkedList::linearSearchByDuplicate(int key, int* size, Node** results[]) {
  if (this->head == nullptr || this->tail == nullptr || this->count == 0) {
    std::cout << "리스트가 비어 있습니다!";
    return;
  }

  *size = 0;
  *results = new Node*[this->count];
  this->current = this->head;

  std::cout << "결과 : ";

  for (int i = 0; i < this->count; ++i) {
    if (this->read(i)->key == key) {
      std::cout << i;
      (*results)[*size] = this->read(i);
    }
  }

  std::cout << std::endl;
}

Node* LinkedList::binarySearchByUnique(int key) {
  if (this->head == nullptr || this->tail == nullptr || this->count == 0) {
    std::cout << "리스트가 비어 있습니다!";
    return nullptr;
  }

  if (key < this->head->key || key > this->tail->key) {
    std::cout << "결과 : 찾지 못함";
    return nullptr;
  }

  int left, right, middle;

  left = 0;
  right = this->count;

  while (left <= right) {
    middle = (left + right) / 2;

    std::cout << middle << " ";

    if (this->read(middle)->key == key) {
      std::cout << "결과 : " << middle << std::endl;
      return this->read(middle);
    }

    if (this->read(middle)->key < key) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }
}

void LinkedList::binarySearchByDuplicate(int key, int* size, Node** results[]) {
  if (this->head == nullptr || this->tail == nullptr || this->count == 0) {
    std::cout << "리스트가 비어 있습니다!";
    *size = -1;
    return;
  }

  if (key < this->head->key || key > this->tail->key) {
    std::cout << "NONE";
    *size = -1;
    return;
  }

  int left, right, middle, isDuplicated;

  results = new Node**[this->count];

  *size = 0;
  left = 0;
  right = this->count;

  while (left < right) {
    middle = (left + right) / 2;

    std::cout << middle << " ";

    if (this->read(middle)->key == key) {
      isDuplicated = 0;

      for (int i = 0; i < *size; ++i) {
        if ((*results)[i] == this->read(middle)) {
          isDuplicated = 1;
        }
      }

      if (!isDuplicated) {
        (*results)[*size] = this->read(middle);
        ++*size;
        std::cout << middle << " ";
      }
    }

    if (this->read(middle)->key < key) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }

  middle = left;

  std::cout << std::endl << "결과 : ";

  while (left < this->count &&
         this->read(middle)->key == this->read(left)->key) {
    std::cout << left << " ";
    (*results)[*size] = this->read(left);
    ++left;
    ++*size;
  }

  std::cout << std::endl;
}

void LinkedList::sortByBubble() {
  if (this->head == nullptr || this->tail == nullptr || this->count == 0) {
    return;
  }

  int temp;

  for (int i = 0; i < this->count - 1; ++i) {
    for (int j = 0; j < this->count - 1 - i; ++j) {
      if (this->read(j)->key >= this->read(j + 1)->key) {
        temp = this->read(j)->key;
        this->modify(this->read(j), this->read(j + 1)->key);
        this->modify(this->read(j + 1), temp);
      }
    }
  }
}

void LinkedList::sortByInsertion() {
  if (this->head == nullptr || this->tail == nullptr || this->count == 0) {
    return;
  }

  int temp;

  for (int i = 0; i < this->count; ++i) {
    for (int j = i; j > 0; --j) {
      if (this->read(j - 1)->key > this->read(j)->key) {
        std::cout << j << std::endl;
        temp = this->read(j - 1)->key;
        this->modify(this->read(j - 1), this->read(j)->key);
        this->modify(this->read(j), temp);
      }
    }
  }
}

void LinkedList::sortBySelection() {
  if (this->head == nullptr || this->tail == nullptr || this->count == 0) {
    return;
  }

  int lowest, temp;

  for (int i = 0; i < this->count; ++i) {
    lowest = i;

    for (int j = i + 1; j < this->count; ++j) {
      if (this->read(lowest)->key >= this->read(j)->key) {
        lowest = j;
      }
    }

    if (lowest != i) {
      temp = this->read(lowest)->key;
      this->modify(this->read(lowest), this->read(i)->key);
      this->modify(this->read(i), temp);
    }
  }
}

bool LinkedList::checkListSorted() {
  if (this->count == 0 || this->head == nullptr || this->tail == nullptr) {
    return false;
  }

  int current_key;

  this->current = this->head;
  current_key = this->current->key;

  for (int i = 0; i < this->count; ++i) {
    if (current_key > this->current->key) {
      return false;
    }

    current_key = this->current->key;
    this->current = this->current->next;
  }

  return true;
}