//
// Created by konrad on 05.10.2020.
//
#include <string>
#include <utility>

#include "TicketBase.h"

TicketBase::TicketBase(IDType id, Cost cost) {
  this->cost = cost;
  this->id = id;
}

IDType TicketBase::getId() const { return this->id; }

float TicketBase::getCost() const { return this->cost; }

void TicketBase::setCost(float new_cost) { this->cost = new_cost; }

string TicketBase::toString() { return ", for $" + to_string(cost); }

string TicketBase::stringify() {
  return to_string(this->id) + ";" + to_string(this->cost) + ";";
}
string TicketBase::getField(string &fields) {
  auto position = new size_t;
  *position = fields.find(';');
  string field = fields.substr(0, *position);
  fields = fields.substr(++(*position));
  delete position;
  return field;
}
