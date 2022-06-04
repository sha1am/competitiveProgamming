import 'package:console_full_project_3jun/console_full_project_3jun.dart'
    as console_full_project_3jun;

void main(List<String> arguments) {
  try {
    print('Hello world: ${console_full_project_3jun.calculate(arguments)}!');
  } catch (e) {
    print("Atleast one argument is not an integer!!!");
   }
} 
