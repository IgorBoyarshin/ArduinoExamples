#include <SoftwareSerial.h>

SoftwareSerial SIM800(8, 9); //RX, TX

const bool OUTPUT_CMD = true;
const bool INPUT_CMD = false;


void setup() {
  initSim();

  const String telephoneNumber = "+380506527183";
  const String message = "ku";
  sendSMS(telephoneNumber, message);
}


void initSim() {
  if (OUTPUT_CMD) {
    Serial.begin(9600); // Speed of data exchange with PC
    Serial.println(":> Started.");
  }

  SIM800.begin(9600); // speed of data exchange with modem

  sendATCommand("AT", true); // check-check
  //sendATCommand("AT+ATE0", false); // turn off echo mode
  sendATCommand("AT+CMGF=1;&W", true); // enter text mode
}


void sendSMS(String phone, String message) {
  // Prepare to receive message text(after ">"
  sendATCommand("AT+CMGS=\"" + phone + "\"", true);
  // Enter message text
  sendATCommand(message + (String)((char)0x1A), true); // must end with 0x1A
}


String sendATCommand(String cmd, bool waitForResponse) {
  if (OUTPUT_CMD) {
    Serial.print(":> ");
    Serial.println(cmd);
  }

  SIM800.println(cmd);

  String response = "";
  if (waitForResponse) {
    response = waitResponse();

    /*
    if (response.startsWith(cmd)) {
      response.remove(0, cmd.length() + 3); // "\r\n"
    } else if (response.substring(1).startsWith(cmd)) {
      response.remove(0, cmd.length() + 4); // "\r\n" and some weird char at the start
    }
    */

    if (OUTPUT_CMD) {
      Serial.print(response);
    }
  }

  return response;
}


String waitResponse() {
  const unsigned int ONE_SECOND = 1000;
  const long timeout = millis() + 100 * ONE_SECOND;

  while (!SIM800.available() && (millis() < timeout));

  String response = "";
  if (SIM800.available()) {
    response = SIM800.readString();
  } else {
    if (OUTPUT_CMD) {
      Serial.println(":> Response has timed out.");
    }
  }

  return response;
}


void loop() {
  if (SIM800.available()) {
    String response = waitResponse();
    response.trim();

    if (OUTPUT_CMD) {
      Serial.println(response);
    }

    if (response.startsWith("+CMGS:")) { // Receive message about SMS sending
      int index = response.lastIndexOf("\r\n");
      String result = response.substring(index + 2, response.length());
      result.trim();

      if (result == "OK") {
        Serial.println (":> Message was sent. OK");
      } else {
        Serial.println (":> Message was not sent. Error");
      }
    }
  }

  /*
  if (INPUT_CMD) {
    if (Serial.available()) {
      SIM800.write(Serial.read());
    };
  }
  */
}
