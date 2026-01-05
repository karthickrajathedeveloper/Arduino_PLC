#define IN I1
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(IN, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hi");
  int a = digitalRead(IN);
  Serial.println(a);
  delay(500);

}
