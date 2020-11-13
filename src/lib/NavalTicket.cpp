//
// Created by konrad on 05.10.2020.
//

#include "NavalTicket.h"
NavalTicket::NavalTicket(IDType id, Cost cost, std::string from, std::string to)
    : super(id, cost, std::move(from), std::move(to)) {}
string NavalTicket::toString() { return "Cruise" + super::toString(); }
string NavalTicket::serialize() {
  string a = " ";
  a[0] = this->META;
  return a + super::serialize();
}
