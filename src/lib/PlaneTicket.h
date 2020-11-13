//
// Created by konrad on 05.10.2020.
//

#ifndef NATIONALCPP_PLANETICKET_H
#define NATIONALCPP_PLANETICKET_H

#include "SingleTicket.h"
#include <string>
#include <utility>

using namespace std;

class PlaneTicket : public SingleTicket {
  typedef SingleTicket super;

public:
  /**
   * p for *P*laneTicket
   * for csv serialisation
   */
  static const char META = 'p';

  PlaneTicket(IDType id, Cost cost, std::string from, std::string to);

  string toString() override;

  string serialize() override;

  static PlaneTicket *deserialize(string &data) {
    IDType id = stoi(data.substr(0, data.find(';')));
    data = data.substr(data.find(';') + 1);
    Cost cost = stof(data.substr(0, data.find(';')));
    data = data.substr(data.find(';') + 1);
    string from = data.substr(0, data.find(';'));
    data = data.substr(data.find(';') + 1);
    string to = data.substr(0, data.find(';'));
    data = data.substr(data.find(';') + 1);

    return new PlaneTicket(id, cost, from, to);
  }
};

#endif // NATIONALCPP_PLANETICKET_H
