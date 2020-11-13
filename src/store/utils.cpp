//
// Created by konrad on 13.11.2020.
//

#include "utils.h"
#include <fstream>

SingleTicket *database::deserialize_simple(string line) {
  const char line_meta = line.substr(0, 2)[0];
  return create_simple_ticket(line_meta, line.substr(2));
}

SingleTicket *database::create_simple_ticket(const char meta, string info) {
  switch (meta) {
  case PlaneTicket::META:
    return PlaneTicket::deserialize(info);
  case NavalTicket::META:
    return NavalTicket::deserialize(info);
  default:
    return nullptr;
  }
}

database::SingleDB database::load_single(const char *file) {
  auto database = new Store<SingleTicket>();
  string line;

  ifstream singles;
  singles.open(file);
  while (!singles.eof()) {
    singles >> line;
    database->add(deserialize_simple(line));
  }
  singles.close();

  return database;
}

database::MultiDB database::load_multi(const char *file, SingleDB database) {
  string line;

  auto multi_db = new Store<MultiTicket>();

  ifstream source;
  source.open(file);
  while (!source.eof()) {
    source >> line;
    *multi_db += MultiTicket::parse(line.substr(2), database);
  }
  source.close();

  return multi_db;
}

database::BaseDB database::load_relations(const char *file_path, SingleDB single,
                              MultiDB multi) {
  string field;
  IDType relation_id;
  ifstream file_content;

  auto related_database = new Store<TicketBase>();

  file_content.open(file_path);
  while (std::getline(file_content, field, ';')) {
    relation_id = stoi(field);

    if (single->has(relation_id))
      *related_database += single->at(relation_id);

    else if (multi->has(relation_id))
      *related_database += multi->at(relation_id);

    else
      throw StoreInternalError("Not in store");
  }
  file_content.close();

  return related_database;
}

void database::save_relations(const char *file_path,
                              database::BaseDB database) {
  string line;

  ofstream target;
  target.open(file_path, ios::trunc);
  target << database->serializeKeys();
  target.close();
}