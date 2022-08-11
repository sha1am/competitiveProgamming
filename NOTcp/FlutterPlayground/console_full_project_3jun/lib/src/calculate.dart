import 'package:calculator/calculator.dart';
// export 'calculate.dart';

//parentCalculatorFunction
double calculateP(int a, int b, int input) {
  if (input == 1)
    return calculateAdd(a, b);
  else if (input == 2)
    return calculateSub(a, b);
  else if (input == 3)
    return calculateMultiply(a, b);
  else if (input == 4)
    return calculateDiv(a, b);
  else
    return -1;
}

double calculateAdd(int a, int b) {
  return add(a, b).toDouble();
}

double calculateSub(int a, int b) {
  return subtract(a, b).toDouble();
}

double calculateMultiply(int a, int b) {
  return multi(a, b).toDouble();
}

double calculateDiv(int a, int b) {
  return divide(a, b);
}
