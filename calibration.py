import time

from machine import PWM, Pin

# Setup Servo on GPIO 2
servo = PWM(Pin(2), freq=50)

def set_angle(angle):
    # Standard 16-bit duty cycle for MicroPython (0-65535)
    # 0 degrees   ~ 1638 duty
    # 180 degrees ~ 8192 duty
    if 0 <= angle <= 180:
        duty = int((angle / 180) * (8192 - 1638) + 1638)
        servo.duty_u16(duty)
        print(f"Servo set to: {angle} degrees")
    else:
        print("Error: Angle must be between 0 and 180")

# --- INTERACTIVE CALIBRATION ---
print("--- MG996R Calibration Tool ---")
print("Type 'set_angle(90)' in the shell to center the motor.")
print("Find the 'ON' angle (e.g., 150) and the 'OFF' angle (e.g., 30).")
