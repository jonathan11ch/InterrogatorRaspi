#Reader Object
import RPi.GPIO as GPIO
import time
#pgio ports to be used:
#gpio 2,3,4,17,27,22,10,9,11,5
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

	def read_register(self):
		data = [0]*8
		data[0] = GPIO.input(self.Bit1)
		data[1] = GPIO.input(self.Bit2)
		data[2] = GPIO.input(self.Bit3)
		data[3] = GPIO.input(self.Bit4)
		data[4] = GPIO.input(self.Bit5)
		data[5] = GPIO.input(self.Bit6)
		data[6] = GPIO.input(self.Bit7)
		data[7] = GPIO.input(self.Bit8)
		print data
		GPIO.output(self.Tx, 1)

	def onDataCallback(self, channel):
		self.read_register()
	
	def shutdown(self):
		print 'shutdown'
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


