#define LEDPIN  (16)

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Start!");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("HIGH");
  digitalWrite( LEDPIN, HIGH );
  delay(1000);
  Serial.println("LOW");
  digitalWrite( LEDPIN, LOW );
  delay(1000);
}
