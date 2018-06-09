import Tkinter

root = Tkinter.Tk()

rx=6 #Global Variables initialized at 6 because its the center of the Matrix
ry=6 # 

for x in range(0,13):
    for y in range (0,13):
        if x==0 or y==0 or x==12 or y==12: # Loops that draw de border of the labyrinth
            label2 = Tkinter.Label(root, text=" # ").grid(row=x, column=y)
        else:
            label2 = Tkinter.Label(root, text="  ").grid(row=x, column=y)


def Casilla(x, y): # Draws a O if theres no Wall in the square
    Tkinter.Label(root, text=" O ").grid(row=x, column=y)

def Muro(x, y): # Draws a O if theres a Wall in the square
    Tkinter.Label(root, text=" X ").grid(row=x, column=y)

def Robot(x, y): # Draws a R where the Robot is
    Tkinter.Label(root, text=" R ").grid(row=x, column=y)
    
def RecibeCelda(Cadena): #Recibes an String that describes the actual situation
    global rx,ry # Uses the global Variables 
    Casilla(rx,ry) #Deletes de robot ol position
    Delante = Cadena[0]
    Izq = Cadena[1]
    Dcha = Cadena[2]
    Mov = Cadena[3]
    
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

        
    if(Mov == '0'):
        rx=rx-1
    if(Mov == '1'):
        ry=ry-1
    if(Mov == '2'):
        ry=ry+1
    if(Mov == '3'):
        rx=rx+1
    Robot(rx,ry) #Allocates the Robot at the new Position

##### MAIN CODE
Robot(rx,ry)
RecibeCelda("OOX1")
#Casilla(rx,ry)
##### END OF MAIN CODE


root.mainloop()

