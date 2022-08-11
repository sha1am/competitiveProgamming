// import 'package:console_full_project_3jun/console_full_project_3jun.dart'
//     as console_full_project_3jun;
// // you need to import this one because you only imported the 'console_full_project_3jun.dart" file only in above code
// import 'package:console_full_project_3jun/src/calculate.dart';

import 'package:console_full_project_3jun/src/calculate.dart';
import 'dart:io';
import 'package:calculator/calculator.dart';
import 'package:console_full_project_3jun/console_full_project_3jun.dart';
import 'package:printerr/printerr.dart';

void main(List<String> arguments) {
  try {
    // print('Hello world: ${console_full_project_3jun.calculate(arguments)}!');
    print("Type 1 for addtion ,2 for sub, 3 for mult, 4 for div");
    //take input
    int? input = 1;
    int? a = 5;
    int? b = 4;
    //now according to input print out the results
    a = int.parse(stdin.readLineSync()!);
    b = int.parse(stdin.readLineSync()!);
    input = int.parse(stdin.readLineSync()!);
    double ans = calculateP(a, b, input).toDouble();

    //now I will use printerr (ie. regular dependency) package to print my answer;
    printFun(ans);
  } catch (e) {
    print("Atleast one argument is not an integer!!!");
  }
}
