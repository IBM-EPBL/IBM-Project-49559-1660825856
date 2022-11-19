import time
from ibm_watson import TextToSpeechV1
from ibm_cloud_sdk_core.authenticators import IAMAuthenticator
import ibmiotf.device
import pygame
pygame.init() # initiate pygame

config={
    "org":"ular9x",             # Device Organization
    "type" :"MedicineRem",              # Device Type
    "id":"dev01",                # Device ID
    "auth-method":"token",      # Device Authentication Method
    "auth-token":"ZTt_CrO0t4zB9sBkmX"    # Device Authentication Token
}
url="https://api.eu-gb.text-to-speech.watson.cloud.ibm.com/instances/21d5e31f-5b34-4265-8bb9-d9e34553064d"  # TextToSpeech URL Link
api="Jg0dO0bOuWJA9OMEyfpWBXR4r5allxW6S_yaUvy-VFfh"                                                          # TextToSpeech API Key
client= ibmiotf.device.Client (config) # Save the device Config in a Varible called client
client.connect()                       # Connect with the device

# Load TextToSpeech API Key and URL
auth=IAMAuthenticator(api)
tts=TextToSpeechV1(authenticator=auth)
tts.set_service_url(url)

# callback
def myCommandCallback (cmd):
    a=cmd.data
    c=1
    instruction="Please Take following Medicine. "
    if len(a["command"])==0:
        pass
    else:
        for i in a["command"]:
            instruction+=str(c)+". "
            instruction+=i
            instruction+=". "
            c+=1
        print("Instruction : ",instruction)
        with open("./speech.wav","wb") as audio_file:
            res=tts.synthesize(instruction,accept="audio/mp3",voice='en-US_AllisonExpressive').get_result()
            audio_file.write(res.content)
        play("speech.wav")

def play(a):
    p=pygame.mixer.Sound(a)
    pygame.mixer.Sound.play(p)
    time.sleep(20)
    pygame.mixer.Sound.play(p)
    time.sleep(20)
    pygame.mixer.Sound.play(p)
    time.sleep(20)

while True:
    client.commandCallback = myCommandCallback
client.disconnect()
