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

  string stringify() override;

  static PlaneTicket *deserialize(string &data);
};

#endif // NATIONALCPP_PLANETICKET_H
