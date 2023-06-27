// Line Follower Robot Code

// Pins connected to the infrared sensors
const int leftSensorPin = 2;
const int rightSensorPin = 3;

// Motor control pins
const int leftMotorPin = 4;
const int rightMotorPin = 5;

// Threshold values for sensor readings
const int sensorThreshold = 500;

// Motor speed values
const int baseSpeed = 150;  // Base motor speed
const int turnSpeed = 200;  // Speed for turning

void setup() {
  // Set sensor pins as inputs
  pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);

  // Set motor pins as outputs
  pinMode(leftMotorPin, OUTPUT);
  pinMode(rightMotorPin, OUTPUT);
}

void loop() {
  // Read sensor values
  int leftSensorValue = analogRead(leftSensorPin);
  int rightSensorValue = analogRead(rightSensorPin);

  // Compare sensor readings with the threshold
  bool leftLineDetected = (leftSensorValue > sensorThreshold);
  bool rightLineDetected = (rightSensorValue > sensorThreshold);

  // Line following logic
  if (!leftLineDetected && !rightLineDetected) {
    // Both sensors are off the line, move forward
    moveForward();
  } else if (leftLineDetected && !rightLineDetected) {
    // Left sensor detects the line, turn right
    turnRight();
  } else if (!leftLineDetected && rightLineDetected) {
    // Right sensor detects the line, turn left
    turnLeft();
  } else {
    // Both sensors detect the line, move forward
    moveForward();
  }
}

// Function to move the robot forward
void moveForward() {
  analogWrite(leftMotorPin, baseSpeed);
  analogWrite(rightMotorPin, baseSpeed);
}

// Function to turn the robot left
void turnLeft() {
  analogWrite(leftMotorPin, 0);
  analogWrite(rightMotorPin, turnSpeed);
}

// Function to turn the robot right
void turnRight() {
  analogWrite(leftMotorPin, turnSpeed);
  analogWrite(rightMotorPin, 0);
}
