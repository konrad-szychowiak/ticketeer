//
// Created by konrad on 05.10.2020.
//

#include "MultiTicket.h"

string MultiTicket::toString() {
  string text = "Multiple directions" + super::toString() + ":\n";

  for (auto const &pair : this->reservations) {
    auto key = pair.first;
    text += "    \x1b[37m+ " + this->reservations[key]->toString() +
            " \x1b[33m[" + to_string(key) + "]\x1b[0m\n";
  }

  return text.substr(0, text.length() - 1);
}

void MultiTicket::addReservation(TicketBase *ticket_link) {
  this->reservations.insert(
      std::pair<IDType, TicketBase *>(ticket_link->getId(), ticket_link));
  this->setCost(this->getCost() + ticket_link->getCost());
}

void MultiTicket::removeById(IDType target_id) {
  this->reservations.erase(target_id);
}

MultiTicket *MultiTicket::operator+=(TicketBase *other) {
  this->addReservation(other);
  return this;
}

MultiTicket *MultiTicket::operator-=(TicketBase *other) {
  this->removeById(other->getId());
  return this;
}

string MultiTicket::serialize() {
  string data = "m;" + super::serialize();
  for (auto const &pair : this->reservations) {
    auto key = pair.first;
    data += to_string(key) + ";";
  }
  return data + '\n';
}
MultiTicket *MultiTicket::deserialize(string data,
                                      Store<SingleTicket> *database) {
  IDType id = stoi(data.substr(0, data.find(';')));
  data = data.substr(data.find(';') + 1);

  Cost cost = stof(data.substr(0, data.find(';')));
  data = data.substr(data.find(';') + 1);

  auto ticket = new MultiTicket(id, cost);

  while (data.length() > 0) {
    IDType link_id = stoi(data.substr(0, data.find(';')));
    data = data.substr(data.find(';') + 1);
    TicketBase *link_ticket = database->at(link_id);
    ticket->addReservation(link_ticket);
  }

  return ticket;
}
