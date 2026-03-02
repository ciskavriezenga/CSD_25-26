from pythonosc.udp_client import SimpleUDPClient

client = SimpleUDPClient("127.0.0.1", 7777)

ADDRESS = "/parameter"

print("This is a test program to show you how you can send values over OSC")
print("The port is 7777, sending messages to /parameter")
print("This script has no input error handling, so use with proper caution")

while True:
    value = float(input("Try a number: "))
    client.send_message(ADDRESS, value)
    print("Sent " + str(value) + " to " + ADDRESS)
