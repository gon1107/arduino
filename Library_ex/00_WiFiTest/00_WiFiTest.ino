// WiFi 모듈 ESP-01 테스트 코드

#include "WiFiEsp.h"
#include "SoftwareSerial.h"
SoftwareSerial Serial1(2, 3); // TX, RX (아두이노는 RX, TX 순)

char ssid[] = "HYOSUNG-2G"; // 공유기 WiFi 이름
char pass[] = "hshs7001"; // 공유기 비밀번호

WiFiEspServer server(80);

void setup() {
  // debugging을 위한 시리얼 초기화
  Serial.begin(9600);

  // ESP-01 모듈을 위한 시리얼 초기화
  Serial1.begin(9600);

  // ESP 모듈 초기화
  WiFi.init(&Serial1);

  Serial.print("연결을 시도 중 입니다. WPA SSID: ");
  Serial.println(ssid);

  // WiFi 네트워크 연결
  WiFi.begin(ssid, pass);

  Serial.println("연결 되었습니다.");

  // 아두이노 웹 서버 시작
  server.begin();
}

void loop() {
  // 클라이언트 접속여부 확인 (Listen)
  WiFiEspClient client = server.available();

  if (client) {
    Serial.println("새로운 클라이언트 접속");

    // 테스트를 위한 HTML 응답
    client.print("HTTP/1.1 200 OK\r\n"); // HTTP 프로토콜 사용 상태코드 200 OK, "/r\n"은 엔터키
    client.print("Content-Type: text/html\r\n"); // 클라이언트에게 현재 문서의 타입을 알려준다.
    client.print("\r\n"); // 한 줄을 비운 뒤에 나오는 정보는 문서의 내용이다.
    client.print("<!DOCTYPE HTML>\r\n");
    client.print("<html>\r\n");
    client.print("<h1>Arduino Server Success!!</h1>\r\n");
    client.print("</html>\r\n");
    client.flush(); // 클라이언트에게 보내줄 정보를 누락없이 마무리하여 보내주도록 하는 함수
    client.stop(); // 서버와 클라이언트 간의 연결을 끊어주는 역할
    Serial.println("클라이언트 연결 끊김");
  }
}
