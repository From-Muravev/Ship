int H1 = 9;
int H2 = 10;
int H3 = 11;
int H4 = 12;
int L1 = 4;
int L2 = 3;
int L3 = 2;
int L4 = 7;


void setup() 
{
  Serial.begin(9600);
  Serial.setTimeout(5);
  
  pinMode(H1,OUTPUT);
  pinMode(H2,OUTPUT);
  pinMode(H3,OUTPUT);
  pinMode(H4,OUTPUT);
  pinMode(L1,OUTPUT);
  pinMode(L2,OUTPUT);
  pinMode(L3,OUTPUT);
  pinMode(L4,OUTPUT);
  stop1();
}

void forward() {
  digitalWrite(H1, LOW);
  digitalWrite(H2, HIGH);
  digitalWrite(H3, HIGH);
  digitalWrite(H4, LOW);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(L3, LOW);
  digitalWrite(L4, HIGH);
}

void backward() {
  digitalWrite(H1, HIGH);
  digitalWrite(H2, LOW);
  digitalWrite(H3, LOW);
  digitalWrite(H4, HIGH);
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, HIGH);
  digitalWrite(L4, LOW);
}
void left() {
  digitalWrite(H1, HIGH);
  digitalWrite(H2, LOW);
  digitalWrite(H3, HIGH);
  digitalWrite(H4, LOW);
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, LOW);
  digitalWrite(L4, HIGH);
}
void right() {
  digitalWrite(H1, LOW);
  digitalWrite(H2, HIGH);
  digitalWrite(H3, LOW);
  digitalWrite(H4, HIGH);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(L3, HIGH);
  digitalWrite(L4, LOW);
}
void stop1(){
  digitalWrite(H1, LOW);
  digitalWrite(H2, LOW);
  digitalWrite(H3, LOW);
  digitalWrite(H4, LOW);
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(L3, LOW);
  digitalWrite(L4, LOW);
}

void loop(){
if (Serial.available() > 0) {
  int data = Serial.parseInt();
  if (data != 0)  {
    if (data == 5) 
    {
      stop1();
      Serial.print("stop...");
     }
    else if (data == 1) {
      forward();
      Serial.print("forward...");
      }
    else if (data == 2) {
      backward();
      Serial.print("backward...");
    }
    else if (data == 3) {
      right();
      Serial.print("right...");
    }
    else if (data == 4) {
      left();
      Serial.print("left...");
    }
    else {
      Serial.print("Unknown command");
   }
  }
 }
}
