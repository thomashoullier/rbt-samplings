#include "triangle_data.h"

std::ostream& operator<< (std::ostream &out, const triangle_data &td) {
  out << "[" << td.at(0) << ", " << td.at(1) << ", " << td.at(2) << "]";
  return out;
}

std::ostream& operator<< (std::ostream &out, const triangulation &tri) {
  out << "<triangulation" << std::endl;
  for (const auto &triangle : tri) {
    out << triangle << std::endl;
  }
  out << ">";
  return out;
}
