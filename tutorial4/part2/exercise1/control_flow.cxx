// Define a function taking two integers. The second parameter takes a default
// argument of 3 which will be used if the second argument isn't specified
//
// Note that the variables i and j here are local to this function and have no
// relationship with any variables defined outside the function's scope

int double_and_add(const int i, const int j = 3) {
  // A local variable in this function
  const auto doubled{i * 2};
  return doubled + j;
}
#include <vector>
#include <iostream>
int main() {
  int x{2};
  int y{0};
  if (x > 3) {
    y++; // equivalent to y = y + 1
  } else {
    y--; // equivalent to y = y - 1
  }
  // Loop N = x times
  // Note by convention we loop from 0 as long as i < x
  // Not from 1 as long as i <= x
  for (int i{0}; i < x; ++i) {
    std::cout << i << std::endl;
  }
  // Early quitting with break statement
  for (int i{0}; i < x; ++i) {
    std::cout << i << std::endl;
    if (i == 1) {
      break;
    }
  }
  // Skipping iterations with the continue statement
  for (int i{0}; i < x; ++i) {
    // Modulo operator
    if (i % 2 == 1) {
      continue;
    }
    std::cout << i << std::endl;
  }
  while (x < 4) {
    int j{2};
    x += j;
  }
  // j is out of scope and cannot be accessed

  // Loop over all the elements of a collection
  const std::vector<std::string> courseCodes{"MNXB01", "FYSN17", "FYST15"};
  for (auto code : courseCodes) {
    std::cout << code << std::endl;
  }
  y = x++;
  y = ++x;
  // Avoid using ++ on a line with other stuff
  // Never modify more than one thing on a single line
  // y = x++ + ++x

  // switch means I expect at least one of these to match (typically no more)
  switch (x) {
  case 4:
    std::cout << "x was 4!" << std::endl;
    // No break statement, so the next case will also be executed
  case 5:
    std::cout << "x was 4 or 5" << std::endl;
    break;
  case 6:
    std::cout << "x was 6" << std::endl;
    break;
  default:
    std::cout << "x was something else" << std::endl;
    break;
  }
  // This code is equivalent to the switch statement above but requires much
  // more attention from the reader to understand
  if (x == 4) {
    std::cout << "x was 4!" << std::endl;
  } else if (x == 4 || x == 5) {
    std::cout << "x was 4 or 5" << std::endl;
  } else if (x == 6) {
    std::cout << "x was 6" << std::endl;
  } else {
    std::cout << "x was something else" << std::endl;
  }

  // Conditional operator/ternary operator
  // condition ? if_true : if_false;
  // Tells you that no matter what, x is changed
  x = (y > 5) ? 5 : 10;
  // equivalent to
  if (y > 5) {
    x = 5;
  } else {
    x = 10;
  }
  // Misleading indentation
  // Danger this only does one of the statements
  if (x == 4)
    std::cout << "x is 4" << '\n';
  std::cout
      << "The nuclear launch codes that should only be shown if x is 4 are: "
      << 123456789 << '\n';

  // Give up control to a separate part of the code (i.e. a function) Note
  // that the variables i and j here are unrelated to the variables i and j
  // that were used in the loops or to the variables i and j in the function
  // body
  int i{3};
  const int j{2};
  const int k{2};

  // Note that this has no effect on the local i, j variables
  auto result{double_and_add(i, j)};
  // Rerunning the same piece of code
  result = double_and_add(i, j);
  // Redoing the calculation with the second argument defaulted
  result = double_and_add(i);
}
