#include <iostream>
bool makeNoise() {
  std::cout << "The makeNoise() function was called!\n";
  return true;
}
int main() {
  double pi{3.141592653589793};
  float pi_narrowed{pi}; // This conversion is a warning with {}
  int compiles_with_warning{pi};
  // Alternatives to the {}-syntax for initialization
  // Note the missing warnings when you compile these!
  // The .0 is to make sure that we do floating-point division and not integer division 
  // 
  int compiles = 3.0 / 2;
  int compiles_too(3.0 / 2);

  // Tell the compiler that you are doing this on purpose and you are aware of
  // the risks involved
  float compiles_without_warning{static_cast<float>(pi)};
  // int error {3.14}; // Conversion with literal is an error with {}

  // On older compilers, combining auto and {} for initialization can sometimes
  // get weird. If you have a less ancient compiler than the default one on
  // Lunarc without the course container (it was released in 2015!), you can use
  // this syntax without problem.
  //
  // auto automatic{3 / 2};

  // Note: No {} initialization as this would be an error (for a good reason!)
  bool integerAsBoolean = 3;
  if (integerAsBoolean) {
    std::cout << 3 << " is treated as true" << std::endl;
  } else {
    std::cout << 3 << " is treated as false" << std::endl;
  }
  integerAsBoolean = 0;
  if (integerAsBoolean) {
    std::cout << 0 << " is treated as true" << std::endl;
  } else {
    std::cout << 0 << " is treated as false" << std::endl;
  }
  // Boolean logic will short-circuit
  // makeNoise will never be evaluated in these two conditions
  // To see this: Try puttin a breakpoint inside the makeNoise function
  if (false && makeNoise()) {
  }
  if (true || makeNoise()) {
  }

  auto automatic = 3 / 2;         // int
  auto automatic_double = 3 / 2.; // double
  int test{automatic};

  std::cout << automatic_double;
  return 0;
}
