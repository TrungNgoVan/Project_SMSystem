#include <iostream>
#include <vector>
#include <algorithm>

struct Person {
  std::string name;
  int age;
};

int main() {
  std::vector<Person> people = {
    {"Alice", 20},
    {"Bob", 30},
    {"Charlie", 25}
  };

  Person person_to_find = {"Bob", 30};
  auto it = std::find(people.begin(), people.end(), person_to_find);
  if (it != people.end()) {
    std::cout << "Found person: " << it->name << std::endl;
  } else {
    std::cout << "Person not found" << std::endl;
  }

  return 0;
}
