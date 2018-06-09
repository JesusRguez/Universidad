import Tkinter, serial, time

root = Tkinter.Tk()
orientacion = 'N'; #N norte S sur E este W oeste
rx=15 #Global Variables initialized at 6 because its the center of the Matrix
ry=15 # 

for x in range(0,31):
    for y in range (0,31):
        if x==0 or y==0 or x==30 or y==30: # Loops that draw de border of the labyrinth
            label2 = Tkinter.Label(root, text=" # ").grid(row=x, column=y)
        else:
            label2 = Tkinter.Label(root, text="  ").grid(row=x, column=y)



def Casilla(x, y): # Draws a O if theres no Wall in the square
    Tkinter.Label(root, text=" O ").grid(row=x, column=y)

def Muro(x, y): # Draws a O if theres a Wall in the square
    Tkinter.Label(root, text=" X ").grid(row=x, column=y)

def Robot(x, y): # Draws a R where the Robot is
    Tkinter.Label(root, text=" R ").grid(row=x, column=y)

def Inicial(x, y): # Draws a R where the Robot is
    Tkinter.Label(root, text=" I ").grid(row=x, column=y)

def Orienta(Cadena):
    global orientacion
    global rx,ry
    Casilla(rx,ry)
    Delante = Cadena[0]
    Izq = Cadena[1]
    Dcha = Cadena[2]
    Detras = Cadena[3]
    Mov = Cadena[4]
    if(orientacion == 'N'):
        Delante = Cadena[0]
        Izq = Cadena[1]
        Dcha = Cadena[2]
        Detras = Cadena[3]
        Mov = Cadena[4]
        
    if(orientacion == 'S'):
        Delante = Cadena[3]
        Izq = Cadena[2]
        Dcha = Cadena[1]
        Detras = Cadena[0]
        Mov = Cadena[4]
        
    if(orientacion == 'E'):
        Delante = Cadena[1]
        Izq = Cadena[3]
        Dcha = Cadena[0]
        Detras = Cadena[2]
        Mov = Cadena[4]

    if(orientacion == 'W'):
        Delante = Cadena[2]
        Izq = Cadena[0]
        Dcha = Cadena[3]
        Detras = Cadena[1]
        Mov = Cadena[4]
    
    if(Delante == 'X'):
        Muro(rx-1,ry)
    else:
        Casilla(rx-1,ry)
            
    if(Izq == 'X'):
        Muro(rx,ry-1)
    else:
        Casilla(rx,ry-1)

    if(Dcha == 'X'):
        Muro(rx,ry+1)
    else:
        Casilla(rx,ry+1)

    if(Detras == 'X'):
        Muro(rx+1,ry)
    else:
        Casilla(rx+1,ry)

    newori = orientacion;
    if(Mov == '0'):
        if(orientacion == 'N'):
            rx=rx-2
        if(orientacion == 'S'):
            rx=rx+2
        if(orientacion == 'E'):
            ry=ry+2
        if(orientacion == 'W'):
            ry=ry-2
        
    if(Mov == '1'):
        if(orientacion == 'N'):
            newori = 'W'
            ry=ry-2
        if(orientacion == 'W'):
            newori = 'S'
            rx=rx+2
        if(orientacion == 'E'):
            newori = 'N'
            rx=rx-2
        if(orientacion == 'S'):
            newori = 'E'
            ry=ry+2
            
    if(Mov == '2'):
        if(orientacion == 'N'):
            newori = 'E'
            ry=ry+2
        if(orientacion == 'W'):
            newori = 'N'
            rx=rx-2
        if(orientacion == 'E'):
            newori = 'S'
            rx=rx+2
        if(orientacion == 'S'):
            newori = 'W'
            ry=ry-2
            
    if(Mov == '3'):
        if(orientacion == 'N'):
            newori = 'N'
            rx=rx+2
        if(orientacion == 'W'):
            newori = 'W'
            ry=ry+2
        if(orientacion == 'E'):
            ry=ry-2
            newori = 'E'
        if(orientacion == 'S'):
            rx=rx-2
            newori = 'S'
            
    if(Mov == '5'):
        if(orientacion == 'N'):
            newori = 'E'
            rx=rx+2
        if(orientacion == 'W'):
            newori = 'N'
            ry=ry+2
        if(orientacion == 'E'):
            ry=ry-2
            newori = 'S'
        if(orientacion == 'S'):
            rx=rx-2
            newori = 'W'
            
    if(Mov == '4'):
        if(orientacion == 'N'):
            newori = 'W'
            rx=rx+2
        if(orientacion == 'W'):
            newori = 'S'
            ry=ry+2
        if(orientacion == 'E'):
            ry=ry-2
            newori = 'N'
        if(orientacion == 'S'):
            rx=rx-2
            newori = 'E'
    orientacion = newori
        
    
def RecibeCelda(Cadena): #Recibes an String that describes the actual situation
    global rx,ry # Uses the global Variables 
    Orienta(Cadena)
    Robot(rx,ry) #Allocates the Robot at the new Position

##### MAIN CODE
try:
    arduino=serial.Serial("COM4",9600)
    arduino.write('e')
    while arduino.read() != 'e':
        root.update()
    while True:
        Inicial(15,15)
        c0 = arduino.read()
        c1 = arduino.read()
        c2 = arduino.read()
        c3 = arduino.read()
        c4 = arduino.read()
        cadena = c0+c1+c2+c3+c4
        print cadena
        Robot(rx,ry)
        print orientacion
        RecibeCelda(cadena)
        time.sleep(1)
        root.update()
    root.mainloop()
    Robot(rx,ry)
    arduino.close()    
    Robot(rx,ry)

except:

    print "Fallo"
    exit()



##### END OF MAIN CODE


