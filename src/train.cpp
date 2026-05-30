// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() : first(nullptr), countOp(0) {}
int Train::getOpCount() {
  return countOp;
}

void Train::addCar(bool light) {
  Car *freCar = new Car;
  freCar->light = light;

  if (first == nullptr) {
    first = freCar;
    freCar->next = freshCar;
    freCar->prev = freshCar;
    return;
  }

  Car *tail = first->prev;
  freCar->next = first;
  freCar->prev = tail;
  tail->next = freCar;
  first->prev = freCar;
}

int Train::getLength() {
  Car *current = first;
  current->light = true;

  while (true) {
    int distance = 0;

    do {
      current = current->next;
      countOp++;
      distance++;
    } while (!current->light);

    current->light = false;

    for (int i = 0; i < distance; i++) {
      current = current->prev;
      countOp++;
    }

    if (!current->light) {
      return distance;
    }
  }
}
