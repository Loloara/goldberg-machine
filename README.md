# Goldberg Challenge - 2017 SKT IoT 메이커톤
![Alt text](/images/machine.jpg?raw=true "Machine")
![Alt text](/images/machine2.jpg?raw=true "Machine2")

## Overview
본 코드는 2017 SKT IoT 메이커톤 중에 진행된 미니 대회인 골드버그 챌린지에서 사용한 아두이노 코드이다.
* 골드버그 챌린지 : 퓰리처상을 수상한 미국의 만화가 Rube Goldberg 의 이름에서 유래된 것으로 생김새나 작동원리는 아주 복잡하고 거창한데 하는 일은 아주 단순한 기계를 일컫는 말이기도 하다. 만화적 상상력으로 만들어진 기계로 효율성보다는 재미와 기발함을 전면에 내세운 장치.

## Project Goals
아두이노와 센서를 활용하여 창의적인 방법으로 골드버그 챌린지를 완수하는 것.

- 창의성 보이기
- 센서 다수 활용하기 (조도 센서, 서보 모터, 초음파 센서, LED)
- 센서값 정밀 조절하기
- 테스트시 90% 이상 골드버그 챌린지 성공시키기

## Main Features
- 쇠구슬이 널판지에 떨어진다.
- 널판지의 위치가 변한다.
- 초음파 센서가 이를 감지하여 LED를 킨다.
- 조도 센서가 이를 감지하여 모터를 돌린다.
- 모터의 회전 운동력은 특정 기구를 통해 수평 운동력으로 치환된다.
- 이 운동력을 이용하여 풍선을 터뜨린다.

## Some Challenges
- 모터의 회전 운동력을 풍선을 터뜨리기 위해 수평운동으로 변환하는 방법을 고민해야 했다.
- 시연하는 곳의 조명 밝기에 따라서 조도 센서 초기값을 새로 세팅해야하는 이슈가 있었다.

## Won the prize from SKT
![Alt text](/images/prize.jpg?raw=true "Prize")