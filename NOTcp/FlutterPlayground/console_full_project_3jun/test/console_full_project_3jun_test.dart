import 'package:console_full_project_3jun/console_full_project_3jun.dart';
import 'package:test/test.dart';

void main() {
  test('calculate', () {
    expect(calculate(['7', '6']), 13);
    expect(calculate(['8', '6']), 14);
  });
}
