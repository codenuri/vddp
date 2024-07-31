// Edit2.cpp : template method 패턴을 사용한 코드
// => 변하는 것을 가상함수로
// => NumEdit 가 "Edit 기능과 Validation 기능"을 모두 가지게 된다.

// => Validation 정책에 NumEdit소유 이므로
//    다른 입력도구에서 사용할수 없고
//    실행시간에 다른 정책으로 변경할수도 없다.


// Edit3.cpp : Strategy 패턴을 사용한 코드
// => 변하는 것을 다른 클래스로
// => 특징 1. Edit 와 Validation 기능이 분리되어있다
//		     다른 입력도구에서도 DigitValidation 사용가능

// => 특징 2. 실행시간에 Validation 정책을 변경할수 있다.


// 도형편집기의 draw/draw_imp 예제에서
// => 사각형을 그리는 방법은 "다른 클래스에서 사용할필요 없다."
// => 사각형을 그리는 방법은 "실행시간에 변경될 필요도 없다."
// => 사각형을 그리려면 "멤버 데이타에 접근해야 한다."
//    template method 는 변하는 것을 멤버 함수(가상함수)로 분리하므로
//    가상함수에서는 private 접근 가능하다.
