filename = "map.txt"
characters = {}

f = open(filename, "r")

lines = f.readlines()

for line in lines:
	line = line.strip("\n")
	for character in line:
		if character in characters:
			characters['{}'.format(character)] = characters['{}'.format(character)] + 1
		else:
			characters['{}'.format(character)] = 1
f.close()

#print(characters)

tiles_total = 0
boxes_total = 0
chests_total = 0
coins_total = 0
flags_total = 0
keys_total = 0
non_interact_total = 0
ladder_total = 0
enemies_total = 0

for char in characters:
	if ord(char) < 58 and ord(char) > 48:
		tiles_total += characters['{}'.format(char)]
	elif ord(char) == 65:
		chests_total += characters['{}'.format(char)]
	elif ord(char) == 66:
		coins_total += characters['{}'.format(char)]
	elif ord(char) == 67:
		flags_total += characters['{}'.format(char)]
	elif ord(char) == 68:
		keys_total += characters['{}'.format(char)]
	elif ord(char) < 72 and ord(char) > 68:
		boxes_total += characters['{}'.format(char)]
	elif (ord(char) > 71 and ord(char) < 79) or (ord(char) > 82 and ord(char) < 91) or (ord(char) == 81):
		non_interact_total += characters['{}'.format(char)]
	elif ord(char) == 79 or ord(char) == 80:
		ladder_total += characters['{}'.format(char)]
	elif ord(char) == 82:
		enemies_total += characters['{}'.format(char)]


print(f"Tiles: {tiles_total}")
print(f"Chests: {chests_total}")
print(f"Coins: {coins_total}")
print(f"Flags: {flags_total}")
print(f"Keys: {keys_total}")
print(f"Boxes: {boxes_total}")
print(f"Non-Interactables: {non_interact_total}")
print(f"Ladders: {ladder_total}")
print(f"Enemies: {enemies_total}")
