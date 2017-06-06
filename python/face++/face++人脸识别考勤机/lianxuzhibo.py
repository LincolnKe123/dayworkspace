import subprocess
import time

#file_number = 0

while True:
    #file_name = dir + format(file_number,"05d")+".jpg"
    #file_number = file_number + 1
    subprocess.call(["raspistill","-w","400","-h","400","-e","jpg","-n","-t","1","-o",'live.jpg'])
    subprocess.call(["cp","-f","live.jpg","live.jpg"])
    subprocess.call(["python","opencv.py"])
    time.sleep(0.5)
    
