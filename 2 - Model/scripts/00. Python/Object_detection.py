import socket
from ultralytics import YOLO
import keyboard


#----Initialize data and count----
data = [320.0, 240.0]
speed = [0.0, 0.0]
count = 0

#----Ip address and Port----
ip_address = "127.0.0.1"
port = 50924

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

model = YOLO("Path to file best.pt")

#----Run Yolo using the virtual camera "1"----
results = model("1", stream=True, show = True, stream_buffer = False, rect = True)

for r in results:
    if r.boxes.shape[0] == 0:
        data = [320.0, 240.0]

    else:
        vector = r.boxes.xywh[[0,0], [0,1]] 
        vector = vector.tolist() 
        data = vector
        data = [round(num, 4) for num in data]  
    data2 = str(data[0]).encode('ascii') + b' ' + str(data[1]).encode('ascii') + b'\n'
    sock.sendto(data2, (ip_address, port))

    if keyboard.is_pressed('x'):
        print('Finished by the User.')
        sock.close()
        break