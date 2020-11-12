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

string TicketBase::getPrintableCost(string &CURRENCY) const {
  const std::string PRINTABLE_COST = std::to_string(this->cost);
  return CURRENCY + " " + PRINTABLE_COST;
}
string TicketBase::toString() {
  return "#" + to_string(this->id) + " for $" + to_string(cost);
}
