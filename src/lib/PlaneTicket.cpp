//
// Created by konrad on 05.10.2020.
//

#include "PlaneTicket.h"

PlaneTicket::PlaneTicket(IDType id, Cost cost, std::string from, std::string to)
    : super(id, cost, std::move(from), std::move(to)) {}

string PlaneTicket::toString() { return "Flight" + super::toString(); }

string PlaneTicket::stringify() {
  string a = " ";
  a[0] = this->META;
  return a + super::stringify();
}

PlaneTicket *PlaneTicket::deserialize(string &data) {
  IDType id = stoi(super::getField(data));
  Cost cost = stof(super::getField(data));
  string from = super::getField(data);
  string to = super::getField(data);

  return new PlaneTicket(id, cost, from, to);
}
