//
// Created by konrad on 12.11.2020.
//

#include "SingleTicket.h"

string SingleTicket::getFrom() const { return this->from; }
void SingleTicket::setFrom(std::string value) { this->from = std::move(value); }

string SingleTicket::getTo() const { return this->to; }
void SingleTicket::setTo(std::string value) { this->to = std::move(value); }

string SingleTicket::toString() {
  return ", from `" + this->getFrom() + "' to `" + this->getTo() + "'" +
         super::toString();
}

string SingleTicket::stringify() {
  return ";" + to_string(this->getId()) + ";" + to_string(this->getCost()) +
         ";" + this->from + ";" + this->to + ";\n";
}

SingleTicket::SingleTicket(IDType id, Cost cost, string from, string to)
    : super(id, cost) {
  this->from = std::move(from);
  this->to = std::move(to);
}
