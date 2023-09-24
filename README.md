# FDF란?
FDF란 2차원 평면상의 도형을 3차원처럼 보여주는 투영법을 적용하여 보여주는 기법입니다.
이때, 사용한 투영법은 isometric projection이며 오일러 각을 사용하였습니다.
<br><br>


## Isometric projection란?
등축투영법을 의미합니다. 대각선을 화면에 수직으로 하여 입방체를 투영했을 때 세 측변이 각각 120°로 만나고, 윤곽이 정육각형으로 되는 투영법이라고 할 수 있습니다. 삼각함수를 이용하고, 특히 오일러 각을 회전행렬로 변환합니다.

![Untitled](https://github.com/8luerose/FDF/assets/105616046/292b32d9-dd70-44b9-bc0d-5816b1c2d6da)
![Untitled (1)](https://github.com/8luerose/FDF/assets/105616046/5996fff7-9568-4ef1-a41a-5a418893a9b9)
![Untitled (2)](https://github.com/8luerose/FDF/assets/105616046/321caba3-7839-49d4-98d7-c43673d804d5)
![Untitled (3)](https://github.com/8luerose/FDF/assets/105616046/333e244b-b247-4ede-b7ab-44f52c6c78fa)

공식<br>
<img width="798" alt="스크린샷 2023-09-25 오전 2 30 34" src="https://github.com/8luerose/FDF/assets/105616046/cc719f84-3bf5-4c8b-9739-7bddf5c7b2e3">
<img width="544" alt="스크린샷 2023-09-25 오전 2 14 11" src="https://github.com/8luerose/FDF/assets/105616046/63fff799-d046-4423-834b-a4c0cc4c3911">
![image](https://github.com/8luerose/FDF/assets/105616046/b7995b94-91fd-4a2e-af2e-486049b25c22)
<br><br>


## Digital Differential Analyzer - DDA 알고리즘
DDA 알고리즘은 양 끝점이 주어졌을 때 화면 위 직선을 그릴 수 있는 알고리즘입니다.
양 끝점을 이용해서 X, Y의 증가분을 구합니다. 이후 X 가 1 증가할 때 Y가 어느정도로 증가하는지를 계산,
좌표를 구하고 해당 좌표의 픽셀을 채워줍니다. X가 1만큼 증가할 때 Y는 그만큼 증가하지 못했다면 X축쪽으로 기운 것이고, Y가 1만큼 증가할 때 X가 그만큼 증가하지 못했다면 Y축 쪽으로 감소한 것입니다.

> **( 참고사항 )** 브레젠험 알고리즘(Bresenham’s line algorithm)도 직선을 연결할 수 있습니다. 다만, DDA는 double 자료형이 사용되며, 브레젠험 알고리즘은 int 자료형이 사용된다는 차이가 있습니다. 부동소수점까지 처리해왔기 때문에 double형이 사용되는 DDA를 사용하였습니다.


<br><br>
## 전체적인 과정
1. 파일 이름 유효성 체크: .fdf  4개가 맞으면 맞다
2. 파싱: 크기 구하기 → 좌표 부여(컬러 포함)
3. 등축투영: z축으로 회전 → x축으로 회전
4. 등축투영한 x,y좌표 중 최대 최소 값 구하기
5. mlx 세팅
6. 사이즈업: 기존 좌표는 픽셀 단위 = 작게 나온다 → 윈도우 벗어나지 않는 gap 구하기 → 키운다
7. 가로선(draw_col) 그려주기: dda 알고리즘으로 선분을 이어준다(gap적용)
8. 세로선(draw_row) 그려주기: dda 알고리즘으로 선분을 이어준다(gap적용)
9. 이미지 출력
<br>

### 매우 잘된 예시
![captura](https://github.com/8luerose/FDF/assets/105616046/47d829fe-748f-432b-8597-74618ce543de)
-> [https://github.com/ailopez-o/42Barcelona-FdF](https://github.com/ailopez-o/42Barcelona-FdF.git)
![zoom_alt](https://github.com/8luerose/FDF/assets/105616046/51e89e7c-3832-4e44-b2a2-4cfc8145ae7e)
-> [https://github.com/bil0u/FdF.git](https://github.com/bil0u/FdF.git)
<br><br>

## 주의할 점
컴파일에 사용되는 mlx라이브러리는 버전이 다양합니다. 해당 파일에서는 x86 아키텍처가 사용되었으므로, 개인 맥북과 같은 ARM 아키텍쳐에서는 컴파일이 불가능합니다.
