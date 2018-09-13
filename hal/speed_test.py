import RPi.GPIO as GPIO
import gpio_reader
o = gpio_reader.GpioReader()
b = o.Bit1
import time
a = time.time()
c = GPIO.input(23) 
#a = time.time()
#o.read_register()
b = time.time()
print b-a 
