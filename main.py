import socket
import time

import network
from machine import PWM, Pin


def main():
    servo = PWM(Pin(2), freq=50)

def set_angle(angle):
    dute = int((angle/180) * ())
