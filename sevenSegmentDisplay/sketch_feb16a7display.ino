int pins[] = {3, 4, 5, 6, 7, 10, 11}; // Arduino pins connected to segments a-g

// Segment patterns for each digit from 0 to 9 (1 = ON for Common Cathode)
const int sequence[10][7] = {
  // a, b, c, d, e, f, g
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  // Set all segment pins as outputs
  for (int i = 0; i < 7; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  // Loop through numbers 0 to 9
  for (int i = 0; i < 10; i++) {
    displayNumber(i);
    delay(1000); // Delay for 1 second
  }
}

// Function to display a specific number
void displayNumber(int num) {
  for (int i = 0; i < 7; i++) {
    // For common cathode, HIGH turns the segment ON
    digitalWrite(pins[i], sequence[num][i] == 1 ? HIGH : LOW);
  }
}
