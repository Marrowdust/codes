'''You are locked into a maze with 10 possible rooms to check for your escape , 5 rooms has an item that can help you and five rooms have an enemy , if you get all five items successully you can go
to the final boss fight in which you will need two items to defeat once defeated you will able to escape you are the room succesfullly                  '''
import pygame
import os

pygame.mixer.init()
pygame.mixer.music.load("D:\Codes\codes-main\A Moment's Peace [ja7dXwjIEKM].mp3")
pygame.mixer.music.play(loops=-1, start=0.0)

def room(num,metrics):
 print_metrics(metrics)
 if (num==1):
  metrics['hp']+=30
  print_status(metrics)
  print("This is Room number one\n")
  print("You found A Medkit")
  input("press any key to continue")
  os.system('cls')
 elif(num==2):
  print("this is room number two\n")
  print("you found a weak enemy\n")
  if(metrics['Sword']>=1):
   print("You killed the enemy and your sword is broken\n")
   metrics['Sword']-=1
   print_status(metrics)
   
  else:
   print("enemy hit you and you escaped like a coward\n")
   metrics['hp']-=30
   print_status(metrics)
   if(metrics['hp']<=0):
       metrics['hp']=0
       print("in a humiliating turn of events as you try to escape the weakling enemy you slowly bleed out until your hp has been depleted a shame on top of the wound , you have been killed by the weak enemy\n")
       print("You are Dead\n")
       print_status(metrics)
  os.system('cls')     
 elif(num==3):
  
  print("This is room number three\n")
  print("You found a sword\n")
  metrics['Sword']+=1
 elif(num==4):
     
  print("This is room number 4\n")
  print("you found a spell but you can't use it now\n")
  metrics['Spell']+=1
 elif(num==5):
     
  print("This is room number 5")
  print("You found a void portal\n")
  print("do you want to enter the void?[y/n]\n")
  choice=input()
  if(choice=='y'):
   print("you are entering a void portal , your memories are now forgotten\n")
   metrics['spell']=0
   metrics['weapon']=0
   metrics['hp']=1
   print("You lost all your items\n")
   print("A voice from across the void whipsers to you and call for you\n")
   print("do you wanna hear the void?[y/n]\n")
   choice1=input()
   if(choice1=='y'):
    print("As you listen to the whispers of the void you see a shiny beam light and a breeze of warmth hit your heart , you have earned a blessing\n")
    print("Blessing added to your inventory\n")
    print("with this blessing you can now one shot the final boss but you if you meet an enemy before it you will lose it\n")
    metrics['blessing']=1
   elif(choice=='n'):
    print("you feel a slight pain in your chest you can't understand what exactly you are feeling , you fall into an abyss and eventually you got ground of shame and misery , you have earned a Curse\n")
    print("Curse added to your inventory, you will now be unable to defend yourself anymore or defeat the final boss but this can be reverted if you defeat one enemy\n")
  elif(choice=='n'):
   print("You walk out of the ominous room with nothing gained or lost\n")
 elif(num==6):
     
  print("This is room number 6")
  print("you found a Book of artistry\n")
  print("you can use this book to make your spell twice as stronger\n")
  if(metrics['spell']>=0):
   metrics['Strongspell']=1
 elif(num==7):
     
     print("This is room number seven\n")
     print("You found a Demon\n")
     print("You can run and lose your items and keep your hp or fight and keep your hp and items and risk dying\n")
     print("do you wanna continue or Leave?[c/l]\n")
     choice=input()
     if(choice=='c'):
         if (metrics['Sword']>=0 or metrics['Spell']>=0):
             print("Enemy takes heavy damage\n")
             if(metrics['Sword']>=1 or metrics['Spell']>=1):
              metrics['Sword']-=1
              metrics['spell']-=1
              print("you Have honorablly defeated the Demon an unprecented feat of strength and power , you truly deserve to call yourself a warrior\n")
         elif(metrics['Spell']>1):
                 metrics['Spell']-=2
                 print("you Have honorablly defeated the Demon an unprecented feat of strength and power , you truly deserve to call yourself a warrior\n")
         elif(metrics['Sword']>1):
                 metrics['Sword']-=2
                 print("you Have honorablly defeated the Demon an unprecented feat of strength and power , you truly deserve to call yourself a warrior\n")
         else:
                 print("You check your inventory for items to fight and protect yourself but as the Demon approaches you find yourself slowly falling back into the door but reality Strike you like lighting bolt you are all alone with this demon with no where to go\n")
                 print("With no way to defend yourself the monster crushes you slowly bone by bone and inch by inch until you are completely demolished\n")
                 metrics['hp']=0
                 print("You Are dead\n")
     elif(choice=='l'):
         print("Like a traditional coward you leave the room with shame and fear from the ominous entity you witnessed and decided to accept all your progress just for a brink of hope\n")
         
         for key in metrics.keys():
            metrics[key]=0
         print("Just like you asked for all your items have been reset and your hopes for survival are reduced but this time with a bearing of shame\n")
     input("press any key to continue")    
 elif(num==8):
     
     print("This is room number eight\n")
     print("You Found a sword\n")
     metrics['Sword']+=1
 elif(num==9):
     
     print('This is room number nine\n') 
     print("you found a Spell\n")
     metrics['Spell']+=1
 elif(num==10):
     
     print("This is room number ten\n")
     print("this the forbidden room\n")
     print("you find a dark door with a painful yet intruiging aura\n")
     print("you at irreversible ultimatum\n")
     print("do you want to enter this door?[y/n]")
     choice=input()
     if(choice=='y'):
         print("you hear a deep voice from across the room\n")
         print("you really dare approach me?")
         pygame.mixer.init()
         pygame.mixer.music.load("D:\Codes\codes-main\DARK SOULS Ⅲ [-armx8FIpYU].mp3")
         pygame.mixer.music.play(loops=-1, start=0.0)
 os.system('cls')
 return metrics        

def print_metrics(metrics):
    print("HP: "+str(metrics['hp'])+" blessing: "+str(metrics['blessing'])+" Curse: "+str(metrics['Curse'])+" Sword: "+str(metrics['Sword'])+" Spell: "+str(metrics['Spell'])+" Strongspell: "+str(metrics['Strongspell']))

metrics={"hp":100,"blessing":0,"Curse":0,"Sword":0,"Spell":0,"Strongspell":0}

# Create a list of numbers from 1 to 10

numbers = list(range(1, 11))
# Function to print the status bar at the top
def print_status(metricss):
    # Move the cursor to the top of the terminal
    print("\033[H", end="")
    # Print each metric in the dictionary
    status = " ".join(f"{key}: {value}" for key, value in metricss.items())
    print(status)
# While there are still numbers left to choose from
while numbers:
    os.system('cls')
    print("Choose a number")
    chosen_number = int(input())
    room((chosen_number+2)%10,metrics)
    os.system('cls')
    # Remove the chosen number from the list so it won't be chosen again
    numbers.remove(chosen_number)
    print("hope that's enough")





       
