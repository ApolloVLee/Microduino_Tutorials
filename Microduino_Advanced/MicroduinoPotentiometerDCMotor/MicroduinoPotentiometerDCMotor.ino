int potPin = A0; //��λ����������
int motorPin = 9;//�������
int potValue = 0;//�����λ����ֵ
int motorValue = 0;//��¼�����ֵ
void setup() {
 Serial.begin(9600);
}
void loop() {
 potValue = analogRead(potPin);  //��ȡ��λ����ֵ
 motorValue = map(potValue, 0, 1023, 0, 255);//ӳ��Ϊ0~255֮�����ֵ
 analogWrite(motorPin, motorValue);//PWM�������
 //��ʾ
 Serial.print("potentiometer = " );     
 Serial.print(potValue);
 Serial.print("\t motor = ");
 Serial.println(motorValue);
 delay(2);    
}
