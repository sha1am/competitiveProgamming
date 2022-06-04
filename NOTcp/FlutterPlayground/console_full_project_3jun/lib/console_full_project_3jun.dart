int calculate(List<String> arguments) {
  int sum = 0;
  for (int i = 0; i < arguments.length; i++) {
    sum += int.parse(arguments[i]);
  }
  return sum;
}
