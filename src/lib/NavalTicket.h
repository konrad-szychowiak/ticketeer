//
// Created by konrad on 05.10.2020.
//

#ifndef NATIONALCPP_NAVALTICKET_H
#define NATIONALCPP_NAVALTICKET_H

#include "SingleTicket.h"

class NavalTicket : public SingleTicket {
private:
  typedef SingleTicket super;

public:
  static const char META = 'n';

  NavalTicket(IDType id, Cost cost, std::string from, std::string to);

  string toString() override;

  string serialize() override;

  static NavalTicket *deserialize(string &data) {
    IDType id = stoi(data.substr(0, data.find(';')));
    data = data.substr(data.find(';') + 1);
    Cost cost = stof(data.substr(0, data.find(';')));
    data = data.substr(data.find(';') + 1);
    string from = data.substr(0, data.find(';'));
    data = data.substr(data.find(';') + 1);
    string to = data.substr(0, data.find(';'));
    data = data.substr(data.find(';') + 1);

    return new NavalTicket(id, cost, from, to);
  }
};

#endif // NATIONALCPP_NAVALTICKET_H
