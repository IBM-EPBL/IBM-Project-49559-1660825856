import random
while(True):
  temperature=random.randint(10,120)
  humidity=random.randint(10,120)
  print("current temperature :",temperature)
  print("current humidity:",humidity,"%")
  temp_val=32
  humid_val=30
  if temperature>temp_val and humidity<humid_val:
     print("Temperature is high Sound the alarm")
  else:
     print("Sound off")
  break