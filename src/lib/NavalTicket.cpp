//
// Created by konrad on 05.10.2020.
//

#include "NavalTicket.h"

NavalTicket::NavalTicket(IDType id, Cost cost, std::string from, std::string to)
    : super(id, cost, std::move(from), std::move(to)) {}

string NavalTicket::toString() { return "Cruise" + super::toString(); }

string NavalTicket::stringify() {
  string a = " ";
  a[0] = this->META;
  return a + super::stringify();
}

NavalTicket *NavalTicket::deserialize(string &data) {
  IDType id = stoi(super::getField(data));
  Cost cost = stof(super::getField(data));
  string from = super::getField(data);
  string to = super::getField(data);

  return new NavalTicket(id, cost, from, to);
}
