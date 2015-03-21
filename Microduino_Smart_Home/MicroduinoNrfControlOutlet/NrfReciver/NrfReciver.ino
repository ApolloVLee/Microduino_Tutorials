#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>

#define outletPin 6

// nRF24L01(+) radio attached using Getting Started board 
RF24 radio(9,10);

// Network uses that radio
RF24Network network(radio);

// Address of our node
const uint16_t this_node = 0;

// Address of the other node
const uint16_t other_node = 1;

// Structure of our payload
struct payload_t
{
  //unsigned long ms;
  unsigned long counter;
};

void setup(void)
{
  Serial.begin(57600);
  Serial.println("RF24Network/examples/helloworld_rx/");
 
  SPI.begin();
  radio.begin();
  network.begin(/*channel*/ 90, /*node address*/ this_node);

  pinMode(outletPin, OUTPUT);
  digitalWrite(outletPin,LOW);
}

void loop(void)
{
  // Pump the network regularly
  network.update();

  // Is there anything ready for us?
  while ( network.available() )
  {
    // If so, grab it and print it out
    RF24NetworkHeader header;
    payload_t payload;
    network.read(header,&payload,sizeof(payload));

    Serial.print("Received packet #");

    if(payload.counter) {
      digitalWrite(outletPin,HIGH);
    }else{
      digitalWrite(outletPin,LOW);
    }


    Serial.print(payload.counter);
  }
}
