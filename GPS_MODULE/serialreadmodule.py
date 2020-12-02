#!/usr/bin/python

#import libs
import serial
import sys
import requests
url = "http://svg.pxl-ea-ict.be/userlogin/addGpsData.php"
#Open serial port
#run "dmesg | grep tty" in terminal to see serial ports
ser = serial.Serial('/dev/ttyACM0', baudrate=9600) #ttyACM0 is the first USB serial device

#declare var to save data in
gpssplitlist = []
gpslist = [None] * 9
gpslabel = ["Time: ", "Status: ", "Latitude: ", "Hemisphere: ", "Longitude: ", "Hemisphere: ", "Speed: ", "Track Angle: ", "Date: "]

#functions
#convert latitude
def ConvertLat(valString, dirString):
    posneg = ''
    if dirString == 'S':
        posneg = '-'
    finalVLat = float(valString[:2])
    latMin = float(valString[2:]) / 60
    finalVLat = format(finalVLat + latMin, '0.6f')
    return posneg + str(finalVLat)

def ConvertLon(valString, dirString):
    posneg = ''
    if dirString == 'W':
        posneg = '-'
    finalVLon = float(valString[:3])
    lonMin = float(valString[3:]) / 60
    finalVLon = format(finalVLon + lonMin, '0.6f')
    return posneg + str(finalVLon)
    
def GetTime():
    return gpslist[0]
def GetStatus():
    return gpslist[1]
def GetLat():
    return gpslist[2]
def GetLon():
    return gpslist[4]
def GetGroundSpeed():
    return gpslist[6]
def GetAngle():
    return gpslist[7]

try:
    while 1: #Here be the actual program, loop a zillion times to get GNRMC over serial
        buf = str(ser.readline())
#        print(buf[2:-5])
        comp = buf.find("b'$GNRMC")
        if comp == 0:
            buf = buf[2:-5]
            gpssplitlist = buf.split(',')
            print(buf)
            #gpslist = gpssplitlist #okay okay, don't do that, that was bad
            gpslist[0] = gpssplitlist[1] #time hhmmss.ss
            gpslist[1] = gpssplitlist[2] #status, A = available, V = gps unavailable, maybe have a wait here until it becomes available
            if gpslist[1] == 'A': #lol why wait, if statements ftw
                gpslist[2] = ConvertLat(gpssplitlist[3], gpssplitlist[4]) #latitude
                gpslist[4] = ConvertLon(gpssplitlist[5], gpssplitlist[6]) #longtitude
            gpslist[3] = gpssplitlist[4] 
            gpslist[5] = gpssplitlist[6]
            gpslist[6] = gpssplitlist[7] #speed over ground in knots
            gpslist[7] = gpssplitlist[8] #course over ground in degrees
            gpslist[8] = gpssplitlist[9] #UTC date ddmmyy
            #buf2 = gpssplitlist[10].split('*')
            #gpslist[9] = buf2[0] #mode N = invalid, A = auto, D = differential, E = estimated
            
            #write to database
            payload = {'lon' : gpslist[4], 'lat' : gpslist[2]}
            r = requests.get(url, payload)
            print(gpslabel)
            print(gpslist)
        

except(KeyboardInterrupt):
    #close serial port on ctrl - c
    ser.close()
    sys.exit()
