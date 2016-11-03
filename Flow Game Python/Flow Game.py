import pygame, math, pickle
pygame.init()

#Setting up the display
game_display = pygame.display.set_mode((520,600))
pygame.display.set_caption("Flow")

#Defining colours
WHITE = (255,255,255) 
BLACK = (0,0,0)
PURPLE = (51,0,102)
LIGHT_PURPLE = (76,0,153)
RED = (200,0,0)
LIGHT_RED = (255,0,0)
BLUE = (0,102,204)
LIGHT_BLUE = (0,128,255)
YELLOW = (200,200,0)
LIGHT_YELLOW = (255,255,0)
GREEN = (34,177,76)
LIGHT_GREEN = (0,255,0)
GREY = (128,128,128)

score = 0

# This sets the margin between each square
MARGIN = 10

#Getting the mids postions into lists
a = 46
xlimit=5
ylimit=5
xlist = [0,0,0,0,0]
ylist = [0,0,0,0,0]
for nx in range (0,ylimit,1):
   for ny in range (0,xlimit,1):
       x = (nx+1)*(2*a+MARGIN) - a
       y = (ny+1)*(2*a+MARGIN) - a
       xlist[nx] = x
       ylist[ny] = y
        
#Display Grid
def display_squares():
    # This sets the WIDTH and HEIGHT of each grid location
    WIDTH = 92
    HEIGHT = 92
    # This sets the OFFSETX and OFFSETY of each grid location
    OFFSETX = 10
    OFFSETY = 10
    # Set the screen background
    game_display.fill(WHITE)
    
    # Draw the grid 
    for row in range(5):
        for column in range(5):
            color = GREY
            pygame.draw.rect(game_display,
                             color,
                             [OFFSETX + (MARGIN + WIDTH) * column,
                              OFFSETY + (MARGIN + HEIGHT) * row,
                              WIDTH,
                              HEIGHT])
            
    button("Menu", 350,530,100,50, LIGHT_BLUE, BLUE, "Menu")

#Defining Level 1            
def level1():
    #Drawing all the coloured circles for this level
    pygame.draw.circle(game_display, GREEN,[xlist[0],ylist[0]] , 40, 0)
    pygame.draw.circle(game_display, GREEN,[xlist[0],ylist[0]] , 40, 0)
    pygame.draw.circle(game_display, GREEN, [xlist[2],ylist[1]], 40, 0)
    pygame.draw.circle(game_display, YELLOW, [xlist[1],ylist[0]], 40, 0)
    pygame.draw.circle(game_display, YELLOW, [xlist[3],ylist[2]], 40, 0)
    pygame.draw.circle(game_display, RED, [xlist[4],ylist[0]], 40, 0)
    pygame.draw.circle(game_display, RED, [xlist[2],ylist[3]], 40, 0)
    pygame.draw.circle(game_display, PURPLE, [xlist[1],ylist[3]], 40, 0)
    pygame.draw.circle(game_display, PURPLE, [xlist[4],ylist[4]], 40, 0)
    pygame.draw.circle(game_display, BLUE, [xlist[2],ylist[2]], 40, 0)
    pygame.draw.circle(game_display, BLUE, [xlist[0],ylist[4]], 40, 0)

    #Putting the level circle positions to lists
    first_circle = [[xlist[0],ylist[0]],[xlist[1],ylist[0]],[xlist[4],ylist[0]],[xlist[1],ylist[3]],[xlist[2],ylist[2]]]
    second_circle = [[xlist[2],ylist[1]],[xlist[3],ylist[2]],[xlist[2],ylist[3]],[xlist[4],ylist[4]],[xlist[0],ylist[4]]]
    circle_colours = [GREEN,YELLOW,RED,PURPLE,BLUE]
    selected_colours = [LIGHT_GREEN,LIGHT_YELLOW,LIGHT_RED,LIGHT_PURPLE,LIGHT_BLUE]
    
    return first_circle, second_circle, circle_colours, selected_colours

#Finding nearest mid position 
def nearest_mid (xmouse,ymouse):
    xmid = 0
    ymid = 0
    closest_dist = 500
            #Getting the mid point 
    for x in xlist:
        for y in ylist:
            xmid = x
            ymid = y
            #Calculating distance between mid point and mouse click
            dist = math.hypot(xmouse-xmid, ymouse-ymid)
            #Checking if its a smaller distance
            if dist < closest_dist:
                closest_dist = dist
                nearestx = xmid
                nearesty = ymid
    return nearestx, nearesty

#Checking if the fist click was on a block with a circle.
def check_ifCircle (position):
   first_circle, second_circle, circle_colours, selected_colours = level1()
   circle_click = False
   circle_pos1 = ""
   circle_pos2 = ""
   colour_C = ""
   active_circle = "" 
   counter = 0
   #Checking the first list of circle positions
   for inner_circle in first_circle:
      counter += 1
      for item in inner_circle:
         circle_pos1 = inner_circle[0],inner_circle[1] 
         if position == circle_pos1:
            circle_click = True
            colour_C = circle_colours[counter - 1]
            active_circle = selected_colours[counter - 1]
            
   counter = 0
   #Checking the second list of circle positions
   for inner_circle in second_circle:
      counter += 1
      for item in inner_circle:
         circle_pos2 = inner_circle[0],inner_circle[1]      
         if position == circle_pos2:
            circle_click = True
            colour_C = circle_colours[counter - 1]
            active_circle = selected_colours[counter - 1]

   return circle_click, colour_C, active_circle

#Reference youtube video sentex
#Rendering the text
def text_objects(text, font):
    text_surface = font.render(text, True, BLACK)
    return text_surface, text_surface.get_rect()

#Reference youtube video sentex: Game Development in Python 3 With PyGame - 14 - Buttons Function
#Creating a buttons
def button(message, x, y, width, height, active, inactive, action=None):
    mouse_pos = pygame.mouse.get_pos()
    mouse_click = pygame.mouse.get_pressed()
    #Checking if the player has clicked on a server
    if x + width > mouse_pos[0] > x and y + height > mouse_pos[1] > y:
        pygame.draw.rect(game_display,active,(x,y,width,height))
        if mouse_click[0] == 1 and action != None:
           if action == "Play":
              main_loop()
           elif action == "EXIT":
              pygame.quit()
              quit()
           elif action == "Rules":
              displaying_instructions()
           elif action == "Scores":
              displaying_scores()              
           elif action == "Menu":
              main_menu()                      
    else:
        pygame.draw.rect(game_display,inactive,(x,y,width,height))

    small_text = pygame.font.SysFont("comicsansms", 25)
    text_surface, text_rect = text_objects(message, small_text)
    text_rect.center = ((x+(width/2)),(y+(height/2)))
    game_display.blit(text_surface, text_rect)
    
#Creating main menu   
def main_menu():

    game_exit = False
    while not game_exit:
        for event in pygame.event.get():  
            if event.type == pygame.QUIT: 
                pygame.quit()
                quit() 
       
        game_display.fill(WHITE)
        
        large_text = pygame.font.SysFont("comicsansms", 60)
        text_surface, text_rect = text_objects("Welcome To Flow", large_text)
        text_rect.center = ((260),(200))
        game_display.blit(text_surface, text_rect)
        #Dispalying the buttons by calling the button function
        button("Play", 40,450,100,50, LIGHT_BLUE, BLUE, "Play")
        button("Rules", 150,450,100,50, LIGHT_BLUE, BLUE, "Rules")
        button("Scores", 260,450,100,50, LIGHT_BLUE, BLUE, "Scores")
        button("EXIT", 370,450,100,50, LIGHT_BLUE, BLUE, "EXIT")
        
        pygame.display.update()

#Displaying instruction on the screen        
def displaying_instructions():
   
   printing_instructions = True
   while printing_instructions:
      
      game_display.fill(WHITE)
      text_file = open("Instructions.txt","r")
      text_font = pygame.font.SysFont("comicsansms", 20)
      y = 50
      #Reading instructions from a file and displaying them
      for i in range (10):      
         line = text_file.readline()
         line = line.replace("\n","")
         text,textrect = text_objects(line,text_font)
         game_display.blit(text,(20,y))
         y += 25
      
      text2,textrect2 = text_objects("To return to the Main Menu press: b",text_font)
      game_display.blit(text2,(100,400))
      for event in pygame.event.get():
              if event.type == pygame.KEYDOWN:
                  if event.key == pygame.K_b:
                     printing_instructions = False
                     main_menu()
      
      pygame.display.update()

#Displaying text at when level finished
def displaying_finishedLevel():
   level_finished = True
   text_font = pygame.font.SysFont("comicsansms", 20)
   while level_finished:
      pygame.draw.rect(game_display,WHITE,[100,100,350,100])
      text,textrect = text_objects("Level Complete",text_font)
      game_display.blit(text,(100,100))
      text2,textrect2 = text_objects("To return to the Main Menu press: b",text_font)
      game_display.blit(text2,(100,150))
      pygame.display.update()
      #A way to get back to the menu screen
      for event in pygame.event.get():
              if event.type == pygame.KEYDOWN:
                  if event.key == pygame.K_b:
                     level_finished = False
                     main_menu()

                     
#Displaying the user scores                     
def displaying_scores():
   score_list = []
   text_font = pygame.font.SysFont("comicsansms", 20)
   printing_list = True  
   while printing_list:
      game_display.fill(WHITE)
      score_list = reading_scores()
      score_list.sort()
      y = 50
      #Printing each score 
      for score in score_list:
         text,textrect = text_objects(str(score),text_font)
         game_display.blit(text,(100,y))
         y += 25
         
      text2,textrect2 = text_objects("High Scores number of mouse clicks less is better:",text_font)
      game_display.blit(text2,(20,20))
      text3,textrect3 = text_objects("To return to the Main Menu press: b",text_font)
      game_display.blit(text3,(100,400))
      pygame.display.update()
      #A way to get back to the menu screen
      for event in pygame.event.get():
              if event.type == pygame.KEYDOWN:
                  if event.key == pygame.K_b:
                     level_finished = False
                     main_menu()
   
                     
#Saving the score to a file
def saving_score():
   global score
   score_list = []
   #Checking if the file already exsits by using try if not its created
   try:
      f = open("Score List.dat","rb")
   except FileNotFoundError:
      f = open("Score List.dat","wb")
      f.close()
      f = open("Score List.dat","rb")
   try:
      score_list = pickle.load(f)
   except:
      print("")
   score_list.append(score)
   f.close()
   f = open("Score List.dat","wb")
   pickle.dump(score_list,f)
   f.close()      

#Reading the scores from the file
def reading_scores():
   score_list = []
   #Checking if the file already exsits by using try if not its created
   try:
      f = open("Score List.dat","rb")
   except FileNotFoundError:
      f = open("Score List.dat","wb")
      f.close()
   #Checking if the file has any score if not a message is given  
   try:
      f = open("Score List.dat","rb")
      score_list = pickle.load(f)
   except EOFError:
      print("Nothing in File")
   f.close()
   
   return score_list

         
#Running the main loop
def main_loop():
   global score
   game_exit = False
   circle_click = False
   first_line = False
   first_move = False
   #Variables for active circle
   green_selected = False
   yellow_selected = False
   blue_selected = False
   purple_selected = False
   red_selected = False
   
   nearest_pos1 = ""
   same_circle = ""
   selected_colour = ""
   active_circle_colour = ""
   selected_list = ""
   
   green_line = []
   yellow_line = []
   blue_line = []
   purple_line = []
   red_line = []
   
   counter = 0 
   counter_clicks = 0
   mouse_clicks = 0

   x1 = 0
   x2 = 0
   y1 = 0
   y2 = 0
   
   points_saved = []
   all_lines = []
   while not game_exit:
       for event in pygame.event.get():  
           if event.type == pygame.QUIT: 
               game_exit = True
               
           #Getting the position of the left mouse click
           elif event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:              
               mouse_clicks += 1
              
               pos1 = pygame.mouse.get_pos()           
               xmouse = pos1[0]
               ymouse = pos1[1]
               #Transferring the clicked pos into the nearest mid 
               nearest_pos1 = nearest_mid (xmouse,ymouse)
               
               #Checking if the click is a circle and getting the colour of it
               circle_click, colour_C, active_circle = check_ifCircle (nearest_pos1)

               #Selecting the list to add the line points to
               if circle_click and first_line == False:
                  counter_clicks = 0
                  first_move = False
                  selected_colour = "" 
                  if colour_C == GREEN:
                     print("here 3")
                     x1 = nearest_pos1[0]
                     y1 = nearest_pos1[1]
                     green_line.append(nearest_pos1)
                     same_circle = nearest_pos1
                     selected_list = green_line
                     selected_colour = colour_C
                     active_circle_colour = active_circle
                     green_selected = True
                     pygame.display.update()
                     first_line = True
                     
                  elif colour_C == YELLOW:
                     x1 = nearest_pos1[0]
                     y1 = nearest_pos1[1]                     
                     yellow_line.append(nearest_pos1)
                     same_circle = nearest_pos1
                     selected_list = yellow_line
                     selected_colour = colour_C
                     active_circle_colour = active_circle
                     yellow_selected = True
                     first_line = True                    
                     
                  elif colour_C == BLUE:
                     x1 = nearest_pos1[0]
                     y1 = nearest_pos1[1]                     
                     blue_line.append(nearest_pos1)
                     same_circle = nearest_pos1
                     selected_list = blue_line
                     selected_colour = colour_C
                     active_circle_colour = active_circle
                     blue_selected = True
                     first_line = True
                     
                  elif colour_C == PURPLE:
                     x1 = nearest_pos1[0]
                     y1 = nearest_pos1[1]                    
                     purple_line.append(nearest_pos1)
                     same_circle = nearest_pos1
                     selected_list = purple_line
                     selected_colour = colour_C
                     active_circle_colour = active_circle
                     purple_selected = True
                     first_line = True
                     
                  elif colour_C == RED:
                     x1 = nearest_pos1[0]
                     y1 = nearest_pos1[1]                     
                     red_line.append(nearest_pos1)
                     same_circle = nearest_pos1
                     selected_list = red_line
                     selected_colour = colour_C
                     active_circle_colour = active_circle
                     red_selected = True
                     first_line = True
                                      
               #Deleting the line if the same circle is clicked   
               elif same_circle == nearest_pos1:
                  selected_list[:] = []
                  first_line = False
                  green_selected = False
                  yellow_selected = False
                  blue_selected = False
                  purple_selected = False
                  red_selected = False
                  
               #Ending the line if the second circle with the same colour is clicked  
               elif first_line == True and colour_C == selected_colour:
                     if first_move:
                        print ("here")
                        tepm_x1 = x1
                        tepm_y1 = y1
                        tepm_x2 = x2 
                        tepm_y2 = y2 
                        x1 = x2
                        y1 = y2                     
                        x2 = nearest_pos1[0]
                        y2 = nearest_pos1[1]
                        valuex = y2-y1
                        valuey = x2-x1
                        
                        #Making sure diognal lines cannot be drawn                      
                        if valuex == 0:
                           selected_list.append(nearest_pos1)
                           first_line = False
                           first_move = False
                           counter += 1                          
                           green_selected = False
                           yellow_selected = False
                           blue_selected = False
                           purple_selected = False
                           red_selected = False                           
                        elif valuey == 0:
                           selected_list.append(nearest_pos1)
                           first_line = False
                           first_move = False
                           counter += 1
                           green_selected = False
                           yellow_selected = False
                           blue_selected = False
                           purple_selected = False
                           red_selected = False                         
                        else:
                           x1 = tepm_x1
                           y1 = tepm_y1
                           x2 = tepm_x2
                           y2 = tepm_y2

                  
               #Adding valid mid points to the selected line list  
               elif first_line == True:
                  if circle_click == False:
                     print("here2")
                     counter_clicks += 1
                     tepm_x1 = x1
                     tepm_y1 = y1
                     tepm_x2 = x2 
                     tepm_y2 = y2 
                     
                     if counter_clicks >= 2:
                        x1 = x2
                        y1 = y2                     
                     x2 = nearest_pos1[0]
                     y2 = nearest_pos1[1]
                     valuex = y2-y1
                     valuey = x2-x1
                     
                     #Making sure diognal lines cannot be drawn                      
                     if valuex == 0:
                        selected_list.append(nearest_pos1)
                        first_move = True
                     elif valuey == 0:
                        selected_list.append(nearest_pos1)
                        first_move = True
                     else:
                        x1 = tepm_x1
                        y1 = tepm_y1
                        x2 = tepm_x2
                        y2 = tepm_y2
                                                                        
       display_squares()
       first_circle, second_circle, circle_colours, selected_colours = level1()
       
       #Displaying players mouse clicks therefore there score
       text_font = pygame.font.SysFont("comicsansms", 30)
       text,textrect = text_objects(str(mouse_clicks),text_font)
       game_display.blit(text,(100,530))
       #Drawing the lines and active circles
       if selected_colour!= "":
         
          if len (green_line)>1:
             pygame.draw.lines(game_display, GREEN, False, green_line, 15)
          if green_selected:
             pygame.draw.circle(game_display, active_circle_colour, [same_circle[0],same_circle[1]], 40, 0)
             
          if len (yellow_line)>1:
             pygame.draw.lines(game_display, YELLOW, False, yellow_line, 15)
          if yellow_selected:
             pygame.draw.circle(game_display, active_circle_colour, [same_circle[0],same_circle[1]], 40, 0)
             
          if len (blue_line)>1:
             pygame.draw.lines(game_display, BLUE, False, blue_line, 15)
          if blue_selected:
             pygame.draw.circle(game_display, active_circle_colour, [same_circle[0],same_circle[1]], 40, 0)
             
          if len (purple_line)>1:
             pygame.draw.lines(game_display, PURPLE, False, purple_line, 15)
          if purple_selected:
             pygame.draw.circle(game_display, active_circle_colour, [same_circle[0],same_circle[1]], 40, 0)
             
          if len (red_line)>1:
             pygame.draw.lines(game_display, RED, False, red_line, 15)
          if red_selected:
             pygame.draw.circle(game_display, active_circle_colour, [same_circle[0],same_circle[1]], 40, 0)               
       #Checking if the has been finsihed        
       if counter == 5:
          score = mouse_clicks
          saving_score() 
          displaying_finishedLevel()
          
       pygame.display.update()
   pygame.quit()
   quit()   

#-----Main----------  
main_menu()
