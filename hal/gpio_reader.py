#Reader Object
import RPi.GPIO as GPIO
import time
import numpy as np
import threading 
#pgio ports to be used:
#gpio 23,24,4,17,27,22,10,9,11,5
#pin  3,5,7,11,13,15,19,21,23,29

class GpioReader(object):
	def __init__(self):
		GPIO.setmode(GPIO.BCM)
		print "reader created"
		#define bit pins 
		self.Bit1 = 23
		self.Bit2 = 24
		self.Bit3 = 4
		self.Bit4 = 17
		self.Bit5 = 27
		self.Bit6 = 22
		self.Bit7 = 10
		self.Bit8 = 9
		self.Rx   = 11
		self.Tx   = 14
		#setup input ports
 		GPIO.setup(self.Bit1, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
		GPIO.setup(self.Bit2, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
		GPIO.setup(self.Bit3, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
		GPIO.setup(self.Bit4, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
		GPIO.setup(self.Bit5, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
		GPIO.setup(self.Bit6, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
		GPIO.setup(self.Bit7, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
		GPIO.setup(self.Bit8, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
		GPIO.setup(self.Rx, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
		#setup output port
		GPIO.setup(self.Tx, GPIO.OUT, initial = GPIO.LOW)
		#set callbacks
		#GPIO.add_event_callback(self.Rx, self.onDataCallback)
		GPIO.add_event_detect(self.Rx, GPIO.FALLING, callback=self.onDataCallback, bouncetime=3)
		#create data buffer
		self.buffer = np.(array[0]*8)		
	]
	#read register function	
	def read_register(self):
		self.buffer[0] = GPIO.input(self.Bit1)
		self.buffer[1] = GPIO.input(self.Bit2)
		self.buffer[2] = GPIO.input(self.Bit3)
		self.buffer[3] = GPIO.input(self.Bit4)
		self.buffer[4] = GPIO.input(self.Bit5)
		self.buffer[5] = GPIO.input(self.Bit6)
		self.buffer[6] = GPIO.input(self.Bit7)
		self.buffer[7] = GPIO.input(self.Bit8)

	def convert_to_integer(self):
		s = ""
		for i in self.buffer:
			s = s + str(i)
		print "string " + s
		integer = int(s,2)
		print "integer " + str(integer)

		
	#callback function for the incoming data event
	def onDataCallback(self, channel):
		#read register		
		self.read_register()
		#perform conversion
		self.convert_to_integer()
		#set tx high to indicate end of data acquisition
		GPIO.output(self.Tx, 1)
	
	#shutdown method		
	def shutdown(self):
		print 'shutdown'
		#clear port configurations
		GPIO.cleanup()


if __name__=="__main__":
	o = GpioReader()
	time.sleep(1)	
	try:
	        while True:

			print 'reading'
			o.read_register()
			time.sleep(1)
    	
	except KeyboardInterrupt:
		o.shutdown()
		print 'End acquisition...'        	
		raise
    	except Exception as inst:
		print type(inst)
		print inst.args
		print inst	
		o.shutdown()
		print("error")
        	# report error and proceed


