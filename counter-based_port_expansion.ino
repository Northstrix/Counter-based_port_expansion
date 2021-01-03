// Counter-based port expansion
// © Copyright Maxim Bortnikov 2021
//For more information visit: https://github.com/Northstrix/Counter-based_port_expansion
#define data 6 // data pin
#define res 5 // reset pin
#define ref 3 // refresh pin
void cbpe (int n){
  digitalWrite(res, HIGH); //set 0 to all output
  delayMicroseconds(1);
  digitalWrite(res, LOW); // allow the counter to count
  delayMicroseconds(1);
  
  for (int i = 0; i<n; i++){ // data output
    digitalWrite(data, HIGH);
    delayMicroseconds(1);
    digitalWrite(data, LOW);
    delayMicroseconds(1);    
  }
  
  digitalWrite(ref, HIGH); // refresh
  delayMicroseconds(1);
  digitalWrite(ref, LOW);
}
void setup() {
pinMode(data, OUTPUT);
pinMode(res, OUTPUT);
pinMode(ref, OUTPUT);
digitalWrite(res, HIGH);
digitalWrite(data, LOW);
digitalWrite(ref, LOW);
}
void loop(){
for(int n = 0; n<16 ; n++){ // counter test
  cbpe(n);
  delay(500);
}
}
