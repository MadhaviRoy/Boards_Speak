import RPi.GPIO as GPIO	
#import firebase module from library	
from firebase import firebase
#Set GPIO warnings to FALSE (Optional)
GPIO.setwarnings(False)			
#Set GPIO mode to Board
GPIO.setmode(GPIO.BOARD)
#Use FirebaseApplication method from firebase library to enter #the firebase database url
firebase=firebase.FirebaseApplication('https://*****.firebaseio.com/')
#configure GPIO pin 7 as output (Relay/LED to be connected here)
GPIO.setup(7,GPIO.OUT)
#Infinite LOOP
while True:
#Use get method to get the value of Light tag which is in #accordance to the command given by the user 
        result=firebase.get('/IoTDemoApp','Light')
#Compare the value and turn light ON/OFF accordingly
        if result =='1':	
                GPIO.output(7,True)
        else:
                GPIO.output(7,False)
        print(result)		#print the value for varification (not required later)
