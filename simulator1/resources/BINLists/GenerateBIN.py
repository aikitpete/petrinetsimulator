import random
import os
import sys 

folder = './'
for the_file in os.listdir(folder):
	if the_file.endswith(".dat"):
		file_path = os.path.join(folder, the_file)
		try:
			if os.path.isfile(file_path):
				os.unlink(file_path)
		except Exception:
			print("Cannot delete file.")
		
for i in range(0, int(sys.argv[1])):
	
	#Open file
	filepath = "BINlist" + str(i) + ".dat"
	try:
		print(filepath)
		f = open(filepath, 'w')
	except IOError:
		print("Cannot open file for writing.")
		sys.exit(0)
		
	# Generate random data
	numberlist = []
	for j in range(0, int(sys.argv[2])):
		number = ''
		for k in range(0,6):
			number = number + str(random.randint(0,9))
		numberlist.append(number + "\n")
	
	# Write all the lines at once
	f.writelines(numberlist)
	
	f.close()
