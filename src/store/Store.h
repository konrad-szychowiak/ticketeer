//
// Created by konrad on 12.11.2020.
//

#ifndef NATIONALCPP_DATABASE_H
#define NATIONALCPP_DATABASE_H

#include "../types/types.h"
#include "StoreInternalError.h"
#include <iostream>
#include <map>

using namespace std;

template <class T> class Store {
  typedef map<IDType, T *> StoreMap;
  typedef pair<IDType, T *> StoredPair;

  StoreMap store;

  void insert(T *ticket);

public:
  Store() = default;
  ~Store();

  T *at(IDType key) { return this->store[key]; }

  Store<T> *add(T *ticket);
  Store<T> *removeById(IDType id);
  Store<T> *operator+=(T *ticket);
  Store<T> *operator-=(T *ticket);

  void listAll();
  bool has(IDType key);

  string serializeKeys();
  string serialize();
};

template <class StoredTicket> void Store<StoredTicket>::listAll() {
  for (auto &pair : this->store) {
    auto key = pair.first;
    printf("\x1b[33m%5u\x1b[0m ", key);
    cout << this->store[key]->toString() << endl;
  }
}

template <class T> Store<T>::~Store() {
  for (auto &pair : this->store) {
    auto key = pair.first;
    delete this->store[key];
  }
}

template <class T> void Store<T>::insert(T *ticket) {
  this->store.insert(StoredPair(ticket->getId(), ticket));
}

template <class T> Store<T> *Store<T>::add(T *ticket) {
  this->insert(ticket);
  return this;
}

template <class T> Store<T> *Store<T>::removeById(IDType id) {
  this->store.erase(id);
  return this;
}

template <class T> Store<T> *Store<T>::operator+=(T *ticket) {
  this->add(ticket);
  return this;
}

template <class T> Store<T> *Store<T>::operator-=(T *ticket) {
  this->removeById(ticket->getId());
  return this;
}

template <class T> bool Store<T>::has(IDType key) {
  if (this->store.count(key))
    return true;
  return false;
}

template <class T> string Store<T>::serializeKeys() {
  string text = "";
  for (auto &pair : this->store) {
    auto key = pair.first;
    text += to_string(key) + ";";
  }
  return text;
}

template <class T> string Store<T>::serialize() {
  string text = "";
  for (auto &pair : this->store) {
    auto key = pair.first;
    text += this->store[key]->stringify();
  }
  return text;
}

#endif // NATIONALCPP_DATABASE_H
