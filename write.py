filename = "map.txt"

f = open(filename, "w")

for i in range(19):
	for j in range(32):
		f.write("0")
	f.write("\n")

for i in range(32):
	f.write("1")

f.close()
